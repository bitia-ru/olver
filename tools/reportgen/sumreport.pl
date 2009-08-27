#!/usr/bin/perl -w

# Script to generate summary report for OLVER test run
#
# Copyright (c) 2005-2009 Institute for System Programming
#
# 08/11/2009 Roman Zybin, ISP RAS

BEGIN{
    chomp(my $program_dir = `dirname $0`);
    unshift @INC, $program_dir."/../share/perl";
}

use strict;
use XML::SAX;
use Getopt::Long;

package SumHandler;
use base qw(XML::SAX::Base);

### Data ###

my %month = (
    'Jan' => '01',
    'Feb' => '02',
    'Mar' => '03',
    'Apr' => '04',
    'May' => '05',
    'Jun' => '06',
    'Jul' => '07',
    'Aug' => '08',
    'Sep' => '09',
    'Oct' => '10',
    'Nov' => '11',
    'Dec' => '12'
    );
my $cur_scen = '';
my $cur_fail = '';
my $cur_bug = '';
my @cur_grouping;
my $cdata;
my $chars;

### Handlers ###

sub start_element {
    my ($self, $el) = @_;
    my $name = $el->{'Name'};

    my %atts;
    if(defined $el->{'Attributes'}){
        while (my ( $key, $value ) = each %{$el->{'Attributes'}}){
            if(ref $value){
                $atts{$value->{'Name'}} = $value->{'Value'};
            }
            else{
                $atts{$key} = $value;
            }
        }
    }
    
    if($name eq 'ScenarioDesc'){
        $self->{'scenario'}{$atts{'identifier'}} = 0;
    }
    elsif($name eq 'ScenarioEnvironment'){
        if($atts{'startTime'} =~ /\w+\s(\w+)\s(\d+)\s([\d:]+)\s*\w*\s(\d+)/){
            my $start_time = "$4_$month{$1}_$2 $3";
               if(! defined $self->{'date'} or $start_time lt $self->{'date'}){
                   $self->{'env'}{'start_time'} = $start_time;
               }
           }
    }
    elsif($name eq 'EnvironmentProperty'){
        if($atts{'name'} eq 'Host'){
            $self->{'env'}{'host'} = $atts{'value'};
           }
           elsif($atts{'name'} eq 'Operating System'){
            $self->{'env'}{'os'} = $atts{'value'};
           }
    }
    elsif($name eq 'FailureDesc'){
        $cur_fail = $atts{'identifier'};
                
        if(defined $atts{'scenarioDesc'}){
            $self->{'failure'}{$cur_fail}{'scenario'} = $atts{'scenarioDesc'};
            $self->{'scenario'}{$atts{'scenarioDesc'}} = 1;
        }
        elsif($atts{'traceName'} =~ /(\w+)\.ut/){
            $self->{'failure'}{$cur_fail}{'scenario'} = $1;
            $self->{'scenario'}{$1} = 1;
        }
        
        $self->{'failure'}{$cur_fail}{'property'}{'info'} = $atts{'info'};
    }
    elsif($name eq 'Property'){
           $self->{'failure'}{$cur_fail}{'property'}{$atts{'name'}} = $atts{'value'};
    }
    elsif($name eq 'bug'){
        $cur_bug = $atts{'id'};
           $self->{'failure'}{$cur_fail}{'bug'} = $cur_bug;
    }
    elsif($name eq 'body'){
           $chars = '';
    }
    elsif($name eq 'FailureGroup'){
        push (@cur_grouping, $atts{'name'});
    }
    elsif($name eq 'FailureId'){
        if(@cur_grouping){
            push (@{$self->{'grouping'}{join(';', @cur_grouping)}}, $atts{'identifier'});
        }
    }
}

sub end_element {
    my ($self, $el) = @_;
    my $name = $el->{'Name'};

    my %atts;
    if(defined $el->{'Attributes'}){
        while (my ( $key, $value ) = each %{$el->{'Attributes'}}){
            if(ref $value){
                $atts{$value->{'Name'}} = $value->{'Value'};
            }
            else{
                $atts{$key} = $value;
            }
        }
    }

    if($name eq 'FailureDesc'){
        if(! defined $self->{'failure'}{$cur_fail}{'property'}{'info'} && $cdata ne ''){
            $self->{'failure'}{$cur_fail}{'property'}{'info'} = $cdata;
        }
        $cdata = '';
        $cur_fail = '';
    }
    elsif($name eq 'bug'){
        $cur_bug = '';
    }
    elsif($name eq 'body'){
        $chars =~ s/\n^[\s\t]+(.*)/$1 /gm;
        $chars =~ s/\s+$//;
        
        $chars =~ s/&/&amp;/go;
        $chars =~ s/</&lt;/go;
        $chars =~ s/\"/&quot;/go;
        
        $chars =~ s/(http\:\/\/www\.nabble\.com.+\.html)/<a href="$1">$1<\/a>/g;
        $chars =~ s/(http\:\/\/bugs\..+show_bug\.cgi\?id\=\d+)/<a href="$1">$1\<\/a>/g;
        $chars =~ s/(http\:\/\/sources\..+show_bug\.cgi\?id\=\d+)/<a href="$1">$1\<\/a>/g;
        $chars =~ s/(http\:\/\/linuxtesting\.\w+\/results\/report\?num\=S\w+)/<a href="$1">$1\<\/a>/g;
        $self->{'bug'}{$cur_bug} = $chars;
    }
    elsif($name eq 'FailureGroup'){
        pop (@cur_grouping);
    }
}

sub start_cdata {
    $chars = '';
    $cdata = '';
}

sub end_cdata {
    $cdata = $chars;
}

sub characters {
    my ($self, $el) = @_;
    $chars = $chars.$el->{'Data'};
}

package main;

my $out_file = '-';
my $coverage_file = '';
my $agent_log_file = '';
my $run_log_file = '';
my $lsb_funcs_file = '';

GetOptions(
    "out|o=s" => \$out_file,
    "coverage|c=s" => \$coverage_file,
    "agentlog|a=s" => \$agent_log_file,
    "runlog|r=s" => \$run_log_file,
    "lsbfunclist|l=s" => \$lsb_funcs_file
    );


my $res_file = shift;
die "Can't find file containing test results '$res_file'" unless -f $res_file;

my $handler = SumHandler->new();
my $parser = XML::SAX::ParserFactory->parser(Handler => $handler);
$parser->parse({Source => {SystemId => $res_file}});

my $env = delete ($handler->{'env'});
my $scenario = delete ($handler->{'scenario'});
my $failure = delete ($handler->{'failure'});
my $bug = delete ($handler->{'bug'});

#
# Group failures into classes
#
my $grouping;
my %fail_status;
foreach (keys %{$handler->{'grouping'}}){
    if($_ =~ /known bugs/){
        foreach my $fid (@{$handler->{'grouping'}{$_}}){
            my $id = $failure->{$fid}{'bug'};
            my $scen = $failure->{$fid}{'scenario'};
            push (@{$grouping->{'Known'}{$scen}{$id}{'failures'}}, $fid);
            $grouping->{'Known'}{$scen}{$id}{'descr'} = $bug->{$id};
            $fail_status{'known'}{$scen.$id} = 1;
        }
    }
    elsif($_ =~ /req failures/){
        foreach my $fid (@{$handler->{'grouping'}{$_}}){
            my $id = join ('; ', sort map { s/req_id.//; $_ } grep { /req_id/ } keys %{$failure->{$fid}{'property'}} );
            my $scen = $failure->{$fid}{'scenario'};
            push (@{$grouping->{'New'}{$scen}{$id}{'failures'}}, $fid);
            $grouping->{'New'}{$scen}{$id}{'descr'} = $failure->{$fid}{'property'}{'info'};
            $fail_status{'new'}{$scen.$id} = 1;
        }
    }
    else{
        # Obtain failure kind
        /([^;]+)$/;
        my $id = $1;
        if (/;[^;]+;([^;]+);/) {
            $id = $1.': '.$id;
        }
        
        foreach my $fid (@{$handler->{'grouping'}{$_}}){
            my $scen = $failure->{$fid}{'scenario'};
            push (@{$grouping->{'Internal'}{$scen}{$id}{'failures'}}, $fid);
            
            if(defined $failure->{$fid}{'property'}{'info'}){
                $grouping->{'Internal'}{$scen}{$id}{'descr'} = $failure->{$fid}{'property'}{'info'};
            }
            elsif(defined $failure->{$fid}{'property'}{'kind'}){
                $grouping->{'Internal'}{$scen}{$id}{'descr'} = $failure->{$fid}{'property'}{'kind'};
            }
            else{
                $grouping->{'Internal'}{$scen}{$id}{'descr'} = '';
            }
            $fail_status{'internal'}{$scen.$id} = 1;
        }
    }
}

#
# Determine tesing host name and os tested
#
chomp(my $cur_host = `uname -n`);
chomp(my $cur_os = `lsb_release -ds`);
if($cur_host eq $env->{'host'}){
    $env->{'os'} = $cur_os;
}
$env->{'os'} = 'unknown' unless $env->{'os'};
$env->{'host'} = 'unknown' unless $env->{'host'};
$env->{'start_time'} = 'unknown' unless $env->{'start_time'};

#
# Try to extract coverage-related information
# Read result.htm, parse line like <h4>Summary: ( Total: 333 etc.
#
my %req_coverage;
if ( -f $coverage_file ){
    open(COVERAGE, $coverage_file);
    while (<COVERAGE>){
        if( $_ =~ /Summary\:\(\s*Total\:(\d+)\s*\/\s*Covered\:(\d+)\s*\/\s*Failed\:(\d+)\s*\)/ ){
            $req_coverage{'total'} = "$1";
            $req_coverage{'covered'} = "$2";
            $req_coverage{'failed'} = "$3";
            last;
        }
    }
    close(COVERAGE);
}

#
# Determine abscent trace files
#
if ( -f $run_log_file ){
    open(RLOG, $run_log_file);
    while (<RLOG>){
        if( $_ =~ /Running scenario (\w+)/ ){
            if(! defined $scenario->{$1}){
                $scenario->{$1} = -1;
            }
        }
    }
    close(RLOG);
}

#
# Try to obtain status of functions
# hash value <= 0 tested
# hash value >= 0 in lsb
#
my %funcs;
if( -f $agent_log_file ){
    if($agent_log_file =~ /\.gz/){
        open(AGLOG, "gunzip -c $agent_log_file |");
    }
    else{
        open(AGLOG, "$agent_log_file");
    }
    
    while(<AGLOG>){
        if($_ =~ /search for (\w+)/){
            $funcs{$1}-- unless defined $funcs{$1};
        }
    }
    close(AGLOG);
}

if( -f $lsb_funcs_file ){
    open(LSBFUNCS, $lsb_funcs_file);
    while(<LSBFUNCS>){
        chomp(my $func = $_);
        $funcs{$func}++;
    }
    close(LSBFUNCS);
}

#
# Prepare data
#
if (! %req_coverage){
    %req_coverage = (
        'total' => '?',
        'passed' => '?',
        'failed' => '?',
        'checked' => '?'
        );
}
else{
    $req_coverage{'passed'} = $req_coverage{'covered'} - $req_coverage{'failed'};
    $req_coverage{'checked'} = $req_coverage{'covered'};
}

$fail_status{'known'} = keys %{$fail_status{'known'}};
$fail_status{'new'} = keys %{$fail_status{'new'}};
$fail_status{'internal'} = keys %{$fail_status{'internal'}};
$fail_status{'total'} = $fail_status{'new'} + $fail_status{'known'} + $fail_status{'internal'};

$fail_status{'known'} = "<a href='#Known'>".$fail_status{'known'}."</a>" if $fail_status{'known'};
$fail_status{'new'} = "<a href='#New'>".$fail_status{'new'}."</a>" if $fail_status{'new'};
$fail_status{'internal'} = "<a href='#Internal'>".$fail_status{'internal'}."</a>" if $fail_status{'internal'};

my %func_coverage = (
        'tested' => 0,
        'non_lsb' => 0,
        'not_tested' => 0
    );
    
if(%funcs){
    foreach (values %funcs){
        if($_ == 0){
            $func_coverage{'tested'}++;
        }
        elsif($_ < 0){
            $func_coverage{'non_lsb'}++;
        }
        else{
            $func_coverage{'not_tested'}++;
        }
    }
    $func_coverage{'total'} = $func_coverage{'tested'} + $func_coverage{'not_tested'};
}
else{
    $func_coverage{'tested'} = '?';
    $func_coverage{'non_lsb'} = '?';
    $func_coverage{'not_tested'} = '?';
    $func_coverage{'total'} = '?';
}

my %scen_status = (
        'passed' => 0,
        'failed' => 0,
        'nodata' => 0
    );
foreach (values %$scenario){
    if ($_ == 0){
        $scen_status{'passed'}++;
    }
    elsif ($_ == 1){
        $scen_status{'failed'}++;
    }
    else {
        $scen_status{'nodata'}++;
    }
}
$scen_status{'total'} = keys %$scenario;

#
# Print results
#
open(OUT, ">$out_file");

my $n_id = 0; # failure links counter

print OUT <<HTML;
<html>
<title>OLVER Test Run Report</title>
<style>

/* links */
a:link {
  text-decoration: none;
  color: #0040FF;
}

a:visited {
  text-decoration: none;
  color: #0040FF;
}

a:hover {
  text-decoration: underline;
}

a.main:link {
  text-decoration: none;
  color: #000000;
}

a.main:visited {
  text-decoration: none;
  color: #000000;
}

a.main:hover {
  text-decoration: none;
  color: #0040FF;
}

/* bordered table  */
table.border {
  border-collapse: collapse;
  font: 12px/1.5 Verdana, sans-serif;
  margin-bottom: 2em;
}

table.border td, table.border th {
  border: 1px solid #999999;
  padding: 3px;
  text-align: left;
}

table.border th {
  background-color: #EEEEEE;
  font-weight: bold;
}

/* inner table  */
table.inner {
  border-collapse: collapse;
  font: 12px/1.5 Verdana, sans-serif;
}

table.inner td, table.inner th {
  border: none;
  text-align: left;
}

table.inner th {
  background-color: #FFFFFF;
  font-weight: bold;
}

/**********/

ul {
  white-space: nowrap;
  list-style-type: none;
  margin-left: 1em;
  padding-left: 1em;
}

h1 {
  font: 22px/1.5 Verdana, sans-serif;
  font-weight: bold;
}

h2 {
  font: 15px/1.5 Verdana, sans-serif;
  font-weight: bold;
}

hr {
  height: 1px;
  color: #aaa;
  background-color: #aaa;
  border: 0;
}

span.info {
  color: #B000E0;
}

</style>

<script>
    function show(id,al)
    {
        el=document.getElementById(id);
        if(el.style.display!='none'){
            el.style.display='none';
            al.innerHTML = ' | ' + id.match(/\\((\\d+)\\)/)[1] + ' more...';
        }else{
            el.style.display='';
            al.innerHTML = ' | hide';
        }
        return false;
    }
</script>
<head>
<h1>Summary Report for OLVER Test Run</h1>
<h2>on Host <span class='info'>$env->{host}</span> under OS <span class='info'>$env->{os}</span> at Time <span class='info'>$env->{start_time}</span></h2>
</head>
<body>
HTML

#
# Print overall results
#
print OUT <<HTML;
<table class='border'>
<tr>
<th><a href='report/index.html'>Scenarios</a></th>
<th><a href='#fails'>Problems</a></th>
<th><a href='#funcs'>Functions</a></th>
<th><a href='result.htm'>Requirements</a></th>
</tr>
<tr>
<td>
<table class='inner'>
<tr><td>Passed</td><td>$scen_status{'passed'}</td></tr>
<tr><td>Failed</td><td>$scen_status{'failed'}</td></tr>
HTML
if($scen_status{'nodata'}){
    print OUT "<tr><td>No data</td><td><a href='#nodata'>".$scen_status{'nodata'}."</a></td></tr>\n";
}
else{
    print OUT "<tr><td>&nbsp;</td><td></td></tr>\n";
}
print OUT <<HTML;
<tr><td colspan='2'><hr/></td></tr>
<tr><th>Total</th><th>$scen_status{'total'}</th></tr>
</table>
</td>
<td>
<table class='inner'>
<tr><td>Known</td><td>$fail_status{'known'}</td></tr>
<tr><td>New</td><td>$fail_status{'new'}</td></tr>
<tr><td>Internal</td><td>$fail_status{'internal'}</td></tr>
<tr><td colspan='2'><hr/></td></tr>
<tr><th>Total</th><th>$fail_status{'total'}</th></tr>
</table>
</td>
<td>
<table class='inner'>
<tr><td>Tested</td><td>$func_coverage{'tested'}</td></tr>
<tr><td>Not tested</td><td>$func_coverage{'not_tested'}</td></tr>
<tr><td>&nbsp;</td><td></td></tr>
<tr><td colspan='2'><hr/></td></tr>
<tr><th>Total</th><th>$func_coverage{'total'}</th></tr>
</table>
</td>
<td>
<table class='inner'>
<tr><td>Passed</td><td>$req_coverage{'passed'}</td></tr>
<tr><td>Failed</td><td>$req_coverage{'failed'}</td></tr>
<tr><td>Checked</td><td>$req_coverage{'checked'}</td></tr>
<tr><td colspan='2'><hr/></td></tr>
<tr><th>Total</th><th>$req_coverage{'total'}</th></tr>
</table>
</td>
</tr>
</table>
HTML

#
# Print detailed results
#

# Scenarios with abcent trace logs
if($scen_status{'nodata'}){
    print OUT <<HTML;
<h1><a class='main' name='nodata' href='#'>Scenarios without traces</a></h1>
<table class='border'>
HTML
    foreach (sort keys %$scenario){
        if($scenario->{$_} == -1){
            print OUT "<tr><td>$_</td></tr>";
        }
    }
    print OUT "</table>";
}

#
# Print failures
#
my %id_name = (
    'Known' => 'Bug Id',
    'New' => 'Req Id',
    'Internal' => 'Kind'
    );
    
my %order = (
    'Known' => 0,
    'New' => 1,
    'Internal' => 2
    );

print OUT "<h1><a class='main' name='fails' href='#'>Problems</a></h1>";
foreach my $group (sort { $order{$a} <=> $order{$b} } keys %{$grouping}){
print OUT <<HTML;
<h2><a class='main' name='$group' href='#'>$group</a></h2>
<table class='border'>
<tr><th>Scenario</th><th>$id_name{$group}</th><th>Description</th><th>Failures</th></tr>
HTML
    foreach my $scen (sort keys %{$grouping->{$group}}){
        foreach my $id (sort keys %{$grouping->{$group}{$scen}}){
            my $descr = $grouping->{$group}{$scen}{$id}{'descr'};
#            $descr =~ s/(.{100,}?[\s\;\,](?=\S))/$1<br\/>/g;
print OUT <<HTML;
<tr><td>$scen</td><td>$id</td><td>$descr</td><td NOWRAP NOBREAK>
HTML
            my @failures = sort { $a =~ /failure (\d+).*/; my $na = $1; $b =~ /failure (\d+).*/; my $nb = $1; $na <=> $nb } @{$grouping->{$group}{$scen}{$id}{'failures'}};
            my $fid_shown = shift @failures;
print OUT <<HTML;
<a href='report/failures/${fid_shown}_0.html'>$fid_shown</a>
HTML
            if(my $count = @failures){
print OUT "<a onclick=\"return show('id_".++$n_id."($count)',this)\" href='\#')\"> | $count more...</a>";
print OUT "<span id='id_".$n_id."($count)' style='display:none'>";
                foreach my $fid (@failures){
print OUT <<HTML;
<br/><a href='report/failures/${fid}_0.html'>$fid</a>
HTML
                }
print OUT "</span>";
            }
print OUT <<HTML;
</td></tr>
HTML
        }
    }
print OUT "</table>";
}


#
# Prepare function coverage data
#

foreach (keys %funcs){
    if($funcs{$_} == 0){
        $funcs{$_} = "#00AA00";
    }
    elsif($funcs{$_} < 0){
        delete $funcs{$_};
        #$funcs{$_} = "#999999";
    }
    else{
        $funcs{$_} = "#FF0000";
    }
}

# Split data into $col_num columns
my $col_num = 5;

my @f = sort { if ($funcs{$a} eq $funcs{$b}){ return $a cmp $b} else { return $funcs{$a} cmp $funcs{$b} } } keys %funcs;
my $func_num = scalar @f;

my $row_num = int( $func_num / $col_num );
my $long_col = $func_num % $col_num;

my @f_shift = ( 0 );
for ( my $j = 1; $j < $col_num; $j++ ){
    $f_shift[$j] = $f_shift[$j - 1];
    
    if ($j <= $long_col){
        $f_shift[$j]++;
    }
}

#
# Print function coverage data
#
#<li style='color:#999999'>$func_coverage{'non_lsb'} tested, non LSB</li>
print OUT <<HTML;
<h1><a class='main' name='funcs' href='#'>Function coverage</a></h1>
<ul>
<li style='color:#00AA00'>$func_coverage{'tested'} tested</li>
<li style='color:#FF0000'>$func_coverage{'not_tested'} not tested</li>
</ul>
HTML
print OUT "<table class='border'>";
for ( my $i = 0; $i < $row_num; $i++ ){
    print OUT "<tr>";
    for ( my $j = 0; $j < $col_num; $j++ ){
        my $elem = $f[$j * $row_num + $i + $f_shift[$j]];
        print OUT "<td style='color:$funcs{$elem}'>$elem</td>";
    }
    print OUT "</tr>";
}
if ($long_col){
    print OUT "<tr>";
    for ( my $j = 0; $j < $long_col; $j++ ){
        my $elem = $f[($j + 1)* $row_num + $f_shift[$j]];
        print OUT "<td style='color:$funcs{$elem}'>$elem</td>";
    }
    print OUT "<td style='border-right:0;border-bottom:0'></td>";
    for ( my $j = $long_col + 1; $j < $col_num; $j++ ){
        print OUT "<td style='border-left:0;border-right:0;border-bottom:0'></td>";
    }
    print OUT "</tr>";
}
print OUT "</table>";

print OUT "</body></html>";
close(OUT);

