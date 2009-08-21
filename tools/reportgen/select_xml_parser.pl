#!/usr/bin/perl -w

# Simple script to determine appropriate xml parser for report generating
#
# Copyright (c) 2005-2009 Institute for System Programming
#
# 27/07/2009 Roman Zybin, ISP RAS

sub try_parser($);

if(@ARGV){
	try_parser(shift);
}

my @preferred = qw(XML::SAX::Expat XML::SAX::ExpatXS XML::LibXML::SAX XML::Parser::PerlSAX);

foreach (@preferred){
	try_parser($_);
}

eval ("use XML::SAX; my \@parsers = map { \$_->{'Name'} } \@{XML::SAX->parsers}; foreach (reverse \@parsers){ try_parser(\$_); }");

sub try_parser($)
{
	my $parser = shift;
	
	my $try = eval ( "sub { use $parser;my \$p = $parser->new();\$p->parse({Source => {String => '<test>test</test>'}}); }" );
	if($try){
		eval { &$try };
		if(not $@){
			print <<INI;
[ParserPackage]
ParserPackage = $parser
INI
			exit;
		}
	}
}