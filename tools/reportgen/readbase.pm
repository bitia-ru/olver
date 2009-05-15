BEGIN{
    chomp(my $program_dir = `dirname $0`);
    unshift @INC, $program_dir."/../share/perl";
}

use strict;
use XML::Parser;

my $basefile="../reportgen/ids.xml";

my $parser = XML::Parser->new(
    Handlers => {
        Init =>			\&b_handle_doc_start,
        Final =>		\&b_handle_doc_end,
        Start =>		\&b_handle_elem_start,
        End =>     		\&b_handle_elem_end,
        CdataStart =>	\&b_handle_Cdata_start,
        CdataEnd =>		\&b_handle_Cdata_end,
        Char =>			\&b_handle_char_data,
    }
);

### Data ###

my %reqs;

sub get_reqs {return %reqs}

my @path;
my $cur_req = "";
my $cur_descr = "";
my $Cdata_w = 0;
my $Cdata = "";

$parser->parsefile($basefile);

### Handlers ###

sub b_handle_doc_start {
}

sub b_handle_elem_start {
    my( $expat, $name, %atts ) = @_;

    if($name eq "req")
    {   $cur_req = $atts{id};    }

    push @path, $atts{name};
}

sub b_handle_elem_end {
    my( $expat, $name ) = @_;

    if($name eq "descr")
    {   $cur_descr = $Cdata;   }
    elsif($name eq "req")
    {   $reqs{$cur_req} = $cur_descr;
#       print "$cur_req $cur_descr\n";
    }

    pop @path;
}

sub b_handle_Cdata_start {
#    my( $expat, $name, %atts ) = @_;
    $Cdata_w++;
    $Cdata = "";
}

sub b_handle_Cdata_end {
#    my( $expat, $name ) = @_;
    $Cdata_w--;
}

sub b_handle_char_data {
    my( $expat, $text ) = @_;

    $Cdata .= $text if($Cdata_w);
}

sub b_handle_doc_end {
}

1;  # return value evaluated