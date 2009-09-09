#!/usr/bin/perl

# Script to generate OLVER-like report on mashines with no
# java installed
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
use File::Temp qw/tmpnam/;
use Time::Local;

sub model_sort{
    my $ma = $a->{'name'};
    my $mb = $b->{'name'};
    
    my $cmp_at = 0;
    $cmp_at-- if ( $ma =~ s/^\@// );
    $cmp_at++ if ( $mb =~ s/^\@// );
    
    $ma cmp $mb || $cmp_at;
}

my $bugDB;

package Exception;

sub new {
    my $self = shift;
    $self = {} unless $self;
    bless($self, "Exception");
}

sub kind{
    my $self = shift;
    return $self->{'kind'};
}

sub reqs{
    my $self = shift;
    
    return undef if ! defined $self->{'property'};
    return join (';', sort map { $_->{'name'} =~ /req_id\.(.*)/; $1 } grep { $_->{'name'} =~ /req_id/ } @{$self->{'property'}} );
}

sub origin{
    my $self = shift;

    if(defined $self->{'model'}){
        my @ids = sort keys %{$self->{'model'}};
        my $id = shift @ids;
        return ($self->{'model'}{$id}{'package'}, $self->{'model'}{$id}{'name'});
    }
    else{
        return ('unknown package', 'unknown model operation');
    }
}

sub isRequirementFailed{
    my $self = shift;
    
    return 0 if ! defined $self->{'property'};
    
    my $req_list = shift;
    my %reqs;
        
    foreach my $p (@{$self->{'property'}}){
        if ($p->{'name'} =~ /^req_id\./o){
            $reqs{$p->{'value'}} = 1;
        }
    }
    
    foreach ( split (';', $req_list) ){
        return 0 if not defined $reqs{$_};
    }
    return 1;
}

sub modelOperation{
    my $self = shift;
    if(defined $self->{'model'}){
        my @ids = sort keys %{$self->{'model'}};
        my $id = shift @ids;
        return $self->{'model'}{$id};
    }
    else{
        return Operation::new();
    }
}

sub interimFailures{
    my $self = shift;
    defined $self->{'interim_fail'} ? return List::new($self->{'interim_fail'}) : return List::new();
}

sub modelOperationSeries{
    my $self = shift;
    defined $self->{'series'} ? return List::new($self->{'series'}[0]) : return List::new();
}

sub info{
    my $self = shift;
    return $self->{'info'};
}

sub getCoveredElementId{
    my $self = shift;
    my $coverage = shift;
    return $self->modelOperation->coveredElementId($coverage);
}

sub transitionName{
    my $self = shift;
    return $self->{'transition'};
}

sub scenarioName{
    my $self = shift;
    return $self->{'scenario'};
}

package Operation;

sub new {
    my $self = shift;
    $self = {} unless $self;
    bless($self, "Operation");
}

sub name{
    my $self = shift;
    return $self->{'name'};
}

sub getParameterValue{
    my $self = shift;
    my $arg = shift;
    return undef if ! defined $self->{'model_value'};
    foreach my $p (@{$self->{'model_value'}}){
        if ($p->{'name'} eq $arg){
            return $p->{'value'};
        }
    }
}

sub returnValue{
    my $self = shift;
    return undef if ! defined $self->{'model_value'};
    foreach my $p (@{$self->{'model_value'}}){
        if ($p->{'kind'} eq 'result'){
            return $p->{'value'};
        }
    }
}

sub channel{
    my $self = shift;
    return undef if ! defined $self->{'model_value'};
    foreach my $p (@{$self->{'model_value'}}){
        if ($p->{'kind'} eq 'channel'){
            return $p->{'value'};
        }
    }
}

sub coveredElementId{
    my $self = shift;
    my $coverage = shift;
    return $self->{'coverage'}{$coverage};
}

package List;

sub new {
    my $self = shift;
    $self = [] unless $self;
    bless($self, "List");
}

sub size{
    my $self = shift;
    return scalar @{$self};
}

sub get{
    my $self = shift;
    my $num = shift;
    
    return defined @{$self}[$num] ? @{$self}[$num] : undef;
}


package main;

sub processBugDB{
    my $bugDB = shift;
    
    while (my ($id , $bug) = each(%{$bugDB->{'bug'}})){
        ### normalize text ###
        my $pattern_union;
                
        foreach my $pattern_el (@{$bug->{'pattern'}}){
            my $pattern = ref $pattern_el ? $pattern_el->{'content'} : $pattern_el;
            $pattern =~ s/\n\s*/ /go;
            $pattern =~ s/^\s+//o;
            $pattern =~ s/\s+$//o;
            $pattern =~ s/\s*&&\s*/ && /go;
            $pattern =~ s/\s*\|\|\s*/ || /go;
            if(! defined $pattern_union){
                $pattern_union = $pattern;
            }
            else{
                $pattern_union = '('.$pattern_union.') || ('.$pattern.')';
            }
        }
        $bug->{'body'} =~ s/\n\s*/ /go;
        $bug->{'body'} =~ s/^\s+//o;
        $bug->{'body'} =~ s/\s+$//o;
        
        $bug->{'body'} =~ s/&/&amp;/go;
        $bug->{'body'} =~ s/</&lt;/go;
        $bug->{'body'} =~ s/\"/&quot;/go;
       
        my $pattern = $pattern_union;

        # == and ""
        $pattern =~ s/(\b)(\w+_FAILED)(\b)/'$2'/go;
        $pattern =~ s/==(\s*["'])/eq$1/go;
        $pattern =~ s/(['"]\s*)==/$1eq/go;
        $pattern =~ s/!=(\s*["'])/ne$1/go;
        $pattern =~ s/(['"]\s*)!=/$1ne/go;
        $pattern =~ s/"/'/go;
        #$pattern =~ s/([\@\%\$])/\$1/go; ### TODO ???
        
        my $old = $pattern;
        ### convert bug pattern to internal format ###
        
        my $key_words = "get|kind|info|isRequirementFailed|modelOperation|modelOperationSeries|size|transitionName|scenarioName|interimFailures|name|returnValue|getParameterValue|getCoveredElementId";
        
        $pattern =~ s/(?<!\.)(?:\b)($key_words)(\b)/\$exc->$1/go;
        $pattern =~ s/\.($key_words)(\b)/->$1/go;
        
        ### ! doesn't suite as negation
        $pattern =~ s/!\s*\$/not \$/go;
        
        sub remove_esc{
            my $string = shift;
            $string =~ s/\\\\/\\/go;
            return $string;
        };
        
        sub esc_parenthesis{
            my $string = shift;
            $string =~ s/(?<!\\)\(/\\(/go;
            $string =~ s/(?<!\\)\)/\\)/go;
            return $string;
        };
        
        $pattern =~ s/(\$[^\$]*)\.indexOf\(/index($1, /go;
        $pattern =~ s/\.endsWith\(\s*['"](.*?[^\\])["']\s*\)/&esc_parenthesis(" =~ \/$1\$\/")/goe;
        $pattern =~ s/\.matches\(\s*['"](.*?[^\\])["']\s*\)/&remove_esc(" =~ \/$1\/")/goe;
        
        $bug->{'pattern'} = $pattern;

        delete $bug->{'property'}; ### TODO: useful to use this ussue
        
        my $funcref = eval( 'sub {my $exc = shift; return '.$pattern.';}' );
        if($@){
            print $old."\n\n";
            print $pattern."\n\n";
            print $@;
            exit;
        }
        else{
            $bug->{'func'} = $funcref;
        }
    }
}


package ReportHandler;
use base qw(XML::SAX::Base);

### Data ###

my $operation;
my %exception;
my $series;

my $f_sc = 0;
my $f_id = 0;
my $im_id = 0;

my $scenario;
my $transition;
my $transition_id;
my $model_id;
my $op_id;
my $exc_id = 0;
my $coverage_id;
my $formula_id;
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
    
    if($name eq 'model_operation_start'){
        $model_id = $atts{'refid'};
        
        if(defined $operation->{$model_id}){
            generate_struct_exception($self, "Duplicate model id '$model_id'");
        }
        
        $operation->{$model_id} = \%atts;
        Operation::new($operation->{$model_id});
        
        if($atts{'signature'} =~ /.*?(\w+)\(.*/){
            $operation->{$model_id}{'name'} = $1
        }
                
        $self->{'coverage'}{$atts{'package'}}{$atts{'signature'}}{'kind'} = $atts{'kind'};
    }
    elsif($name eq 'model_value'){
        push (@{$operation->{$model_id}{'model_value'}}, \%atts);
    }
    elsif($name eq 'model_operation_end'){
        undef $model_id;
    }
    elsif($name eq 'oracle_start'){
        $op_id = defined $atts{'ref'} ? $atts{'ref'} : $model_id;
        
        push(@{$series->[-1]}, "op_$op_id");
        
        if(not defined $operation->{$op_id}){
            $operation->{$op_id} = {'package' => $atts{'package'}, 'signature' => $atts{'signature'}};
            generate_struct_exception($self, "No model call with id '$op_id'");
        }
    }
    elsif($name eq 'oracle_end'){
        undef $op_id;
    }
    elsif($name eq 'exception'){
        $exc_id++;

        $exception{$exc_id} = \%atts;
        $exception{$exc_id}{'transition'} = $transition;
        $exception{$exc_id}{'scenario'} = $scenario;
        $exception{$exc_id}{'traceName'} = $main::trace_file_name.", transition $transition (id=$transition_id)";
        Exception::new($exception{$exc_id});
        
        if(defined $operation->{''}){
            delete $operation->{''};
        }
        
        if(defined $op_id){
            $exception{$exc_id}{'model'}{$op_id} = $operation->{$op_id};
        }
        elsif(defined $model_id){
            $exception{$exc_id}{'model'}{$model_id} = $operation->{$model_id};
        }
        elsif($atts{'kind'} eq 'SERIALIZATION_FAILED'){
            $exception{$exc_id}{'model'} = $operation if defined $operation;
        }
                
        if ($atts{'kind'} eq 'SERIALIZATION_FAILED'){
            $atts{'series'} = $series;
        }
        else{
            push(@{$series->[-1]}, "exc_$exc_id");
        }
        
        foreach (qw (kind interim internal)){
            if(defined $atts{$_}){
                push(@{$exception{$exc_id}{'property'}}, {'name' => $_, 'value' => $atts{$_}});
            }
        }
    }
    elsif($name eq 'property'){
        push(@{$exception{$exc_id}{'property'}}, \%atts);
    }
    elsif($name eq 'serialization_start'){
        push(@$series, []) if scalar @{$series->[-1]};
    }
    
    elsif($name eq 'coverage'){
        $coverage_id = $atts{'id'};
    }
    elsif($name eq 'element'){
        my $p = $operation->{$op_id}{'package'};
        my $s = $operation->{$op_id}{'signature'};

        $atts{'name'} =~ s/&/&amp;/go;
        $atts{'name'} =~ s/</&lt;/go;
        $atts{'name'} =~ s/\"/&quot;/go;

        $self->{'coverage'}{$p}{$s}{'coverage'}{$coverage_id}{$atts{'id'}}{'name'} = $atts{'name'};
    }
    elsif($name eq 'formula'){
        $formula_id = $atts{'id'};
    }
    elsif($name eq 'coverage_element'){
        my $p = $operation->{$op_id}{'package'};
        my $s = $operation->{$op_id}{'signature'};
        $self->{'coverage'}{$p}{$s}{'coverage'}{$atts{'coverage'}}{$atts{'id'}}{'hits'}++;
        
        $operation->{$op_id}{'coverage'}{$atts{'coverage'}} = $atts{'id'};
    }
    elsif($name eq 'prime_formula'){
        $operation->{$op_id}{'formula'}{$atts{'id'}} = $atts{'value'};
    }
    elsif($name eq 'mark'){
        my ($p, $s);
        if(defined $op_id and defined $operation->{$op_id}){
            $p = $operation->{$op_id}{'package'};
            $s = $operation->{$op_id}{'signature'};
        }
        elsif(defined $operation){
            my $id = (sort {$a <=> $b} keys %$operation)[0];
            $p = $operation->{$id}{'package'};
            $s = $operation->{$id}{'signature'};
        }
        else{
            $p = 'unknown package';
            $s = 'unknown model operation';
        }
        $self->{'coverage'}{$p}{$s}{'mark'}{$atts{'name'}}++;
    }
    elsif($name eq 'scenario_start'){
        $scenario = delete $atts{'name'};
        $self->{'scenario'}{$scenario} = \%atts;
        $self->{'scenario'}{$scenario}{'trace'} = $main::trace_file_name;
        $exc_id = 0;
        $f_sc = 0;
    }
    elsif($name eq 'scenario_end'){
        $self->{'scenario'}{$scenario}{'end_time'} = $atts{'time'};
    }
    elsif($name eq 'scenario_value'){
        if ($atts{'kind'} eq 'scenario method'){
            $transition = '?';
        }
    }
    elsif($name eq 'transition_start'){
        $transition_id = $atts{'id'};
        
        undef $operation;
        undef %exception;
        undef $series;
        push(@$series, []);
    }
    elsif($name eq 'transition_end'){
        foreach my $c_id (sort {$a <=> $b} keys %exception){
            next if(defined $main::mfpsc and $f_sc >= $main::mfpsc);
            $f_sc++;
            my $exc = $exception{$c_id};
            
            if(! defined $exc->{'interim'} or $exc->{'interim'} eq 'false'){
                if(defined $exc->{'series'}){
                    foreach my $s (@{$exc->{'series'}}){
                        foreach (@$s){
                            if ($_ =~ /exc_(\w+)/){
                                $self->{'interim'}{'Interim failure '.(++$im_id)} = $exception{$1};
                                $_ = 'im_'.$im_id;
                                
                                push(@{$exc->{'interim_fail'}}, $exception{$1});
                            }
                        }
                    }
                }
                                
                foreach my $b_id (keys %{$bugDB->{'bug'}}){
                    if ($bugDB->{'bug'}{$b_id}{'func'}($exc) ){
                        $exc->{'bug'} = $b_id;
                        last;
                    }
                }

                $self->{'failure'}{'failure '.(++$f_id)} = $exc;

                prepare_for_printing($exc);
                
                ### failure grouping according to scenario name ###
                push(@{$self->{'scenario'}{$scenario}{'failure'}}, "failure $f_id");
                
                ### failure grouping according to failure.grouping.xml ###
                my ($p, $s) = $exc->origin;
                
                if(my $b_id = $exc->{'bug'}){
                    push(@{$self->{'grouping'}{'known bugs'}{$p}{$s}{$b_id}}, "failure $f_id");
                }
                elsif ($exc->reqs ){
                    push(@{$self->{'grouping'}{'req failures'}{$p}{$s}}, "failure $f_id");
                }
                else{
                    if($exc->kind eq 'POSTCONDITION_FAILED' or $exc->kind eq 'INVARIANT_FAILED'){
                        push(@{$self->{'grouping'}{'other failures'}{'postcondition violation'}{$p}{$s}}, "failure $f_id");
                    }
                    elsif($exc->kind eq 'SCENARIO_FUNCTION_FAILED'){
                        push(@{$self->{'grouping'}{'other failures'}{'extra assertion violation'}}, "failure $f_id");
                    }
                    elsif($exc->kind eq 'MEDIATOR_FAILED'){
                        push(@{$self->{'grouping'}{'other failures'}{'target function failures'}{$p}{$s}}, "failure $f_id");
                    }
                    elsif($exc->kind eq 'INCORRECT_SET_OF_INTERACTIONS' or $exc->kind eq 'SERIALIZATION_FAILED'){
                        push(@{$self->{'grouping'}{'other failures'}{'serialization failures'}}, "failure $f_id");
                    }
                    elsif($exc->kind eq 'PRECONDITION_FAILED' or $exc->kind eq 'UNCONNECTED_GRAPH'
                        or $exc->kind eq 'NONDETERMINISTIC_GRAPH' or $exc->kind eq 'SCENARIO_INITIALIZATION_FAILED'
                        or $exc->kind eq 'INVALID_SCENARIO' or $exc->kind eq 'NONDETERMINISTIC_MODEL'
                        ){
                        push(@{$self->{'grouping'}{'other failures'}{'test failures'}}, "failure $f_id");
                    }
                    elsif($exc->kind eq 'INTERNAL_ERROR' or $exc->kind eq 'UNKNOWN_KIND'){
                        push(@{$self->{'grouping'}{'other failures'}{'internal failures'}}, "failure $f_id");
                    }
                    elsif($exc->kind eq 'STRUCTURAL_FAILURE'){
                        push(@{$self->{'grouping'}{'other failures'}{'structural failures'}}, "failure $f_id");
                    }
                }
            }
        }
        
        $transition = '';
        undef $transition_id;
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

    if ($name eq 'model_value'){
        $operation->{$model_id}{'model_value'}[-1]{'value'} = $cdata;
    }
    elsif ($name eq 'info'){
        $exception{$exc_id}{'info'} = $cdata;
    }
    elsif ($name eq 'exception'){
        if (! defined $exception{$exc_id}{'info'}){
            $exception{$exc_id}{'info'} = join ( ' ', map { ucfirst lc $_ } split ( '_', $exception{$exc_id}{'kind'}));
        }
    }
    elsif ($name eq 'coverage'){
        $coverage_id = '';
    }
    elsif ($name eq 'formula'){
        my $p = $operation->{$op_id}{'package'};
        my $s = $operation->{$op_id}{'signature'};
        
        $self->{'coverage'}{$p}{$s}{'formula'}{$formula_id} = $cdata;
        $formula_id = '';
    }
    elsif($name eq 'scenario_value'){
        if ($transition eq '?'){
            $transition = $cdata;
        }
    }
}

sub start_cdata {
    $cdata = '';
    $chars = '';
}

sub end_cdata {
    $cdata = $chars;
    $cdata =~ s/&amp;/&/go;
}

sub characters {
    my ($self, $el) = @_;
#    $el->{'Data'} =~ s/\n^[\s\t]+(.*)/$1 /gm;
#    $el->{'Data'} =~ s/\s+$//;
    $chars = $chars.$el->{'Data'};
}

sub error {
    my ($self, $el) = @_;
    generate_struct_exception($self, $el);
}

sub fatal_error {
    my ($self, $el) = @_;
    generate_struct_exception($self, $el);
}

sub generate_struct_exception{
    my $self = shift;
    my $error = shift;
    
    my $info;
    my $tracename = $main::trace_file_name;
        
    if(ref($error)){
        if(defined $error->{'Message'}){
            $info = $error->{'Message'};
        }
        else{
            $info = $error;
        }
        
        if(defined $error->{'LineNumber'}){
            $tracename .= ', line '.$error->{'LineNumber'};
        }
        elsif(defined $error->{'reader'}){
            $tracename .= ', line '.$error->{'reader'}[3];
        }
        else{
            $tracename .= ", transition $transition (id=$transition_id)";
        }
    }
    else{
        $info = $error;
        if($error =~ /line (\d+)/){
            $tracename .= ', line '.$1;
        }
        else{
            $tracename .= ", transition $transition (id=$transition_id)";
        }
    }
    
    $info =~ s/\n//go;
    
    ### TODO: constraint of structural fails per scenario

    my $exc = {
        'info' => $info,
        'structural' => 'true',
        'traceName' => defined $scenario ? $tracename : $main::trace_file_name,
        'scenario' => defined $scenario ? $scenario : ( $main::trace_file_name =~ /(\w+)\.ut/ ),
        };

    prepare_for_printing($exc);
    Exception::new($exc);
    $self->{'failure'}{'failure '.(++$f_id).' (structural)'} = $exc;
    push(@{$self->{'grouping'}{'other failures'}{'structural failures'}}, "failure $f_id (structural)");
    
    $main::is_struct_fail = 1;
}

### prepare data for printing ###
sub prepare_for_printing{
    my $exc = shift;
    
    defined $exc->{'prepared'} ? (return) : ($exc->{'prepared'} = 1);
        
    if(defined $exc->{'info'}){
        $exc->{'info'} =~ s/&/&amp;/go;
        $exc->{'info'} =~ s/</&lt;/go;
        $exc->{'info'} =~ s/\"/&quot;/go;
    }
    if(defined $exc->{'property'}){
        foreach (@{$exc->{'property'}}){
            $_->{'value'} =~ s/&/&amp;/go;
            $_->{'value'} =~ s/</&lt;/go;
            $_->{'value'} =~ s/\"/&quot;/go;
        }
    }
    if(defined $exc->{'model'}){
        foreach (values %{$exc->{'model'}}){
            foreach my $param (@{$_->{'model_value'}}){
                $param->{'value'} =~ s/&/&amp;/go;
                $param->{'value'} =~ s/</&lt;/go;
                $param->{'value'} =~ s/\"/&quot;/go;
            }
        }
    }
    if(defined $exc->{'interim_fail'}){
        foreach (@{$exc->{'interim_fail'}}){
            prepare_for_printing($_);
        }
    }
}

package main;

my $report_dir = './report';
my $res_file = './res.xml';
my $bug_db_file = '';
my $crpfm;
our $mfpsc;

GetOptions(
    "d=s" => \$report_dir,
    "x=s" => \$res_file,
    "crpfm=s" => \$crpfm,
    "mfpsc=s" => \$mfpsc, # max fails per scenario
    "bdbs=s" => \$bug_db_file
    );

$bug_db_file =~ s/xml://;
if(-f $bug_db_file){
    $bugDB = XMLin($bug_db_file,
        ForceArray => ["pattern", "bug", "property"],
        KeyAttr => {
#            "pattern" => "origin",
            "bug" => "id",
            "property" => "name"
            }
        );
    processBugDB($bugDB);
}

our $trace_file_name;
our $is_struct_fail;

my $handler = ReportHandler->new();
our $parser;

my $tmp_file = tmpnam();
foreach $trace_file_name (sort @ARGV){
    $is_struct_fail = 0;
    undef $ReportHandler::scenario;
    
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
    print "Processing entry: $short_file_name\n";

    $parser = XML::SAX::ParserFactory->parser(Handler => $handler);
    eval { $parser->parse({Source => {SystemId => $tmp_file}}) };
    if($@){
        ReportHandler::generate_struct_exception($handler, $@);
    }
    undef $parser;
    
    print "error: structural failures detected\n" if $is_struct_fail;
}
system("rm -f $tmp_file");

print "Generating results...\n";

### print xml report ###

open(RES, ">$res_file");

print RES "<?xml version='1.0' encoding='UTF-8'?>\n";
print RES "<Report technology=\"CTesK\" isCorrect=\"false\">\n";

### coverage ###

foreach my $p ( keys %{$handler->{'coverage'}}){
    print RES <<XML;
  <PackageDesc identifier="$p">
    <SpecificationDesc identifier="~undefined class~">
XML
    foreach my $s ( keys %{$handler->{'coverage'}{$p}}){
        my $kind = $handler->{'coverage'}{$p}{$s}{'kind'};
        print RES <<XML;
      <SpecificationMethodDesc identifier="$s" kind="$kind">
        <CoverageStructure name="$p/$s" noDisjuncts="true">
XML
        foreach my $id ( sort keys %{$handler->{'coverage'}{$p}{$s}{'formula'}}){
            my $name = $handler->{'coverage'}{$p}{$s}{'formula'}{$id};
            print RES <<XML;
          <Formula id="$id" text="$name" />
XML
        }
        foreach my $cov ( sort keys %{$handler->{'coverage'}{$p}{$s}{'coverage'}}){
            print RES <<XML;
          <CoverageDeclaration name="$cov" coverageStructure="$p/$s">
XML
            foreach my $id ( sort keys %{$handler->{'coverage'}{$p}{$s}{'coverage'}{$cov}}){
                my $name = $handler->{'coverage'}{$p}{$s}{'coverage'}{$cov}{$id}{'name'};
                print RES <<XML;
            <UserDefinedCoverageElement id="$id" text="$name" />
XML
            }
            print RES <<XML;
          </CoverageDeclaration>
XML
        }
        print RES <<XML;
        </CoverageStructure>
XML
        foreach my $cov ( sort keys %{$handler->{'coverage'}{$p}{$s}{'coverage'}}){
            foreach my $id ( sort keys %{$handler->{'coverage'}{$p}{$s}{'coverage'}{$cov}}){
                my $hits = $handler->{'coverage'}{$p}{$s}{'coverage'}{$cov}{$id}{'hits'};
                $hits = 0 if ! defined $hits;
                print RES <<XML;
        <CoveredUserDefElement coverageName="$cov" elementId="$id" hits="$hits"></CoveredUserDefElement>
XML
            }
        }
        foreach my $id ( sort keys %{$handler->{'coverage'}{$p}{$s}{'mark'}}){
            my $hits = $handler->{'coverage'}{$p}{$s}{'mark'}{$id};
            print RES <<XML;
        <CoveredStandaloneMark name="$id" hits="$hits" />
XML
        }
        print RES <<XML;
      </SpecificationMethodDesc>
XML
    }
    print RES <<XML;
    </SpecificationDesc>
  </PackageDesc>
XML
}

### scenarios ###

print RES <<XML;
  <PackageDesc identifier="~default package~">
XML
foreach my $scen ( sort keys %{$handler->{'scenario'}}){
    my $start_time = localtime($handler->{'scenario'}{$scen}{'time'} / 1000);
    my $end_time = localtime($handler->{'scenario'}{$scen}{'end_time'} / 1000);
    my $os = $handler->{'scenario'}{$scen}{'os'};
    my $host = $handler->{'scenario'}{$scen}{'host'};
    my $trace = $handler->{'scenario'}{$scen}{'trace'};

    print RES <<XML;
    <ScenarioDesc identifier="$scen">
      <ScenarioEnvironment startTime="$start_time" endTime="$end_time" trace="$trace">
        <EnvironmentProperty name="Host" value="$host" />
        <EnvironmentProperty name="Operating System" value="$os" />
      </ScenarioEnvironment>
XML
    foreach my $fail ( @{$handler->{'scenario'}{$scen}{'failure'}}){
        print RES <<XML;
      <FailureId identifier="$fail" isCertain="false" />
XML
    }
    print RES <<XML;
    </ScenarioDesc>
XML
}
print RES <<XML;
  </PackageDesc>
XML

### failures ###

foreach my $fid ( sort keys %{$handler->{'failure'}}){
    print_failure($fid, $handler->{'failure'}{$fid});
}
foreach my $fid ( sort keys %{$handler->{'interim'}}){
    print_failure($fid, $handler->{'interim'}{$fid});
}

sub print_failure{
    my $fid = shift;
    my $fail = shift;

    my ($p, $s) = $fail->origin;
    my $info = $fail->{'info'};
    my $scen = $fail->{'scenario'};
    my $trace_name = $fail->{'traceName'};
    my $structural = defined $fail->{'structural'} ? $fail->{'structural'} : 'false';
    my $interim = defined $fail->{'interim'} ? $fail->{'interim'} : 'false';
    
    print RES <<XML;
  <FailureDesc identifier="$fid" scenarioDesc="$scen" structural="$structural" interim="$interim" traceName="$trace_name" currentOracleSignature="$s" info="$info">
XML
    my $model = $fail->modelOperation;

    if (not defined $fail->{'series'}){
        if(defined $model->{'formula'}){
            foreach my $id ( sort keys %{$model->{'formula'}}){
                my $value = $model->{'formula'}{$id};
                print RES <<XML;
    <FormulaInfo id="$id" value="$value" />
XML
            }
        }
        if(defined $model->{'coverage'}){
            foreach my $id ( keys %{$model->{'coverage'}}){
                my $value = $model->{'coverage'}{$id};
                print RES <<XML;
    <CoveredElementDesc coverage="$id" elementId="$value" />
XML
            }
        }
    }
    
    foreach my $param (@{$model->{'model_value'}}){
        if ($param->{'kind'} eq 'argument'){
            print RES <<XML;
    <Parameter type="$param->{type}" name="$param->{name}" value="$param->{value}" />
XML
        }
    }
    foreach my $param (@{$model->{'model_value'}}){
        if ($param->{'kind'} eq 'result'){
            print RES <<XML;
    <Result value="$param->{value}" />
XML
        }
    }

    if(defined $fail->{'model'}){
        foreach my $id (sort keys %{$fail->{'model'}}){
            my $model = $fail->{'model'}{$id};
            my $channel = $model->channel;
            my $signature = $model->{'signature'};
            my $package = $model->{'package'};
            print RES <<XML;
    <ModelCall refid="$id" channel="$channel" signature="$signature" package="$package">
XML
            foreach my $param (@{$model->{'model_value'}}){
                if ($param->{'kind'} eq 'argument'){
                    print RES <<XML;
      <Parameter type="$param->{type}" name="$param->{name}" value="$param->{value}" />
XML
                }
            }
            print RES <<XML;
    </ModelCall>
XML
        }
    }
    if(defined $fail->{'series'}){
        foreach (@{$fail->{'series'}}){
            print RES <<XML;
    <Series>
XML
            foreach my $item (@{$_}){
                if($item =~ /op_(\d+)/){
                    my $id = $1;
                    my $model = $fail->{'model'}{$id};
                    print RES <<XML;
      <OracleCall ref="$id">
XML
                    if(defined $model->{'coverage'}){
                        foreach my $id ( keys %{$model->{'coverage'}}){
                            my $value = $model->{'coverage'}{$id};
                            print RES <<XML;
        <CoveredElementDesc coverage="$id" elementId="$value" />
XML
                        }
                    }
                    print RES <<XML;
      </OracleCall>
XML
                }
                elsif($item =~ /im_(\d+)/){
                    print RES <<XML;
      <FailureId identifier="Interim failure $1" />
XML
                }
            }
            print RES <<XML;
    </Series>
XML
        }
    }
    foreach my $param (@{$fail->{'property'}}){
        print RES <<XML;
    <Property name="$param->{name}" value="$param->{value}" />
XML
    }
    if(defined $fail->{'info'}){
        print RES <<XML;
    <Property name="info" value="$fail->{info}" />
XML
    }
    
    if(defined $fail->{'bug'}){
        my $bid = $fail->{'bug'};
        my $text = join ("\n        ",  grep /./o,  $bugDB->{'bug'}{$bid}{'body'} =~ /(.{0,100}(?:[\s\;\,](?=\S)|\z))/gs );
        print RES <<XML;
    <bug id="$bid"><body>
        $text
    </body>
    </bug>
XML
    }
    print RES <<XML;
  </FailureDesc>
XML
}

### grouping ###

print_group({"&lt;root group>" => $handler->{'grouping'}}, '');

sub print_group{
    my $group = shift;
    my $space = shift;
    $space = $space.'  ';
    foreach my $sg (keys %$group){
        print RES <<XML;
$space<FailureGroup name="$sg">
XML
        if(ref($group->{$sg}) eq 'HASH'){
            print_group($group->{$sg}, $space);
        }
        else{
            foreach my $f (@{$group->{$sg}}){
                print RES <<XML;
$space  <FailureId identifier="$f" />
XML
            }
        }
        print RES <<XML;
$space</FailureGroup>
XML
    }
    $space = substr($space, 2);
}

print RES "</Report>\n";
close(RES);

### print html report ###

system("rm -rf $report_dir");
system("mkdir -p $report_dir/failures");

### print css file ###

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


foreach my $fid ( sort keys %{$handler->{'failure'}}){
    print_failure_html($fid, $handler->{'failure'}{$fid});
}
foreach my $fid ( sort keys %{$handler->{'interim'}}){
    print_failure_html($fid, $handler->{'interim'}{$fid});
}

sub print_failure_html{
    my $fid = shift;
    my $fail = shift;
    
    open(FAIL, "> $report_dir/failures/${fid}_0.html");
    
    my $info = $fail->{'info'};
    my $scenario = $fail->{'scenario'};
    my $trace_name = $fail->{'traceName'};
    my $structural = defined $fail->{'structural'} ? $fail->{'structural'} : 'false';
    my $interim = defined $fail->{'interim'} ? $fail->{'interim'} : 'false';

    print FAIL <<HTM;
<html>
<head>
<title>$fid: $info</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<link rel="stylesheet" href="../report.css" type="text/css">
<script src="../xmlTree.js" type="text/javascript"></script>
</head>
<body>
<table width="100%" cellpadding="0" cellspacing="0" border="0">
<tr>
<!-- content -->
<td class="content">
HTM

    print FAIL <<HTM;
<h1>$fid:</h1>
<b>$info</b>

<table class="border">

<tr>
  <th colspan="2">location</th>
</tr>
<tr>
  <td>trace</td>
    <td>$trace_name</td>
  </tr>
<tr>
  <th colspan="2">occurence</th>
</tr>
HTM
    if(defined $scenario){
        print FAIL <<HTM;
<tr>
  <td>scenario</td>
  <td><a href="">$scenario</a></td>
</tr>
HTM
    }

if(not defined $fail->{'series'}){

    my $model = $fail->modelOperation;
    
    if(defined $model->{'name'}){
        print FAIL <<HTM;
<tr>
  <td>specification function</td>
  <td><a href="">$model->{name}()</a></td>
</tr>
HTM
    }
        
    if(defined $model->{'model_value'}){
        foreach my $param (sort model_sort @{$model->{'model_value'}}){
            if ($param->{'kind'} eq 'argument'){
            print FAIL <<HTM;
<tr>
  <td>parameter value</td>
  <td><nobr>&nbsp;$param->{type} $param->{name} =<wbr/> $param->{value}</nobr></td>
</tr>
HTM
            }
        }
        foreach my $param (@{$model->{'model_value'}}){
            if ($param->{'kind'} eq 'result'){
                print FAIL <<HTM;
<tr>
  <td>return value</td>
  <td><nobr>&nbsp;$param->{type}<wbr/> $param->{value}</nobr></td>
</tr>
HTM
            }
        }
    }

    if(defined $model->{'coverage'}){
        my $rowspan = keys %{$model->{'coverage'}};
        print FAIL <<HTM;
<tr>
  <td rowspan="$rowspan">coverage<br>&amp; branch</td>
HTM
        my $first = 1;
        foreach my $cov (keys %{$model->{'coverage'}}){
            my $branch = $handler->{'coverage'}{$model->{'package'}}{$model->{'signature'}}{'coverage'}{$cov}{$model->{'coverage'}{$cov}}{'name'};
        
            if(! $first){
                print FAIL "<tr>\n";
            }
            else{
                $first = 0;
            }

            print FAIL <<HTM;
  <td>$cov<br>$branch</td>
</tr>
HTM
        }
    }
}

    if(defined $fail->{'property'} and scalar @{$fail->{'property'}}){
        print FAIL <<HTM;
  <tr>
    <th colspan="2">properties</th>
  </tr>
HTM
    }
    
    foreach my $param (@{$fail->{'property'}}){
        print FAIL <<HTM;
<tr>
  <td>$param->{name}</td>
  <td>$param->{value}</td>
</tr>
HTM
    }
    
    print FAIL <<HTM;
</table>
HTM

if(defined $fail->{'series'}){
    print FAIL <<HTM;
<table class="border">
<caption>Stimuli &amp; reactions in the serialization:</caption>
  <tr>
    <th>id and signature</th>
    <th>channel</th>
    <th>timestamp</th>
    <th>parameter</th>
  </tr>
HTM
    foreach my $id (sort keys %{$fail->{'model'}}){
        my $model = $fail->{'model'}{$id};
        my $channel = $model->channel;
        my $signature = $model->{'signature'};
        my $kind = $model->{'kind'};

        my $rowspan = scalar grep( ($_->{'kind'} eq 'argument' or $_->{'kind'} eq 'result'), @{$model->{'model_value'}});
        my $letter = chr($id + 96);
        print FAIL <<HTM;
  <tr>
    <td class='double-up' rowspan="$rowspan">$letter) $kind $signature</td>
    <td class='double-up' rowspan="$rowspan">$channel</td>
    <td class='double-up' rowspan="$rowspan"></td>
HTM
        my $first = 1;

        foreach my $param (sort model_sort @{$model->{'model_value'}}){
            if ($param->{'kind'} eq 'argument'){

                if(! $first){
                    print FAIL "  <tr>\n";
                    print FAIL "    <td>";
                }
                else{
                    print FAIL "    <td class='double-up'>";
                    $first = 0;
                }

                print FAIL <<HTM;
<nobr>&nbsp;$param->{'type'} $param->{'name'} =<wbr/> $param->{'value'}</nobr></td>
  </tr>
HTM
            }
        }
        foreach my $param (@{$model->{'model_value'}}){
            if ($param->{'kind'} eq 'result'){

                if(! $first){
                    print FAIL "  <tr>\n";
                    print FAIL "    <td>";
                }
                else{
                    print FAIL "    <td class='double-up'>";
                    $first = 0;
                }

            print FAIL <<HTM;
<nobr>&nbsp;result =<wbr/> $param->{type}<wbr/> $param->{value}</nobr></td>
  </tr>
HTM
            }
        }
    }
print FAIL <<HTM;
</table>
<table class="border">
  <caption>Serialization:</caption>
  <tr>
    <th>#</th>
    <th>series</th>
    <th>coverage</th>
    <th>branch</th>
  </tr>
HTM

    my $ser_num = 0;
    foreach (@{$fail->{'series'}}){
        my $rowspan = scalar map { if ($_ =~ /op_(\d+)/){ defined $fail->{'model'}{$1}{'coverage'} ? keys %{$fail->{'model'}{$1}{'coverage'}} : $_ }else{ $_ } } @{$_};
        $ser_num++;
        
        print FAIL <<HTM;
  <tr>
    <td class='double-up' rowspan="$rowspan">$ser_num</td>
HTM
        
        my $first_line = 1;
        my $num = 0;
        foreach my $item (@{$_}){
            $num++;
            
            if($item =~ /op_(\d+)/){
                my $model = $fail->{'model'}{$1};
                my $cov_rowspan = defined $model->{'coverage'} ? scalar keys %{$model->{'coverage'}} : 1;
                my $letter = chr($1 + 96);
                my $first = 1;
                
                if($first_line){
                    print FAIL "    <td class='double-up rowspan=\"$cov_rowspan\"'>";
                }
                else{
                    print FAIL "  <tr>\n";
                    print FAIL "    <td rowspan=\"$cov_rowspan\">";
                }
                print FAIL <<HTM;
<span title="$model->{kind} $model->{signature}">$num. $model->{name} ($letter)</span></td>
HTM
                foreach my $cov (defined $model->{'coverage'} ? keys %{$model->{'coverage'}} : '--'){
                    my $branch = ($cov eq '--') ? '--' : $handler->{'coverage'}{$model->{'package'}}{$model->{'signature'}}{'coverage'}{$cov}{$model->{'coverage'}{$cov}}{'name'};

                    if($first_line){
                        $first_line = 0;
                        print FAIL <<HTM;
    <td class='double-up'>$cov</td>
    <td class='double-up'>$branch</td>
  </tr>
HTM
                    }
                    elsif($first){
                        $first = 0;
                        print FAIL <<HTM;
    <td>$cov</td>
    <td>$branch</td>
  </tr>
HTM
                    }
                    else{
                        print FAIL <<HTM;
  <tr>
    <td>$cov</td>
    <td>$branch</td>
  </tr>
HTM
                    }
                }
            }
            elsif($item =~ /im_(\d+)/){
                my $im = $handler->{'interim'}{'Interim failure '.$1};
                my $info = defined $im->{'info'} ? $im->{'info'} : $im->{'kind'};
                print FAIL <<HTM;
  <tr>
    <td colspan="3">
      <a href="../failures/Interim failure ${1}_0.html"> $info</a><br/>
    </td>
  </tr>
HTM
            }
        }
    }
        print FAIL <<HTM;
</table>
HTM
}

    if(defined $fail->{'bug'}){
        my $bid = $fail->{'bug'};
        my $text = $bugDB->{'bug'}{$bid}{'body'};
        $text =~ s/(http\:\/\/www\.nabble\.com.+\.html)/<a href="$1">$1<\/a>/g;
        $text =~ s/(http\:\/\/bugs\..+show_bug\.cgi\?id\=\d+)/<a href="$1">$1\<\/a>/g;
        $text =~ s/(http\:\/\/sources\..+show_bug\.cgi\?id\=\d+)/<a href="$1">$1\<\/a>/g;
        $text =~ s/(http\:\/\/linuxtesting\.\w+\/results\/report\?num\=S\w+)/<a href="$1">$1\<\/a>/g;
        #my $text = join ("<br/>",  grep /./o,  $bugDB->{'bug'}{$bid}{'body'} =~ /(.{0,100}(?:[\s\;\,](?=\S)|\z))/gs );
        print FAIL <<HTM;
<table class="border">
  <caption>similar known bug(s)</caption>
  <tr><td>$text</td></tr>
</table>
HTM
    }
    
    print FAIL <<HTM;
</td>
</tr>
</table>
</body>
</html>
HTM

    close(FAIL);
}
print "done\n";
