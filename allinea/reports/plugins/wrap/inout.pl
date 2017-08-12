#!/usr/bin/perl
# Uses the OpenMPI man pages to create a list of input and output parameters for MPI calls for use in wrap.py.
# Run this script in, e.g., openmpi-1.6.5/ompi/mpi/man/man3

use strict;

# This following notice applies to intersect and array_minux:
# 
# This module is Copyright (c) 2007 Sergei A. Fedorov.
# All rights reserved.
# 
# You may distribute under the terms of either the GNU General Public
# License or the Artistic License, as specified in the Perl README file.
# 
# This is free software. IT COMES WITHOUT WARRANTY OF ANY KIND.
sub intersect(\@\@) {
        my %e = map {$_=>1} @{$_[0]};
        return grep { $e{$_} } @{$_[1]};
}

sub array_minus(\@\@) {
        my %e = map{ $_ => undef } @{$_[1]};
        return grep( ! exists( $e{$_} ), @{$_[0]} ); 
}

# Find all man pages in the current directory.
my @manPages = glob('*.3');
if (!@manPages) {
    print "Run this script in the OpenMPI man page directory, e.g., openmpi-1.6.5/ompi/mpi/man/man3\n";
    exit 1;
}

# Global hash of input and output parameters for each function.
my %mpi_input_parameters;
my %mpi_output_parameters;
my %mpi_inout_parameters;

foreach my $manPage (@manPages) {
    open(my $fileHandle, '<', $manPage) || die "Can't open $manPage: $!\n";
    my $functionName;
    # Reference to @in or @out depending on whether we are reading input or output parameters
    my $inputOutput;
    # Array of the *indexes* of the input parameters (first parameter = 0)
    my @in;
    # Array of the *indexes* of the output parameters (first parameter = 0)
    my @out;
    # Array of the *indexes* of the input/output parameters (first parameter = 0)
    my @inOut;
    # Array of the *names* of the parameters.
    my @parameterNames;
    while (my $line = <$fileHandle>) {
        # Remove newline from the end of $line
        chomp($line);

        # .TH MPI_Irecv 3 "Jun 26, 2013" "1.6.5" "Open MPI"
        if ($line =~ /^\.TH ([A-Za-z_]+) /) {
            # .TH groff macro sets the title of the man page
            # We use the title to decide which MPI function we are looking at.
            $functionName = $1;
        } elsif (defined($functionName) &&
                 !defined($inputOutput) &&
                 $line =~ /^\s*(?:int\s+)?\Q$functionName\E\((.*)/) {
            # This is the function prototype.
            # We only care about functions that return int (see comment for rtypes global variable in wrap.py).
            my $parameters = $1;
            while ($parameters !~ /\)\s*$/) {
                # The parameters continue on the next line.
                $line = <$fileHandle>;
                # Remove newline from the end of $line
                chomp($line);
                # Remove leading whitespace
                $line =~ s/^\s+//;
                if ($parameters != ~ /\s+$/) {
                    # If $parameters does not end in one or more spaces then add one.
                    $parameters .= ' ';
                }
                # Append to the existing parameters
                $parameters .= $line;
            }
            # Remove markup from $parameters
            $parameters =~ s/\\f[A-Za-z]//g;
            # Remove trailing ) and whitespace from $parameters
            $parameters =~ s/\)\s*(;\s*)?$//g;
            # Split the parameters string into indivudual parameters
            my @parameters = split(/\s*,\s*/, $parameters);
            # Remove the type from each parameter
            @parameterNames = ();
            foreach my $parameter (@parameters) {
                $parameter =~ s/^.*\s+[&*]*([A-Za-z0-9_]+)\s*$/$1/;
                push(@parameterNames, $parameter);
            }
        } elsif ($line =~ /INPUT\/OUTPUT PARAMETERS?/) {
            $inputOutput = \@inOut;
        } elsif ($line =~ /INPUT PARAMETERS?/) {
            # Switch to the input parameters array
            $inputOutput = \@in;
        } elsif ($line =~ /OUTPUT PARAMETERS?/) {
            # Switch to the output parameters array
            $inputOutput = \@out;
        } elsif ($line =~ /DESCRIPTION/) {
            # End of parameters.
            last;
        } elsif (defined($inputOutput)) {
            my $parameterIndex = 0;
            foreach my $parameter (@parameterNames) {
                if ($line =~ /^\s*\Q$parameter\E\s*$/) {
                    # Add the *index* for this parameter to the current input/output parameters array.
                    push(@$inputOutput, $parameterIndex);
                }
                ++$parameterIndex;
            }
        }
    } 
    close($fileHandle);
    if (!defined($functionName)) {
        # File did not contain any prototypes.
        # e.g. MPI_Comm_c2f.3
        next;
    }
    if ($functionName eq 'MPI') {
        # Not a function
        next;
    }
    # Convert @in and @out to strings.
    if ($functionName eq 'MPI_Get') {
        # OpenMPI MPI_Get.3 has a typo.
        @in = (0, 1, 2, 3, 4, 5, 6, 7);
    }
    if ($functionName eq 'MPI_Bcast') {
        # OpenMPI MPI_Bcast.3 defines all parameters are input/output which is incorrect.
        @in = (0, 1, 2, 3, 4);
        @inOut = ();
    }

    # Fixup @in, @out and @inOut into three distinct sets.
    @in = (@in, @inOut);
    @out = (@out, @inOut);
    #@inOut = intersect(@in, @out);
    #@in = array_minus(@in, @inOut);
    #@out = array_minus(@out, @inOut);

    my $in = join(', ', @in);
    my $out = join(', ', @out);
    #my $inOut = join(', ', @inOut);

    # Add the in/out parameters for this function to the global hash.
    $mpi_input_parameters{$functionName} = $in;
    $mpi_output_parameters{$functionName} = $out;
    #$mpi_inout_parameters{$functionName} = $inOut;
}

# Finally write the output for copy-and-paste into wrap.py.
print "mpi_input_parameters = {\n";
foreach my $functionName (sort keys %mpi_input_parameters) {
    printf "    %-32s: [ %s ],\n", "\"$functionName\"", $mpi_input_parameters{$functionName}
}
print "}\n";
print "mpi_output_parameters = {\n";
foreach my $functionName (sort keys %mpi_output_parameters) {
    printf "    %-32s: [ %s ],\n", "\"$functionName\"", $mpi_output_parameters{$functionName}
}
print "}\n";
#print "mpi_inout_parameters = {\n";
#foreach my $functionName (sort keys %mpi_inout_parameters) {
#    printf "    %-32s: { %s },\n", "\"$functionName\"", $mpi_inout_parameters{$functionName}
#}
#print "}\n";
