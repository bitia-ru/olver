#!/usr/bin/perl -w

# These should be above. But I can't seem to import
# them reliably without
# Elinfo being in a separate file.

BEGIN{push(@INC,"../share/perl")};
use English;
use XML::Parser;

my %elements;
my $file = shift;
my $reqfile = shift;
my $runlog = shift;
my $agentlog = shift;
my $all_lsb_funcs = shift;
my $testtime = shift;
my $unknown_failures_file = shift;

die "Can't find file \"$file\""
  unless -f $file;
    
my $parser = new XML::Parser(ErrorContext => 2);
$parser->setHandlers(	Start => \&start_handler,
		     			Char  => \&char_handler,
					 	End => \&end_handler,
					);

$parser->parsefile($file);


#
# Try to extract requirements-related information
# Read result.htm, parse line like <h4>Summary: ( Total: 333
my $req_total 	= "---";
my $req_covered = "---";
my $req_failed 	= "---";
my $req_total_checked = "---";


if ( $reqfile )
{
	open(REQ, $reqfile);

	while (<REQ>)
	{
		my $str = $_;
		if( $str =~  /\<h4\>Summary\:\( Total\:([\d]+) \/\ Covered\:([\d]+) \/\ Failed\:([\d]+)\)\<\/h4\>/ )
		{
			$req_total = "$1";
			$req_covered = "$2";
			$req_failed = "$3";
			$req_total_checked=$req_covered+$req_failed;
			last;
		}
	}
}



my %scenarios;
my $currScen = undef;
my $currFailure = undef;
my $currFailureLong = undef;



sub start_handler
{
    my $p = shift;
    my $el = shift;
    my %attrs = @_;
    if( $el eq "ScenarioDesc" ) {
    	my $sceninf;
    	$sceninf->{"name"} = $attrs{"identifier"};
    	
    	my @flrs;
    	$sceninf->{"failures"} = \@flrs;
    	$scenarios{$attrs{"identifier"}} = $sceninf;
    	$currScen = $sceninf;
	}
    if( $el eq "FailureId" ) {
		if ( $currScen ) {
			push ( @{$currScen->{failures}}, $attrs{"identifier"} );
		}
	}
	$currFailure = undef;
	if( $el eq "FailureDesc" and $attrs{"scenarioDesc"} )	{
		my $elinf;
		$elinf->{identifier} = $attrs{"identifier"};
		$elinf->{scenarioDesc} = $attrs{"scenarioDesc"};
		$elinf->{descr_buffer} = "";
		if( $attrs{"info"} )
		{
			$p->{finfo} = $attrs{"info"};
		}
		$elinf->{has_bug} = 0;
		$elements{$attrs{"identifier"}} = $elinf;
		$p->{FailureDesc} = $elinf;
		$p->{descr_buffer} = '';
		
    	my @ids;
    	$elinf->{"ids"} = \@ids;
		
		$currFailure = $elinf;
		$currFailureLong =$elinf;
    } 
    if( $el eq "Property" ) {
		if ( $currFailureLong ) {
			if ( $attrs{"name"} and $attrs{"value"} and ($attrs{"name"} eq ("req_id.".$attrs{"value"}) ) ) {
				push ( @{$currFailureLong->{ids}}, $attrs{"value"} );
			}
		}
	}
    if( $el eq "bug" ) {
		$p->{FailureDesc}{has_bug} = 1;
		$p->{FailureDesc}{bug_id} = $attrs{"id"};
		$p->{bug_buffer} = '';
    } 
}  # End start_handler

sub trim {
	my $string = shift;
	$string =~ s/\A\s+|\s+\z//gm;
    return $string;
}

sub char_handler {
	my($xp, $data) = @_;
	
	if( $data eq "" ){ return; }
	
	if ( $xp->in_element("FailureDesc") and $currFailure ) 
	{
		$xp->{descr_buffer} .= $data;
	}
	
	if ( $xp->in_element("body") ) 
	{
		$xp->{bug_buffer} .= $data;
	}
}

sub end_handler {
	my($p, $el) = @_;
	if ( $el eq "FailureDesc" )
	{
		$p->{FailureDesc}{text} = "";
		if ( $p->{finfo} )
		{
			$p->{FailureDesc}{text} .= trim($p->{finfo});
			$p->{finfo} = undef;
		}
		
		if ( $p->{descr_buffer} ) {
			$p->{FailureDesc}{text} .= trim($p->{descr_buffer});
		}
		
		$currFailureLong = undef;
	}
	if ( $el eq "bug" )
	{
		$p->{FailureDesc}{bug_descr} = trim($p->{bug_buffer});
	}
	if ( $el eq "ScenarioDesc" )
	{
		$currScen = undef;
	}
}

# Prints any referenced structure
sub print_ref {
    my $href = shift;
    my $marg = shift;
    
    unless ( defined($marg) ) { $marg = 0; }

    if ( ref($href) eq "" ) {
        if ( ! defined ($href) ) { 
            print 'undef';
        } else {
            print '"'.$href.'"';
        }
    }
    elsif ( ref($href) eq "SCALAR" ) {
        print '"'.$$href.'"';
    }
    elsif ( ref($href) eq "HASH" ) {
        print '%{ '."\n";
        foreach my $key ( keys %$href ) {
            print " " x ($marg+3);
            print_ref ( $key, $marg+3);
            print ' => ';
            print_ref ( $href->{$key}, $marg+3 );
            print "\n";
        }
        print " " x $marg;
        print '  }%';
    }
    elsif ( ref($href) eq "ARRAY" ) {
        print '@[ '."\n";
        foreach my $elem ( @$href ) {
            print " " x ($marg+3);
            print_ref ( $elem, $marg+3);
            print "\n";
        }
        print " " x $marg;
        print ' ]@';
    }
    else {
        print 'Unknown type: "'.ref($href).'"';
    }
    if ($marg == 0) { print "\n"; }
}
#----------------------------------------------------------------------------

sub dump_problem {
	my $value = shift;
    print "$value->{'identifier'}\n";
    print "$value->{'scenarioDesc'}\n";
	print "$value->{'text'}\n";
	if ( $value->{'bug_id'} ) {
		print "$value->{'bug_id'}\n";
	}
	if ( $value->{'bug_descr'} ) {
		print "$value->{'bug_descr'}\n";
	}
	if ( $value->{'has_bug'} ) {
		print "$value->{'has_bug'}\n";
	}
}

sub dump_problems {

	foreach $el (sort keys %elements)
	{
	    my $value = $elements{$el};	
	    dump_problem $value;
	}
}


#
# This section fills information about found problems in 3 groups:
# Known/New/Unresolved
# Known: Matched by BugDB (having BugID)
# New: Having Req ID
# Unresoved: Failures not matched and having no Req ID

my $count_known = 0;
my $count_new = 0;
my $count_unresolved = 0;
my $count_problems = 0;
my $count_problems_diff = 0;

my $newproblems_txt = 	"<table class='small' border=1 width=100%><tr><th>Scenario</th><th>Failure Id</th><th>Req Id</th><th>Description</th></tr>\n";
my $knownproblems_txt = "<table class='small' border=1 width=100%><tr><th>Scenario</th><th>Failure Id</th><th>Bug Id	</th><th>Description</th></tr>\n";
my $unresolved_txt = "<table class='small' border=1 width=100%><tr><th>Scenario</th><th>Failure Id	</th><th>Failure Description</th></tr>\n";
my $unresolved_scenarios = "<table class='small' border=1 width=100%><tr><th>Scenario</th><th>Status</th></tr>\n";
my $tested_functions = "<table class='small' border=1 width=100%><tr><th>LSB Function</th><th>Tested</th></tr>\n";

sub processBugDescription
{
	my $curtext=shift;
	$curtext =~ s/\t/ /g;
	$curtext =~ s/[ ]+/ /g;
	$curtext =~ s/\.([ ]*)\n/\.\$/g;
	$curtext =~ s/http\:\/\/www\.nabble\.com(.+)\.html/\<a href \= \"http\:\/\/www\.nabble\.com$1\.html\"\>at nabble\.com\<\/a\>/g;
	$curtext =~ s/([\s]+)http\:\/\/bugs\.(.+)show_bug\.cgi\?id\=([\d]+)/\, \<a href\=\"http\:\/\/bugs\.$2show_bug\.cgi\?id\=$3\"\>bug $3\<\/a\>/g;
	$curtext =~ s/([\s]+)http\:\/\/sources\.(.+)show_bug\.cgi\?id\=([\d]+)/\, \<a href\=\"http\:\/\/sources\.$2show_bug\.cgi\?id\=$3\"\>bug $3\<\/a\>/g;
	$curtext =~ s/([\s]+)http\:\/\/linuxtesting\.([\w]+)\/results\/report\?num\=S([\w]+)/ \<a href\=\"http\:\/\/linuxtesting\.$2\/results\/report\?num\=S$3\"\>www\.linuxtesting\.$2, bug $3\<\/a\>/g;
	
    my @chararr = split(//, $curtext);
    my $i;
    my $strlength=80;
    my $res="";
    my $outp_num=0;
    
    for($i=0;$i<=$#chararr;$i++)
    {
    	if($chararr[$i] ne "\n")
    	{
    		if($chararr[$i] ne "\$")
    		{
    			if($chararr[$i] eq "<" && $i+1<=$#chararr && $chararr[$i+1] eq "a")
    			{
    				while($chararr[$i] ne ">")
    				{
			    		$res .= $chararr[$i];
    					$i++;
    				}
		    		$res .= $chararr[$i];
    			}
    			elsif($chararr[$i] eq "<" && $i+1<=$#chararr && $chararr[$i+1] eq "/" && $i+2<=$#chararr && $chararr[$i+2] eq "a")
    			{
    				while($chararr[$i] ne ">")
    				{
			    		$res .= $chararr[$i];
    					$i++;
    				}
		    		$res .= $chararr[$i];
    			}
    			else
    			{
		    		$outp_num++;
		    		if($outp_num eq $strlength+1)
		    		{
			    		$res .= "\$";
			    		$outp_num = 0;
		    		}
		    		$res .= $chararr[$i];
		    	}
			}
			else
			{
	    		$outp_num = 0;
	    		$res .= "\$";
			}
    	}
    }

	$res =~ s/([\w]+)\(\)([ ]*)\$/\n$1\(\)/g;
	$res =~ s/\(([ ]*)\$/\n\(/g;
	$res =~ s/\)([ ]*)\$/\n\)/g;
	$res =~ s/([\w]+)\'([ ]*)\$/\n$1\'/g;
	$res =~ s/([\d]+)\$([\d]+)/\n$1$2/g;
	$res =~ s/([\w]+)\$/\n$1/g;
	$res =~ s/\$([ ]+)/\n/g;
	$res =~ s/\$\./\.\n/g;
	$res =~ s/\$/\n/g;
	
    return $res;
}


sub flrsort
{
	$a =~ m/(\d+)/;
	my $c = $1;
	$b =~ m/(\d+)/;
	my $d = $1;
	
	$c <=> $d;
}

my %scens_unknown;

open(UNKN_FAILURES_FILE, "> $unknown_failures_file");
my %filtered;
foreach $key ( sort flrsort keys %elements )
{
	my $value = $elements{$key};
	$count_problems++;
	my @ids = @{$value->{ids}};
	
	if(!($value->{identifier} =~ /Interim failure ([\d]+)/))
	{
		if ( $value->{'has_bug'} ) 
		{
			my $bugtxt=processBugDescription($value->{bug_descr});
			$curr = "<tr><td>$value->{scenarioDesc}</td><td NOBREAK NOWRAP><a href='report/failures/$value->{identifier}_0.html'>$value->{identifier}</a></td><td NOBREAK NOWRAP>$value->{bug_id}</td><td><pre>$bugtxt</pre></td></tr>\n";
			my $fcurr = $value->{scenarioDesc}.$value->{bug_descr};
			
			if ( not $filtered{$fcurr} ) 
			{
				$knownproblems_txt .= $curr;
				$count_known++;
			}
			$filtered{$fcurr} = 1;
		} elsif ( @ids > 0 ) {
			$ids_list = join( ", ", @ids );
			$curr = "<tr><td>$value->{scenarioDesc}</td><td NOBREAK NOWRAP><a href='report/failures/$value->{identifier}_0.html'>$value->{identifier}</a></td><td NOBREAK NOWRAP>$ids_list</td><td><pre>$value->{text}</pre></td></tr>\n";
			my $fcurr = $value->{scenarioDesc}.$value->{text};

			if ( not $filtered{$fcurr} ) 
			{
				$newproblems_txt .= $curr;
				$count_new++;
			}
			$filtered{$fcurr} = 1;

			my $sc_name=$value->{scenarioDesc};
			
			if(!(defined $scens_unknown{$sc_name}))
			{
				print UNKN_FAILURES_FILE "$sc_name\n";
				$scens_unknown{$sc_name}=1;
			}
		} else {
			$curr = "<tr><td>$value->{scenarioDesc}</td><td NOBREAK NOWRAP><a href='report/failures/$value->{identifier}_0.html'>$value->{identifier}</a></td><td><pre>$value->{text}</pre></td></tr>\n";
			my $fcurr = $value->{scenarioDesc}.$value->{text};
			if ( not $filtered{$fcurr} ) 
			{
				$unresolved_txt .= $curr;
				$count_unresolved++;
			}
			$filtered{$fcurr} = 1;

			my $sc_name=$value->{scenarioDesc};

			if(!(defined $scens_unknown{$sc_name}))
			{
				print UNKN_FAILURES_FILE "$sc_name\n";
				$scens_unknown{$sc_name}=1;
			}

		}
	}
}

$count_problems_diff = $count_known + $count_new + $count_unresolved;

$knownproblems_txt .= "</table>\n";
$newproblems_txt .= "</table>\n";
$unresolved_txt .= "</table>\n";

my $count_passed = 0;
my $count_failed = 0;
my $count_unknown = 0;
my $count_total = 0;

while ( my ($key, $value) = each(%scenarios) ) 
{
	my @failures = @{$value->{failures}};
	
	if ( @failures > 0 ) 
	{
		$count_failed++;
	} else {
		$count_passed++;
	}
}

my $count_scen_total = $count_passed + $count_failed;

my $realtotal = 0;
my @notprinted;
my $curi=0;
my $curline;

die "Can't find runlog file \"$runlog\""
  unless -f $runlog;

open(RLOG, $runlog);

while(<RLOG>)
{
	my $curstr= $_;
	if($curstr =~ /Running scenario ([\w]+)/)
	{
		my $run_scen_name="$1";

		if($run_scen_name eq "main_util_search_queue")
		{
			$run_scen_name="queue_scenario";
		}
		
		if(!(defined $scenarios{$run_scen_name}))
		{
			$notprinted[$curi]=$run_scen_name;
    		$curline = "<tr><td>$run_scen_name</td><td>Unresolved</td></tr>\n";
    		$unresolved_scenarios .= $curline;
			my $sc_name="$run_scen_name";
			if(!(defined $scens_unknown{$sc_name}))
			{
				print UNKN_FAILURES_FILE "$sc_name\n";
				$scens_unknown{$sc_name}=1;
			}
			$curi=$curi+1;
		}
	}
    elsif($curstr =~ /PASSED\: ([\d]+), FAILED\: ([\d]+), TERMINATED\: ([\d]+), ABNORMAL\: ([\d]+), UNKNOWN\: ([\d]+)/ )
	{
		$realtotal = $1+$2+$3+$4+$5;
	}
}

close(UNKN_FAILURES_FILE);

$unresolved_scenarios .= "</table>\n";

my $unresolved_sc = $realtotal-$count_scen_total;

my %called_funcs;

die "Can't find agentlog file \"$agentlog\""
  unless -f $agentlog;

open(AGLOG, $agentlog);

while(<AGLOG>)
{
	my $curstr= $_;
	if($curstr =~ /search for ([\w]+) \(([\d]+)\)\.\.\./)
	{
		my $cur_key = "$1";
		$cur_key .= "\n";
		$called_funcs{$cur_key} = "1";
	}
}

my $not_tested_functions = "";

die "Can't find all_lsb_funcs file \"$all_lsb_funcs\""
  unless -f $all_lsb_funcs;

my $tested_count = 0;

open(ALLFUNCS, $all_lsb_funcs);

while(<ALLFUNCS>)
{
	my $curstr= $_;
	if(defined ($called_funcs{$curstr}))
	{
		$curline = "<tr><td>$curstr</td><td>+</td></tr>\n";
    	$tested_functions .= $curline;
    	$tested_count++;
	}
	else
	{
		$curline = "<tr><td>$curstr</td><td>-</td></tr>\n";
		$not_tested_functions .= $curline;
	}
}

$tested_functions .= $not_tested_functions;
$tested_functions .= "</table>\n";


my $testhost = `uname -n`;
chomp $testhost;
my $testos = `uname -sr`;
chomp $testos;

print <<ENDM;
	<html>
		<title>OLVER Execution Report</title>
		<style>
			A:link    { COLOR: #0000FF; }
			A:visited { COLOR: #6666FF; }
			A:active  { COLOR: #6666FF; }
			A:hover   {
				COLOR: #FF0000;
				TEXT-DECORATION: underline;
			}

			H1{
			    FONT-FAMILY: Arial, Helvetica, sans-serif;
			    COLOR: #006600;
			    BACKGROUND-COLOR: white;
			    FONT-SIZE: 20pt;
			}
			H2{
			    FONT-FAMILY: Arial, Helvetica, sans-serif;
			    COLOR: #006600;
			    BACKGROUND-COLOR: white;
			    FONT-SIZE: 15pt;
			}
			H3{
			    FONT-FAMILY: Arial, Helvetica, sans-serif;
			    COLOR: #006600;
			    BACKGROUND-COLOR: white;
			    FONT-SIZE: 14pt;
			}
			H4{
			    FONT-FAMILY: Arial, Helvetica, sans-serif;
			    COLOR: #006600;
			    BACKGROUND-COLOR: white;
			    FONT-Style: italic;
			    FONT-SIZE: 12pt;
			}
			H5{
			    FONT-FAMILY: Arial, Helvetica, sans-serif;
			    COLOR: #006600;
			    BACKGROUND-COLOR: white;
			    FONT-SIZE: 11pt;
			}
			H6{
			    FONT-FAMILY: Arial, Helvetica, sans-serif;
			    COLOR: #006666;
			    BACKGROUND-COLOR: white;
			    FONT-SIZE: 10pt;
			    font-weight : bold;
			}
			TH.mainheader {
			    FONT-FAMILY: Arial, Helvetica, sans-serif;
			    COLOR: #006600;
			    BACKGROUND-COLOR: white;
			    FONT-SIZE: 11pt;
			}

			BODY
			{
			    FONT-FAMILY: Verdana, Arial, Helvetica, sans-serif;
			    FONT-SIZE: 10pt;
			    MARGIN-LEFT: 3pt;
			    MARGIN-TOP: 2pt;
			    COLOR: #000000;
			    /*BACKGROUND-COLOR: #EEEEEE;*/
			}

			BLOCKQUOTE.body
			{
			    FONT-SIZE: 10pt;
			    MARGIN-BOTTOM: 0pt;
			    MARGIN-LEFT: 0pt;
			    MARGIN-TOP: 0pt;
			    FONT-FAMILY: Verdana, Arial, Helvetica, sans-serif;
			    TEXT-INDENT: 10px;
			}

			TABLE {
			    FONT-FAMILY: Verdana, Arial, Helvetica, sans-serif;
			    FONT-SIZE: 10pt;
			    MARGIN-LEFT: 0pt;
			    MARGIN-TOP: 0pt;
			    COLOR: #000000;
			    BACKGROUND-COLOR: white;
			}

			UL 
			{
			    FONT-FAMILY: Verdana, Arial, Helvetica, sans-serif;
			    FONT-SIZE: 10pt;
			    COLOR: #000000;
			}

			LI
			{
			    FONT-FAMILY: Verdana, Arial, Helvetica, sans-serif;
			    FONT-SIZE: 10pt;
			    COLOR: #000000;
			/*     TEXT-INDENT: -10px; */

			}

			HR
			{
			    COLOR: #009900;
			}
			
			TH
			{
				text-align: left;
			}

			pre {FONT-SIZE: 11pt; }
			pre { font-family: monospace; }
		</style>
	<body>
		<h1>Summary Report for Test Run</h1>
		<h2>Host \'$testhost\' on OS \'$testos\' at Time $testtime</h2>
	<table border=1><tr><td>
		<table>
			<tr>
				<th colspan="2" class="mainheader">Scenarios</th>
			</tr>
			<tr>
				<th>Passed</th><td>$count_passed</td>
			</tr>
			<tr>
				<th>Failed</th><td>$count_failed</td>
			</tr>
ENDM

if($unresolved_sc!=0)
{
	print <<ENDM;
				<tr>
					<th>Unresolved</th><td><a href='#unres_scen'>$unresolved_sc</a></td>
				</tr>
ENDM
}
else
{
	print <<ENDM;
				<tr>
					<th>Unresolved</th><td>$unresolved_sc</td>
				</tr>
ENDM
}

	print <<ENDM;
				<tr>
					<th>Total</th><td>$realtotal</td>
				</tr>
				<tr>
					<td colspan="2"><a href="report/index.html">Details...</a></td>
				</tr>
			</table>
			</td><td bgcolor="#EEEEEE">
			<table>
				<tr>
					<th colspan="2" class="mainheader">Problems</th>
				</tr>
ENDM

if($count_known!=0)
{
	print <<ENDM;
				<tr>
					<th>Known</th><td><a href='#known'>$count_known</a></td>
				</tr>
ENDM
}
else
{
	print <<ENDM;
				<tr>
					<th>Known</th><td>$count_known</td>
				</tr>
ENDM
}
			
if($count_new!=0)
{
	print <<ENDM;
				<tr>
					<th>New</th><td><a href='#new'>$count_new</a></td>
				</tr>
ENDM
}
else
{
	print <<ENDM;
				<tr>
					<th>New</th><td>$count_new</td>
				</tr>
ENDM
}

if($count_unresolved!=0)
{
	print <<ENDM;
				<tr>
					<th>Internal</th><td><a href='#unresolved'>$count_unresolved</a></td>
				</tr>
ENDM
}
else
{
	print <<ENDM;
				<tr>
					<th>Internal</th><td>$count_unresolved</td>
				</tr>
ENDM
}

print <<ENDM;
			<tr>
				<th>Total</th><td>$count_problems_diff</td>
			</tr>
ENDM

if($count_known!=0)
{
	print <<ENDM;
			<tr>
				<td colspan="2"><a href='#known'>Details...</a></td>
			</tr>
ENDM
}
else
{
	print <<ENDM;
			<tr>
				<td colspan="2">----------</td>
			</tr>
ENDM
}

print <<ENDM;
		</table>
		</td><td>			
		<table>
			<tr>
				<th colspan='2' class="mainheader">Requirements</th>
			</tr>
			<tr>
				<th>Checked</th><td>$req_covered</td>
			</tr>
			<tr>
				<th>Failed</th><td>$req_failed</td>
			</tr>
			<tr>
				<th>Total</th><td>$req_total_checked</td>
			</tr>
			<tr>
				<th>Checked</th><td></td>
			</tr>
			<tr>
				<td colspan="2"><a href="result.htm">Details...</a></td>
			</tr>
		</table>
		</td></tr></table>
ENDM

print <<ENDM;
<p><b>Tested Functions:</b> $tested_count. <a href='#tested_funcs'>Details...</a> </p>
ENDM

if($count_known!=0)		
{
	print <<ENDM;
		<hr>
		<h2><a name='known'/>Known Problems</h2>
		$knownproblems_txt
ENDM
}
if($count_new!=0)		
{
	print <<ENDM;
			<hr>
			<h2><a name='new'/>New Problems</h2>
			$newproblems_txt
ENDM
}

if($count_unresolved!=0)
{
	print <<ENDM;
			<hr>
			<h2><a name='unresolved'/>Internal Problems</h2>
			$unresolved_txt
ENDM
}

if($unresolved_sc!=0)
{
	print <<ENDM;
			<hr>
			<h2><a name='unres_scen'/>Unresolved Scenarios</h2>
			$unresolved_scenarios
ENDM
}

print <<ENDM;
	<hr>
		<h2><a name='tested_funcs'/>Tested Functions	($tested_count)</h2>
		$tested_functions
ENDM
