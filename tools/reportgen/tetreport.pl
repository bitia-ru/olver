#!/usr/bin/perl

BEGIN{push(@INC,"../share/perl")};
use strict;
use XML::Simple;
use readbase;

my $xmlfile = shift;

my $xmlreport;
if(-f $xmlfile){
    $xmlreport = XMLin($xmlfile,
        ForceArray => ["FailureDesc", "PackageDesc", "SpecificationMethodDesc", "FailureId", "CoveredStandaloneMark", "Property"],
        KeyAttr => {
            "FailureDesc" => "identifier",
            "Property" => "name",
            "PackageDesc" => "identifier",
            "SpecificationMethodDesc" => "identifier",
            "FailureId" => "identifier",
            "CoveredStandaloneMark" => "name"
            }
        );
}
else{
    die "Can't find file $xmlfile"
}

my %reqs;
if(-f "./ids.xml"){
    %reqs = &get_reqs;
}
else{
    die "Can't find file ./ids.xml"
}

my $mtime_c = 0;
sub mtime
{
    return "time_".(++$mtime_c);
}

use Data::Dumper;


my $version = "CTesk";
my $context = "00012345";


my $os = `uname -s`;
chomp $os;
my $os_name = `uname -n`;
chomp $os_name;
my $os_release = `uname -r`;
chomp $os_release;
my $os_release_date = `uname -v`;
chomp $os_release_date;
my $machine = `uname -m`;
chomp $machine;
my $date = `date \"+%H:%M:%S %Y%m%d\"`;
chomp $date;

print "0|$version ".$date."|User: tester TCC Start\n";
print "5|$os $os_name $os_release $os_release_date $machine|System Information\n";

my $activity = 0;
foreach my $pkg (sort keys %{$xmlreport->{PackageDesc}}){
    if ($pkg ne "~default package~"){
        (my $s, my $ss) = split(/\./, $pkg);
        
        foreach my $spec (keys %{$xmlreport->{PackageDesc}{"$pkg"}{SpecificationDesc}{SpecificationMethodDesc}}){
            my $req_failed;
            my $req_count = scalar(keys %{$xmlreport->{PackageDesc}{"$pkg"}{SpecificationDesc}{SpecificationMethodDesc}{"$spec"}{CoveredStandaloneMark}});
            $spec =~ /\*?(\w+)\(/;
            my $spec_name = $1;
            my $num = 1;
            my $tp_num;
            
            # Test information
            print "70||\"total reqs in $pkg.$spec_name $req_count\"\n";
            # Test Case Start: 10|activity testcase time|IClist
            print "10|$activity /olver/$s/$ss/tests/$spec_name ".&mtime."|TC Start\n";
            # Test Case Manager Start: 15|activity version ICcount|text
            print "15|$activity $version 1|TCM Start start\n";
            
            # Print all failures
            foreach my $fid (keys %{$xmlreport->{PackageDesc}{"$pkg"}{SpecificationDesc}{SpecificationMethodDesc}{"$spec"}{FailureId}}){
                if(defined($xmlreport->{FailureDesc}{"$fid"}{bug})){
                    $xmlreport->{FailureDesc}{"$fid"}{bug}{id} =~ /bug(\d+)_?(\d)?/;
                    $tp_num = "$1$2";
                }
                else{
                    $tp_num = $num;
                }
                
                # Invocable Component Start: 400|activity ICnumber TPcount time|text
                print "400|$activity $tp_num 1 ".&mtime."|IC start\n";                
                # Test Purpose Start: 200|activity TPnumber time|text
                print "200|$activity $tp_num ".&mtime."|TP Start\n";
                my $ii = 0;
                
                my $link = "./test_logs/olver_full/report/failures/${fid}_0.html";
                $link =~ s/ /\&\#32\;/g;
                # Test Case Information: 520|activity TPnumber context block sequence|text
                print "520|$activity $tp_num $context 1 ".++$ii."|{noreplace}<a href=\"$link\">$fid</a>{/noreplace}\n";
                print "520|$activity $tp_num $context 1 ".++$ii."|--------------------------------\n";
                if(defined($xmlreport->{FailureDesc}{"$fid"}{Property}{kind})){
                    # Test Case Information: 520|activity TPnumber context block sequence|text
                    print "520|$activity $tp_num $context 1 ".++$ii."|".$xmlreport->{FailureDesc}{"$fid"}{Property}{kind}{value}."\n";
                }
                
                my $text = "";
                foreach my $property (keys %{$xmlreport->{FailureDesc}{"$fid"}{Property}}){
                    if($property =~ m/req_id\.(.*)/){
                        $req_failed->{$1} = 1;
                        if($text eq ""){
                            $text = "$1} $reqs{$1}";
                        }
                        else{
                            $text = "$1;$text";
                        }
                    }
                }
                
                if($text ne ""){
                    # 520|activity TPnumber context block sequence|text
                    print "520|$activity $tp_num $context 1 ".++$ii."|{noreplace}Requirement failed: {".$text."{/noreplace}\n"; 
                }
                else{
                    if(defined($xmlreport->{FailureDesc}{"$fid"}{Property}{info})){
                        # Test Case Information: 520|activity TPnumber context block sequence|text
                        print "520|$activity $tp_num $context 1 ".++$ii."|{noreplace}".$xmlreport->{FailureDesc}{"$fid"}{Property}{info}{value}."{/noreplace}\n";
                    }
                }
                
                if(defined($xmlreport->{FailureDesc}{"$fid"}{bug})){
                    # Test Case Information: 520|activity TPnumber context block sequence|text
                    print "520|$activity $tp_num $context 1 ".++$ii."|--------------------------------\n";
                    print "520|$activity $tp_num $context 1 ".++$ii."|Registered bug: ".$xmlreport->{FailureDesc}{"$fid"}{bug}{id}."\n";
                    #print "520|$activity $tp_num $context 1 ".++$ii."|--------------------------------\n";
                    
#                    my @bug_body = split(/\n/,$xmlreport->{FailureDesc}{"$fid"}{bug}{body});
#                    foreach(@bug_body){
#                        my $str = $_;
#                        $str =~ s/^\s+//g;
#                        chomp($str);
#                        if($str){
#                            print "520|$activity $tp_num $context 1 ".++$ii."|".$str."\n";
#                        }
#                    }
                }
                
                # Test Purpose Result: 220|activity TPnumber result time|result-name
                print "220|$activity $tp_num 1 ".&mtime."|FAILED\n";
                # Invocable Component End: 410|activity ICnumber TPcount time|text
                print "410|$activity $tp_num 1 ".&mtime."|IC end\n";
                $num++;
            }
            
            # Eliminate warnings
            if(! scalar keys %{$xmlreport->{PackageDesc}{"$pkg"}{SpecificationDesc}{SpecificationMethodDesc}{"$spec"}{CoveredStandaloneMark}}){
                # Invocable Component Start: 400|activity ICnumber TPcount time|text
                print "400|$activity 1 1 ".&mtime."|IC start\n";  
                # Test Purpose Start: 200|activity TPnumber time|text
                print "200|$activity 1 ".&mtime."|TP Start no reqs\n";
                # Test Purpose Result: 220|activity TPnumber result time|result-name
                print "220|$activity 1 0 ".&mtime."|PASS\n";
                # Invocable Component End: 410|activity ICnumber TPcount time|text
                print "410|$activity 1 1 ".&mtime."|IC end\n";                
            }
            # Print the rest requirements
            foreach my $req (keys %{$xmlreport->{PackageDesc}{"$pkg"}{SpecificationDesc}{SpecificationMethodDesc}{"$spec"}{CoveredStandaloneMark}}){
                if(! defined($req_failed->{$req})){
                    $tp_num = $num;
                    # Invocable Component Start: 400|activity ICnumber TPcount time|text
                    print "400|$activity $tp_num 1 ".&mtime."|IC start\n";  
                    # Test Purpose Start: 200|activity TPnumber time|text
                    print "200|$activity $tp_num ".&mtime."|TP Start $req\n";
                    # 520|activity TPnumber context block sequence|text
                    print "520|$activity $tp_num $context 1 1|$reqs{$req}\n";
                    # Test Purpose Result: 220|activity TPnumber result time|result-name
                    print "220|$activity $tp_num 0 ".&mtime."|PASS\n";
                    # Invocable Component End: 410|activity ICnumber TPcount time|text
                    print "410|$activity $tp_num 1 ".&mtime."|IC end\n";
                    $num++;
                }
            }
            
            # Test Case End: 80|activity status time|text
            print "80|$activity 0 ".&mtime."|TC End\n";
            $activity++;
        }
    }
}

# TCC End: 900|time|text
print "900|".&mtime."|TCC end";
