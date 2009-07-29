#!/usr/bin/perl

# Script to generate tet-like report based on real one.
#
# Copyright (c) 2005-2009 Institute for System Programming
#
# 24/07/2009 Roman Zybin, ISP RAS

BEGIN{
    chomp(my $program_dir = `dirname $0`);
    unshift @INC, $program_dir."/../share/perl";
}

use strict;
use XML::SAX;
use XML::Simple;
use Getopt::Long;

package ReportHandler;
use base qw(XML::SAX::Base);

### Data ###

my $cur_pack = '';
my $cur_spec = '';
my $cur_fail = '';
my $cur_bug = '';
my @cur_grouping;

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

	if($name eq 'PackageDesc'){
		$cur_pack = $atts{'identifier'};
	}
	elsif($name eq 'SpecificationMethodDesc'){
		$atts{'identifier'} =~ s/.*?(\w+)\(.*/$1/;
		$cur_spec = $atts{'identifier'};
	}
	elsif($name eq 'CoveredStandaloneMark'){
		push(@{$self->{'tests'}{$cur_pack}{$cur_spec}{'reqs'}}, $atts{'name'});
	}
### fair test count
#	elsif($name eq 'CoveredUserDefElement'){
#		if(! defined $self->{'tests'}{$cur_pack}{$cur_spec}{'coverage'}){
#			$self->{'tests'}{$cur_pack}{$cur_spec}{'coverage'} = $atts{'coverageName'};
#			$self->{'tests'}{$cur_pack}{$cur_spec}{'hits'} += $atts{'hits'};
#		}
#		elsif($self->{'tests'}{$cur_pack}{$cur_spec}{'coverage'} eq $atts{'coverageName'}){
#			$self->{'tests'}{$cur_pack}{$cur_spec}{'hits'} += $atts{'hits'};
#		}
#	}
    elsif($name eq 'FailureDesc'){
    	$cur_fail = $atts{'identifier'};
    	
    	if(defined $atts{'scenarioDesc'}){
    		$self->{'failure'}{$cur_fail}{'scenario'} = $atts{'scenarioDesc'};
    	}
    	elsif($atts{'traceName'} =~ /(\w+)\.ut/){
    		$self->{'failure'}{$cur_fail}{'scenario'} = $1;
    		$self->{'failure'}{$cur_fail}{'property'}{'info'} = $atts{'info'};
    	}
    }
    elsif($name eq 'Property'){
    	if($atts{'name'} =~ /req_id/ or $atts{'name'} eq 'kind' or $atts{'name'} eq 'info'){
    		$self->{'failure'}{$cur_fail}{'property'}{$atts{'name'}} = $atts{'value'};
    	}
    }
    elsif($name eq 'bug'){
    	$cur_bug = $atts{'id'};
   		$self->{'failure'}{$cur_fail}{'bug'} = $cur_bug;
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

	if($name eq 'PackageDesc'){
		$cur_pack = '';
	}
	elsif($name eq 'SpecificationMethodDesc'){
		$cur_spec = '';
	}
    elsif($name eq 'FailureDesc'){
    	$cur_fail = '';
    }
    elsif($name eq 'bug'){
    	$cur_bug = '';
    }
    elsif($name eq 'FailureGroup'){
    	pop (@cur_grouping);
    }
}

package main;


my $res_file = shift;
die "Can't find file containing test results '$res_file'" unless -f $res_file;

my $handler = ReportHandler->new();
my $parser = XML::SAX::ParserFactory->parser(Handler => $handler);
$parser->parse({Source => {SystemId => $res_file}});

my $tests = delete ($handler->{'tests'});
my $failure = delete ($handler->{'failure'});

my $grouping;
my %fail_status;
foreach (keys %{$handler->{'grouping'}}){
	if($_ =~ /known bugs;([^;]+);([^;]+);([^;]+)/){
		my $pack = $1;
		my $spec = $2;
		my $bid = $3;
		my $fid = @{$handler->{'grouping'}{$_}}[0];
		
		my $reqs = join (';', sort map { s/req_id.//; $_ } grep { /req_id/ } keys %{$failure->{$fid}{'property'}} );
		$failure->{$fid}{'property'}{'reqs'} = $reqs;
		
		$tests->{$pack}{$spec}{'failures'}{$bid} = $fid;
	}
	elsif($_ =~ /req failures;([^;]+);([^;]+)/){
		my $pack = $1;
		my $spec = $2;

		foreach my $fid (@{$handler->{'grouping'}{$_}}){
			my $reqs = join (';', sort map { s/req_id.//; $_ } grep { /req_id/ } keys %{$failure->{$fid}{'property'}} );
			
			if(! defined $tests->{$pack}{$spec}{'failures'}{$reqs}){
				$tests->{$pack}{$spec}{'failures'}{$reqs} = $fid;
				$failure->{$fid}{'property'}{'reqs'} = $reqs;
			}
		}
	}
	else{
		# Obtain failure kind
		/([^;]+)$/;
		my $pack = 'undef.undef';
		my $spec = 'internal';
		my $kind = $1;
		
		foreach my $fid (@{$handler->{'grouping'}{$_}}){
			my $id = $failure->{$fid}{'scenario'}.';'.$kind;
			if(! defined $tests->{$pack}{$spec}{'failures'}{$id}){
				$tests->{$pack}{$spec}{'failures'}{$id} = $fid;
				if(defined $failure->{$fid}{'scenario'}){
					$failure->{$fid}{'property'}{'scen_info'} = 'Scenario '.$failure->{$fid}{'scenario'}.':';
				}
			}
		}
	}
}

my $mtime_c = 0;
sub mtime
{
    return "time_".(++$mtime_c);
}

my $version = "CTesk";
my $context = "00012345";

chomp(my $os = `uname -s`);
chomp(my $os_name = `uname -n`);
chomp(my $os_release = `uname -r`);
chomp(my $os_release_date = `uname -v`);
chomp(my $machine = `uname -m`);
chomp(my $date = `date \"+%H:%M:%S %Y%m%d\"`);

print "0|$version ".$date."|User: tester TCC Start\n";
print "5|$os $os_name $os_release $os_release_date $machine|System Information\n";

my $activity = 0;
foreach my $pack (sort keys %{$tests}){
	(my $s, my $ss) = split(/\./, $pack);
        
    foreach my $spec (keys %{$tests->{$pack}}){
#	    my $test_total = $tests->{$pack}{$spec}{'hits'};

	    my $num = 1;
	    my $tp_num;
	    my %printed;
	    
	    # Test information
#	    print "70||\"total tests in $pack.$spec $test_total\"\n";
	    # Test Case Start: 10|activity testcase time|IClist
	    print "10|$activity /olver/$s/$ss/tests/$spec ".&mtime."|TC Start\n";
	    # Test Case Manager Start: 15|activity version ICcount|text
	    print "15|$activity $version 1|TCM Start\n";
	    
	    # Print all failures
	    foreach my $fid (values %{$tests->{$pack}{$spec}{'failures'}}){
	        if(defined($failure->{$fid}{'bug'})){
	            $failure->{$fid}{'bug'} =~ /bug(\d+)_?(\d)?/;
	            $tp_num = "$1$2";
	            $printed{$tp_num} = 1;
	        }
	        else{
	        	while(defined($printed{$num})){$num++;}
	            $tp_num = $num;
	        }
	        
	        my $reqs = defined ($failure->{$fid}{'property'}{'reqs'})
	        	? 'Check requirement '.$failure->{$fid}{'property'}{'reqs'} : 'Check extra requirement';
	        
	        # Invocable Component Start: 400|activity ICnumber TPcount time|text
	        print "400|$activity $tp_num 1 ".&mtime."|IC start\n";
	        # Test Purpose Start: 200|activity TPnumber time|text
	        print "200|$activity $tp_num ".&mtime."|$reqs\n";
	        my $ii = 0;
	        
	        my $link = "./test_logs/olver_full/results/failures/${fid}_0.html";
	        $link =~ s/ /\&\#32\;/g;
	        # Test Case Information: 520|activity TPnumber context block sequence|text
	        print "520|$activity $tp_num $context 1 ".++$ii."|{noreplace}<a href=\"$link\">$fid</a>{/noreplace}\n";
	        print "520|$activity $tp_num $context 1 ".++$ii."|--------------------------------\n";

	        if(defined($failure->{$fid}{'property'}{'scen_info'})){
	            # Test Case Information: 520|activity TPnumber context block sequence|text
	            print "520|$activity $tp_num $context 1 ".++$ii."|".$failure->{$fid}{'property'}{'scen_info'}."\n";
	        }
	        
	        if(defined($failure->{$fid}{'property'}{'kind'})){
	            # Test Case Information: 520|activity TPnumber context block sequence|text
	            print "520|$activity $tp_num $context 1 ".++$ii."|".$failure->{$fid}{'property'}{'kind'}."\n";
	        }
	        
			if(defined($failure->{$fid}{'property'}{'info'})){
			    # Test Case Information: 520|activity TPnumber context block sequence|text
			    print "520|$activity $tp_num $context 1 ".++$ii."|{noreplace}".$failure->{$fid}{'property'}{'info'}."{/noreplace}\n";
			}
	        
	        if(defined($failure->{$fid}{'bug'})){
	            # Test Case Information: 520|activity TPnumber context block sequence|text
	            print "520|$activity $tp_num $context 1 ".++$ii."|--------------------------------\n";
	            print "520|$activity $tp_num $context 1 ".++$ii."|Registered bug: ".$failure->{$fid}{'bug'}."\n";
	        }
	        
	        # Test Purpose Result: 220|activity TPnumber result time|result-name
	        print "220|$activity $tp_num 1 ".&mtime."|FAIL\n";
	        # Invocable Component End: 410|activity ICnumber TPcount time|text
	        print "410|$activity $tp_num 1 ".&mtime."|IC end\n";
	        
	        $num++;
	    }
	    
	    # Print the rest tests
	    foreach my $req (@{$tests->{$pack}{$spec}{'reqs'}}){
			while(defined($printed{$num})){$num++;}
			$tp_num = $num;
			# Invocable Component Start: 400|activity ICnumber TPcount time|text
			print "400|$activity $tp_num 1 ".&mtime."|IC start\n";  
			# Test Purpose Start: 200|activity TPnumber time|text
			print "200|$activity $tp_num ".&mtime."|Check requirement $req\n";
			# Test Purpose Result: 220|activity TPnumber result time|result-name
			print "220|$activity $tp_num 0 ".&mtime."|PASS\n";
			# Invocable Component End: 410|activity ICnumber TPcount time|text
			print "410|$activity $tp_num 1 ".&mtime."|IC end\n";
       		$num++;
	    }

	    # Eliminate warnings
	    if(! scalar keys %{$tests->{$pack}{$spec}{'failures'}} and ! scalar @{$tests->{$pack}{$spec}{'reqs'}}){
	    	while(defined($printed{$num})){$num++;}
	        $tp_num = $num;
	        # Invocable Component Start: 400|activity ICnumber TPcount time|text
	        print "400|$activity $tp_num 1 ".&mtime."|IC start\n";  
	        # Test Purpose Start: 200|activity TPnumber time|text
	        print "200|$activity $tp_num ".&mtime."|No requirements checked\n";
	        # Test Purpose Result: 220|activity TPnumber result time|result-name
	        print "220|$activity $tp_num 0 ".&mtime."|PASS\n";
	        # Invocable Component End: 410|activity ICnumber TPcount time|text
	        print "410|$activity $tp_num 1 ".&mtime."|IC end\n";
        	$num++;
	    }
	    # Test Case End: 80|activity status time|text
	    print "80|$activity 0 ".&mtime."|TC End\n";
	    $activity++;
	}
}

# TCC End: 900|time|text
print "900|".&mtime."|TCC end";
