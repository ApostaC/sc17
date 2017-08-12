MPICC=mpicc
MPIF90=mpif90
MPIRUN=mpirun

all: slow_f
# Flags for compiler inlining: MAP works whether inlining is on or off,
# but you'll typically see more intuitive stacks with it turned off.
# The major compilers are discussed here:
#
# Intel: -g -fno-inline -no-ip -no-ipo -fno-omit-frame-pointer -O3 is recommended.
#
# PGI: -g -O3 -Meh_frame -Mframe is recommended.
#
# GNU: -g -O3 -fno-inline is recommended. You might be lucky without -fno-inline,
# as it should produce enough information to unwind those calls. You will see
# my_function [inlined] in the MAP stack for functions that were inline.
# -fno-inline-functions appears with newer gnu compilers, just to confuse

# gnu
slow_f: slow.f90
	${MPIF90} -g -O3 -fno-inline slow.f90 -o slow_f -lm -lrt
# intel
#	${MPIF90} -g -fno-inline -no-ip -no-ipo -fno-omit-frame-pointer -O3 slow.f90 -o slow_f -lm -lrt
# pgi
#	${MPIF90} -g -Meh_frame -Mframe -O3 slow.f90 -o slow_f -lm -lrt

check:
	${MPIRUN} -np 4 ./slow_f 3

clean:
	-rm -f ./slow_f
