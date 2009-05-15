#!/usr/bin/perl

# Script to represent test coverage in a user-friendly way
#
# Copyright (c) 2005-2009 Institute for System Programming
#
# 07/05/2009 Roman Zybin, ISP RAS

BEGIN{	
    chomp(my $program_dir = `dirname $0`);
    unshift @INC, $program_dir."/../share/perl";
}

use strict;
use XML::Parser;
use XML::Simple;

my $res_xml = shift;
my $out = shift;

die "Can't find file containing test results \"$res_xml\"" unless -f $res_xml;
if($out eq ""){$out = "-";}

my $coverage;

my $parser = XML::Parser->new(
        Handlers => {
        Start => \&handle_elem_start
    }
);

sub handle_elem_start {
    my( $expat, $name, %atts ) = @_;
    my $req = $atts{'name'};
    if($name eq "CoveredStandaloneMark"){
        if($req =~ s/\?//){
            $coverage->{$req}{'covered'} = 0;
        }
        else{
            $coverage->{$req}{'covered'} = 1;
        }
    }
    elsif($name eq "Property"){
        if($req =~ s/req_id.//){
            $coverage->{$req}{'failed'} = 1;
        }
    }
}

$parser->parsefile("$res_xml");

our $group;
our $func;
our $n_id = 0;
my $ids_xml = XMLin("./ids.xml", ForceArray => ["group", "func", "req", "gsub"]);

sub chooseColors{
    my $hashref = shift;
    
    foreach my $req (keys %{$hashref}){
        if(defined($hashref->{$req}{"req"})){
            chooseColors($hashref->{$req}{"req"});
            my $children_red = 0;
            my $children_yellow = 0;
            my $children_green = 0;
            foreach my $children (keys %{$hashref->{$req}{"req"}}){
                if($hashref->{$req}{"req"}{$children}{'color'} eq "#008800"){ #green
                    $children_green++;
                }
                if($hashref->{$req}{"req"}{$children}{'color'} eq "#888800"){ #yellow
                    $children_yellow++;
                }
                if($hashref->{$req}{"req"}{$children}{'color'} eq "#FF0000"){ #red
                    $children_red++;
                }
            }
            if(!defined($hashref->{$req}{"struct"}) && !($req =~ m/app./)){
                if(($children_red == 0) && ($children_yellow == 0) && ($children_green > 0)){
                    $hashref->{$req}{'color'} = "#008800"; #green
                }
                if(($children_red == 0) && ($children_yellow > 0)){
                    $hashref->{$req}{'color'} = "#888800"; #yellow
                }
                if($children_red > 0){
                    $hashref->{$req}{'color'} = "#FF0000"; #red
                }
            }
            else{
                $hashref->{$req}{'color'} = "#888888"; #gray
            }
        }
        elsif(defined($hashref->{$req}{"isgen"}) && scalar($hashref->{$req}{"gsub"}) > 0){
            my $gsub_red = 0;
            my $gsub_yellow = 0;
            my $gsub_green = 0;
            foreach my $gsub (keys %{$hashref->{$req}{"gsub"}}){
                if(!defined($hashref->{$req}{"gsub"}{$gsub}{"struct"}) && !($gsub =~ m/app./)){
                    if(defined($coverage->{$gsub}{'covered'})){
                        if($coverage->{$gsub}{'covered'} == 1){
                            $hashref->{$req}{"gsub"}{$gsub}{'color'} = "#008800"; #green
                            $gsub_green++;
                        }
                        else{
                            $hashref->{$req}{"gsub"}{$gsub}{'color'} = "#888800"; #yellow
                            $gsub_yellow++;
                        }
                    }
                    if(defined($coverage->{$gsub}{'failed'})){
                        $hashref->{$req}{"gsub"}{$gsub}{'color'} = "#FF0000"; #red
                        $gsub_red++;
                    }
                }
                else{
                    $hashref->{$req}{"gsub"}{$gsub}{'color'} = "#888888"; #gray
                }
            }
            
            if(($gsub_red == 0) && ($gsub_yellow == 0) && ($gsub_green > 0)){
                $hashref->{$req}{'color'} = "#008800"; #green
            }
            if(($gsub_red == 0) && ($gsub_yellow > 0)){
                $hashref->{$req}{'color'} = "#888800"; #yellow
            }
            if($gsub_red > 0){
                $hashref->{$req}{'color'} = "#FF0000"; #brown
            }
        }
        else{
            if(!defined($hashref->{$req}{"dummy"}) && !defined($hashref->{$req}{"struct"}) && !($req =~ m/app./)){
                if(defined($coverage->{$req}{'covered'})){
                    if($coverage->{$req}{'covered'} == 1){
                        $hashref->{$req}{'color'} = "#008800"; #green
                    }
                    else{
                        $hashref->{$req}{'color'} = "#888800"; #yellow
                    }
                }
                if(defined($coverage->{$req}{'failed'})){
                    $hashref->{$req}{'color'} = "#FF0000"; #red
                }
            }
            else{
                $hashref->{$req}{'color'} = "#888888"; #gray
            }
        }
    }
}

sub searchBaseReq($$$){
    my $hashref = shift;
    my $basereq = shift;
    my $descr = shift;

    foreach my $req (keys %{$hashref}){
        if(defined($hashref->{$req}{"req"})){
            searchBaseReq($hashref->{$req}{"req"}, $basereq, $descr);
        }
        else{
            if($req eq $basereq){
                $hashref->{$basereq}{"descr"} = $hashref->{$basereq}{"descr"}."<br>".$descr;
            }
        }
    }
}

sub processFuncReqs{
    my $hashref = shift;
    
    foreach my $req (keys %{$hashref}){
        if(defined($hashref->{$req}{"req"})){
            processFuncReqs($hashref->{$req}{"req"});
        }
        else{
            if(!defined($hashref->{$req}{"dummy"}) && !defined($hashref->{$req}{"struct"}) && !($req =~ m/app./) && !($req =~ m/&/)){
                $ids_xml->{"group"}{$group}{"func"}{$func}{"total"}++;
                $ids_xml->{"group"}{$group}{"total"}++;
                $ids_xml->{"total"}++;
                if(defined($coverage->{$req}{'covered'})){
                    $ids_xml->{"group"}{$group}{"func"}{$func}{"covered"}++;
                    $ids_xml->{"group"}{$group}{"covered"}++;
                    $ids_xml->{"covered"}++;
                }
                if(defined($coverage->{$req}{'failed'})){
                    $ids_xml->{"group"}{$group}{"func"}{$func}{"failed"}++;
                    $ids_xml->{"group"}{$group}{"failed"}++;
                    $ids_xml->{"failed"}++;
                }
            }
            if($req =~ m/&/){
                my $basereq = $req;
                $basereq =~ s/&//g;
                searchBaseReq($ids_xml->{"group"}{$group}{"func"}{$func}{"req"}, $basereq, $hashref->{$req}{"descr"});
            }
        }
        $coverage->{$req}{'processed'} = 1;
    }
}

sub processIdsXML
{
    $ids_xml->{"total"} = 0;
    $ids_xml->{"covered"} = 0;
    $ids_xml->{"failed"} = 0;
    foreach $group (keys %{$ids_xml->{"group"}}){
        $ids_xml->{"group"}{$group}{"total"} = 0;
        $ids_xml->{"group"}{$group}{"covered"} = 0;
        $ids_xml->{"group"}{$group}{"failed"} = 0;
        foreach $func (keys %{$ids_xml->{"group"}{$group}{"func"}}){
            $ids_xml->{"group"}{$group}{"func"}{$func}{"total"} = 0;
            $ids_xml->{"group"}{$group}{"func"}{$func}{"covered"} = 0;
            $ids_xml->{"group"}{$group}{"func"}{$func}{"failed"} = 0;
            processFuncReqs($ids_xml->{"group"}{$group}{"func"}{$func}{"req"});
            if($ids_xml->{"group"}{$group}{"func"}{$func}{"covered"} == 0){
                $ids_xml->{"group"}{$group}{"func"}{$func}{"color"} = "#CC0000"; #red
            }
            if($ids_xml->{"group"}{$group}{"func"}{$func}{"covered"} == $ids_xml->{"group"}{$group}{"func"}{$func}{"total"}){
                $ids_xml->{"group"}{$group}{"func"}{$func}{"color"} = "#009900"; #green
            }
            chooseColors($ids_xml->{"group"}{$group}{"func"}{$func}{"req"});
        }
        if($ids_xml->{"group"}{$group}{"covered"} == 0){
            $ids_xml->{"group"}{$group}{"color"} = "#CC0000"; #red
        }
        if($ids_xml->{"group"}{$group}{"covered"} == $ids_xml->{"group"}{$group}{"total"}){
            $ids_xml->{"group"}{$group}{"color"} = "#009900"; #green
        }
    }
}

sub mysort {
    my $ma = $a;
    my $mb = $b;
    $ma =~ s/app.//;
    $mb =~ s/app.//;
    $ma cmp $mb;
}

sub printFuncCoverage{
    my $hashref = shift;
    
    foreach my $req (sort mysort keys %{$hashref}){
        if(! defined($hashref->{$req}{"dummy"}) && !($req =~ m/&/)){
print HTM "<li>";
            if(defined($hashref->{$req}{'color'})){
print HTM "<font color=\"$hashref->{$req}{'color'}\">";
            }
print HTM "$req";
            if(defined($hashref->{$req}{"struct"})){
print HTM " (struct)";
            }
            if(defined($coverage->{$req}{'failed'})){
print HTM " (failed)";
            }
            if(defined($hashref->{$req}{'color'})){
print HTM "</font>";
            }
print HTM "<br><font color=\"#000088\">$hashref->{$req}{'descr'}</font>";
            if(defined($hashref->{$req}{"isgen"}) && scalar($hashref->{$req}{"gsub"}) > 0){
print HTM "<br>Generalizes:<ul>\n";
                foreach my $gsub (sort keys %{$hashref->{$req}{"gsub"}}){
print HTM "<li>";
                    if(defined($hashref->{$req}{'gsub'}{$gsub}{'color'})){
print HTM "<font color=\"$hashref->{$req}{'gsub'}{$gsub}{'color'}\">";
                    }
print HTM "$gsub";
                    if(defined($hashref->{$req}{'gsub'}{$gsub}{'color'})){
print HTM "</font>";
                    }
print HTM "</li>\n";
                }
print HTM "</ul>";
            }
print HTM "</li>\n";
        }
        if(defined($hashref->{$req}{"req"})){
            printFuncCoverage($hashref->{$req}{"req"});
        }
    }
}

sub printCoverage
{
    foreach $group (sort keys %{$ids_xml->{"group"}}) {
        my $gr_total = $ids_xml->{"group"}{$group}{"total"};
        my $gr_covered = $ids_xml->{"group"}{$group}{"covered"};
        my $gr_failed = $ids_xml->{"group"}{$group}{"failed"};
print HTM "<li>[<a onclick=\"return show('id".++$n_id."',this)\" href=\"#\">+</a>]";
        if(defined($ids_xml->{"group"}{$group}{"color"})){
            my $g_color = $ids_xml->{"group"}{$group}{"color"};
print HTM "<font color=\"$g_color\"><b>$group</b></font>";
        }
        else{
print HTM "<b>$group</b>";
        }
print HTM " ($gr_total / $gr_covered / $gr_failed)<ul id=\"id$n_id\" style=\"display:none\">\n";
        foreach $func (sort keys %{$ids_xml->{"group"}{$group}{"func"}}){
            my $f_total = $ids_xml->{"group"}{$group}{"func"}{$func}{"total"};
            my $f_covered = $ids_xml->{"group"}{$group}{"func"}{$func}{"covered"};
            my $f_failed = $ids_xml->{"group"}{$group}{"func"}{$func}{"failed"};
print HTM "<li>[<a onclick=\"return show('id".++$n_id."',this)\" href=\"#\">+</a>]";
            if(defined($ids_xml->{"group"}{$group}{"func"}{$func}{"color"})){
                my $f_color = $ids_xml->{"group"}{$group}{"func"}{$func}{"color"};
print HTM "<font color=\"$f_color\"><b>$func</b></font>";
            }
            else{
print HTM "<b>$func</b>";
            }
print HTM " ($f_total / $f_covered / $f_failed)<ul id=\"id$n_id\" style=\"display:none\">\n";
            printFuncCoverage($ids_xml->{"group"}{$group}{"func"}{$func}{"req"});
print HTM "</ul></li>\n";
        }
print HTM "</ul></li>\n";
    }
}

processIdsXML();

my $misprints = "";
foreach my $req (sort keys %{$coverage}){
    if(!defined($coverage->{$req}{'processed'})){
        $misprints = $misprints."<li>".$req."</li>\n";
    }
}

open(HTM, "> $out");
print HTM<<TEXT;
<html>
<script>
    function show(id,al)
    {
        el=document.getElementById(id);
        if(el.style.display!='none')
        {
            el.style.display='none';
            al.innerHTML = "+";
        }else{
            el.style.display='';
            al.innerHTML = "&#150;";
        }
        return false;
    }
</script>
<style>
    a {text-decoration:none}
</style>
<body>
TEXT
if($misprints ne ""){
print HTM<<TEXT;
<h4>[<a onclick="return show('mispr',this)" href="#">+</a>]Misprints</h4><ul id="mispr" style="display:none">
<font color="red">
$misprints
</font>
</ul>
TEXT
}
print HTM<<TEXT;
<h4>Summary:( Total:$ids_xml->{"total"} / Covered:$ids_xml->{"covered"} / Failed:$ids_xml->{"failed"})</h4>
<ul>
TEXT
printCoverage();
print HTM<<TEXT;
</ul>
</body>
TEXT
close(HTM);
