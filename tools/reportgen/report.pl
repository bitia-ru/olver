#!/usr/bin/perl

# Script to generate OLVER-like report on mashines with no
# java installed
#
# Copyright (c) 2005-2008 Institute for System Programming
#
# 02/12/2008 Roman Zybin, ISP RAS

BEGIN{
    chomp(my $program_dir = `dirname $0`);
    unshift @INC, $program_dir."/../share/perl";
}

use strict;
use XML::Parser;
use File::Temp qw/tmpnam/;

my $report_dir;
my $res_xml;

use Getopt::Long;
GetOptions( "d=s"=>\$report_dir,
            "x=s"=>\$res_xml
            );

my $parser = XML::Parser->new(
    Handlers => {
        Start =>        \&handle_elem_start,
        End =>          \&handle_elem_end,
        CdataStart =>   \&handle_cdata_start,
        CdataEnd =>     \&handle_cdata_end,
        Char =>         \&handle_char
    }
);

my $fid = 0;
my $scenario;
my $spec_func;
my $model_value;
my $property;
my $coverage_name;
my $coverage_element;
my $info;
my $exception;
my $text;
my $cdata;
my $formulaid;

my $package;
my $signature;
my $refid;
my $xml_model_value;
my $xml_property;
my $xml_coverage_element;
my $xml_formula_info;

our $trace_file_name;
my %spec_desc;
my $failures = "";

system("mkdir -p $report_dir/failures");

open(CSS, "> $report_dir/report.css");
print CSS <<TEXT;
body {
  margin: 0;
  padding: 0;
  color: #000000;
  background-color: #FFFFFF;
  font: 12px/1.5 Verdana, sans-serif;
}

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


td {
  font: 12px/1.5 Verdana, sans-serif;
}

td.content {
  padding: 1em;
  width: 100%;
  vertical-align: top;
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

table.border td.wo {
  border-left: 0;
  border-bottom: 0;
  border-right: 0;
  border-top: 0;
}

table.border td.wo-left {
  border-left: 0;
}

table.border td.wo-left-right {
  border-left: 0;
  border-right: 0;
}

table.border td.wo-left-up-down {
  border-left: 0;
  border-top: 0;
  border-bottom: 0;
}

table.border td.wo-left-right-up {
  border-left: 0;
  border-right: 0;
  border-top: 0;
}

table.border td.wo-left-right-down {
  border-left: 0;
  border-right: 0;
  border-bottom: 0;
}

table.border td.double-up {
  border-top: double 3px #999999;
}
table.border th.double-down {
  border-bottom: double 3px #999999;
}

table.border td.double-up-wo-right {
  border-top: double 3px #999999;
  border-right: 0;
}

table.border td.double-up-wo-left {
  border-top: double 3px #999999;
  border-left: 0;
  vertical-align: bottom;
}

table.border td.summary {
  font-weight: bold;  
}

table.border td.grandsummary {
  font-weight: bold;
  background: #F8F8F8;
  border-top: double 3px #999999;
}
table.border td.covered {
  background: #F4FFF4;
}
table.border td.maybecovered {
  background: #FFFFF4;
}
table.border td.uncovered {
  background: #FFF4F4;
}
table.border td.double-up-covered {
  border-top: double 3px #999999;
  background: #F4FFF4;
}
table.border td.double-up-maybecovered {
  border-top: double 3px #999999;
  background: #FFFFF4;
}
table.border td.double-up-uncovered {
  border-top: double 3px #999999;
  background: #FFF4F4;
}

table caption {
  text-align: left;
  font-weight: bold;
  padding-bottom: 1em;
  color: #666666;
}

hr.separator {
  border-top: 1px solid;
  border-top-color: #999999;
  border-bottom: none;
  border-left: none;
  border-right: none;
  height: 1px
}

/**********/

/* menu */

ul.top-level-menu {
  white-space: nowrap;
  list-style-type: none;
  margin-left: 0em;
  padding-left: 0em;
}

div.top-level-menu {
  width: 100%;
  border: 1px solid #999999;
  padding: 3px;
  text-align: left;
  background-color: #DDDDDD;
  white-space: nowrap;
  margin-top: 5px;
}

ul.menu {
  white-space: nowrap;
  list-style-type: none;
  margin-left: 1em;
  padding-left: 1em;
}

/**********/

h1 {
  font: 22px/1.5 Verdana, sans-serif;
  font-weight: bold;
}

.summary {
  font-weight: bold;
}

.exclamation {
  color: red;
}

.ok {
  color: green;
}

.highlight {
  font-style: italic;
  background-color: #EEEEEE;
}

div.probability {
  float: right;
  padding: 0 3px 0 12px;
  color: #999999;
}

.top-separator {
  padding-top: 3px;
  margin-top: 3px;
  border-top: 1px solid #DDDDDD;
}

.xmltree_root{
  list-style-type: none;
  margin-left: 0px;
  margin-top: 0px;
  margin-bottom: 0px;
  left: 0px;
  top: 0px;
  bottom: 0px;
}

.xmltree_branch{
  display: none;
  list-style-type: none;
  margin-left: 5px;
  margin-top: 0px;
  margin-bottom: 0px;
  left: 0px;
  top: 0px;
  bottom: 0px;
}

.xmltree_leaf{
  padding-left: 11px;
}

TEXT
close CSS;

my $tmp_file = tmpnam();
foreach $trace_file_name (sort @ARGV){
	if(! -f $trace_file_name){next};
	chomp($trace_file_name = `readlink -f $trace_file_name`);
	if($trace_file_name =~ /\.utz/){
		open(TRACE, "unzip -p $trace_file_name |");
	}
	elsif($trace_file_name =~ /\.utgz/){
		open(TRACE, "gunzip -c $trace_file_name |");
	}
	else{
		open(TRACE, "$trace_file_name");
	}
	
	open(TMP, "> $tmp_file");
	my $norep = 0;
	while(<TRACE>){
		if(! $norep and $_ =~ s/encoding=\"iso(\d)/encoding=\"iso-$1/){
			$norep = 1;
		}
		print TMP $_;
	}
	close(TMP);
	close(TRACE);
    
    print "$trace_file_name parsing...\n";
    (my $short_file_name = $trace_file_name) =~ s/.*\///;
    print " Processing entry: $short_file_name\n";
    
    eval {$parser->parsefile($tmp_file)};
    if($@){
        print "error: structural failures detected\n";
    }
}

system("rm -f $tmp_file");

open(RESXML, "> $res_xml");
print RESXML <<TEXT;
<?xml version='1.0' encoding='UTF-8'?>
<Report technology="CTesK" isCorrect="true">
TEXT

foreach my $package (sort keys %spec_desc){
    if($package eq ""){next};
print RESXML <<TEXT;
  <PackageDesc identifier="$package">
    <SpecificationDesc identifier="~undefined class~">
TEXT
    foreach my $signature (sort keys %{$spec_desc{$package}}){
        if($signature eq ""){next};
        my $s = $signature;
        $s =~ s/\w+\s+//;
print RESXML "      <SpecificationMethodDesc identifier=\"$s\" kind=\"stimulus\" specificationDesc=\"~undefined class~\" isNontrivialPostMarksExist=\"false\">\n";
print RESXML "        <CoverageStructure name=\"$package/$signature\" noDisjuncts=\"true\">\n";
        foreach my $formulaid (sort keys %{$spec_desc{$package}{$signature}{'formula'}}){
            my $text = $spec_desc{$package}{$signature}{'formula'}{$formulaid}{'text'};
            if(! defined($text)){$text = ""};
            $text =~ s/</&lt;/g;
            $text =~ s/>/&gt;/g;
            $text =~ s/\"/\'/g;
print RESXML "          <Formula id=\"$formulaid\" text=\"$text\" />\n";
        }
        foreach my $coverage (sort keys %{$spec_desc{$package}{$signature}{'coverage'}}){
print RESXML "          <CoverageDeclaration name=\"$coverage\" coverageStructure=\"$package/$signature\">\n";
            foreach my $cid (sort keys %{$spec_desc{$package}{$signature}{'coverage'}{$coverage}}){
                my $text = $spec_desc{$package}{$signature}{'coverage'}{$coverage}{$cid}{'text'};
                if(! defined($text)){$text = "The only branch"};
                $text =~ s/</&lt;/g;
                $text =~ s/>/&gt;/g;
                $text =~ s/\"/\'/g;
print RESXML "            <UserDefinedCoverageElement id=\"$cid\" text=\"$text\" />\n";
            }
print RESXML "          </CoverageDeclaration>\n";
            foreach my $cid (sort keys %{$spec_desc{$package}{$signature}{'coverage'}{$coverage}}){
                my $hits = $spec_desc{$package}{$signature}{'coverage'}{$coverage}{$cid}{'hits'};
print RESXML "        <CoveredUserDefElement coverageName=\"$coverage\" elementId=\"$cid\" hits=\"$hits\">\n";
print RESXML "        </CoveredUserDefElement>\n";
            }
        }
print RESXML "        </CoverageStructure>\n";
        foreach my $mark (sort keys %{$spec_desc{$package}{$signature}{'mark'}}){
            my $hits = $spec_desc{$package}{$signature}{'mark'}{$mark}{'hits'};
print RESXML "        <CoveredStandaloneMark name=\"$mark\" hits=\"$hits\" />\n";
        }
print RESXML "      </SpecificationMethodDesc>\n";
    }
print RESXML <<TEXT;
    </SpecificationDesc>
  </PackageDesc>
TEXT
}

print RESXML <<TEXT;
$failures</Report>
TEXT
close(RESXML);


sub handle_elem_start {
    my( $expat, $name, %atts ) = @_;
    
    if($name eq "model_operation_start"){
        $model_value = "";
        $property = "";
        $exception = 0;
        $info = "";
        
        $package = $atts{'package'};
        $signature = $atts{'signature'};
        $refid = $atts{'refid'};
        $xml_model_value = "";
        $xml_property = "";
        $xml_formula_info = "";
        
        $atts{'signature'} =~ m/(\w+)\s*?\(/;
        $spec_func = $1;
    }
    elsif($name eq "model_value"){
        if($atts{'kind'} eq "argument"){
            $model_value = $model_value."<tr>\n\t<td>parameter value</td>\n\t<td><nobr>&nbsp;$atts{'type'} $atts{'name'} = ";
            $xml_model_value = $xml_model_value."    <Parameter type=\"$atts{'type'}\" name=\"$atts{'name'}\"";
        }
        elsif($atts{'kind'} eq "result"){
            $model_value = $model_value."<tr>\n\t<td>return value</td>\n\t<td><nobr>&nbsp;($atts{'type'})";
            $xml_model_value = $xml_model_value."    <Result";
        }
    }
    elsif($name eq "property"){
        $property = $property."<tr>\n\t<td>$atts{'name'}</td>\n\t<td>$atts{'value'}</td>\n</tr>\n";
        $xml_property = $xml_property."    <Property name=\"$atts{'name'}\" value=\"$atts{'value'}\" />\n";
    }
    elsif($name eq "exception"){
        $exception = 1;
        $property = $property."<tr>\n\t<td>kind</td>\n\t<td>$atts{'kind'}</td>\n</tr>\n";
        $xml_property = $xml_property."    <Property name=\"kind\" value=\"$atts{'kind'}\" />\n";
        $property = $property."<tr>\n\t<td>internal</td>\n\t<td>$atts{'internal'}</td>\n</tr>\n";
        $xml_property = $xml_property."    <Property name=\"internal\" value=\"$atts{'internal'}\" />\n";
    }
    elsif($name eq "coverage_structure"){
    }
    elsif($name eq "coverage"){
        $coverage_name = $atts{'id'};
    }
    elsif($name eq "element"){
        $spec_desc{$package}{$signature}{'coverage'}{$coverage_name}{$atts{'id'}}{'text'} = $atts{'name'};
        $spec_desc{$package}{$signature}{'coverage'}{$coverage_name}{$atts{'id'}}{'hits'} = 0;
    }
    elsif($name eq "formula"){
        $formulaid = $atts{'id'};
    }
    elsif($name eq "coverage_element"){
        my $branch = $spec_desc{$package}{$signature}{'coverage'}{$atts{'coverage'}}{$atts{'id'}}{'text'};
        if(! defined($branch)){$branch = ""};
        $coverage_element = "<tr>\n\t<td rowspan=\"1\">coverage<br>&amp; branch</td>\n\t<td>$atts{'coverage'}<br>$branch</td>\n</tr>\n";
        $xml_coverage_element = "    <CoveredElementDesc coverage=\"$atts{'coverage'}\" elementId=\"$atts{'id'}\" />";
        $spec_desc{$package}{$signature}{'coverage'}{$atts{'coverage'}}{$atts{'id'}}{'hits'}++;
    }
    elsif($name eq "prime_formula"){
        $xml_formula_info = $xml_formula_info."    <FormulaInfo id=\"$atts{'id'}\" value=\"$atts{'value'}\" />\n";
    }
    elsif($name eq "mark"){
        $spec_desc{$package}{$signature}{'mark'}{$atts{'name'}}{'hits'}++;
    }
    elsif($name eq "model_operation_end"){
        if($exception){
            $fid++;
            open(HTML, "> $report_dir/failures/failure\ ${fid}_0.html");
print HTML <<TEXT;
<html>
<head>
<title>failure $fid: $info</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<link rel="stylesheet" href="../report.css" type="text/css">
</head>
<body>
<table width="100%" cellpadding="0" cellspacing="0" border="0">
<tr>
<!-- content -->
<td class="content">
<h1>failure $fid:</h1>
<b>$info</b>

<table class="border">

<tr>
    <th colspan="2">location</th>
</tr>
<tr>
    <td>trace</td>
    <td>$trace_file_name</td>
</tr>
<tr>
    <th colspan="2">occurence</th>
</tr>
<tr>
    <td>scenario</td>
    <td>$scenario</td>
</tr>
<tr>
    <td>specification function</td>
    <td>$spec_func</td>
</tr>
$model_value
$coverage_element
<tr>
    <th colspan="2">properties</th>
</tr>
$property
</table>
</td>
</tr>
</table>
</body>
</html>
TEXT
            close(HTML);

chomp($xml_model_value);
chomp($xml_property);
chomp($xml_formula_info);

$failures = $failures.<<TEXT;
  <FailureDesc identifier="failure $fid" scenarioDesc="$scenario" structural="false" interim="false" backtrace="" where="" traceName="" currentOracleSignature="$signature" info="$info">
$xml_formula_info
$xml_coverage_element
$xml_model_value
TEXT
$xml_model_value =~ s/    <Result.*>//;
chomp($xml_model_value);
$xml_model_value =~ s/    /      /g;
$failures = $failures.<<TEXT;
    <ModelCall refid="$refid" channel="" timestamp="" signature="$signature" package="$package">
$xml_model_value
    </ModelCall>
$xml_property
  </FailureDesc>
TEXT
            close(RESXML);
        }
    }
}

sub handle_elem_end {
    my( $expat, $name) = @_;
    
    if($name eq "scenario_value"){
        $scenario = $cdata;
    }
    elsif($name eq "model_value"){
        $model_value = $model_value."<wbr/>$cdata</nobr></td>\n</tr>\n";
        $xml_model_value = $xml_model_value." value=\"$cdata\" />\n";
    }
    elsif($name eq "info"){
        $xml_property = $xml_property."    <Property name=\"info\" value=\"$cdata\" />\n";
        $info = $cdata;
    }
    elsif($name eq "formula"){
        $spec_desc{$package}{$signature}{'formula'}{$formulaid}{'text'} = $cdata;
    }
}

sub handle_cdata_start {
    $cdata = "";
    $text = "";
}

sub handle_cdata_end {
    $cdata = $text;
    $cdata =~ s/&/&amp;/g;
    $cdata =~ s/</&lt;/g;
    $cdata =~ s/>/&gt;/g;
    $cdata =~ s/\"/&\#x22;/g;
    chomp($cdata);
}

sub handle_char {
	my( $expat, $string) = @_;
	$text = $text.$string;
}
