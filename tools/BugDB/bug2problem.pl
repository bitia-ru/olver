#!/usr/bin/perl

use strict;
use XML::Simple;

my $bugfile = shift;

my $bugDB;
if(-f $bugfile){
    $bugDB = XMLin($bugfile,
        ForceArray => ["pattern", "bug"],
        KeyAttr => {
            "pattern" => "origin",
            "bug" => "id"
            }
        );
}
else{
    die "Can't find file $bugfile"
}

use Data::Dumper;
#print Dumper($bugDB);
#exit;
#my $activity = 0;
foreach my $bug (sort keys %{$bugDB->{bug}}){
    foreach my $origin (sort keys %{$bugDB->{bug}{$bug}{pattern}}){
        my ($s, $ss, $spec_name) = split(/\./, $origin);
        
        $bug =~ /bug(\d+)_?(\d)?/;
        my $tp_num = "$1$2";    
        
        print "test /olver/$s/$ss/tests/$spec_name $tp_num\n";
        print "expected_severity failed\n";
        print "resolution Known problem\n";
        print "marker Registered bug: $bug\n";
        my @bug_body = split(/\n/,$bugDB->{bug}{$bug}{body});
        foreach(@bug_body){
            my $str = $_;
            $str =~ s/^\s+//g;
            chomp($str);
            $str =~ s/(http:\S+[\w\d])/<a href=\"$1\">$1<\/a>/g;
            if($str){
                print "comment $str\n";
            }
        }
        print "end\n\n";
    }
}

