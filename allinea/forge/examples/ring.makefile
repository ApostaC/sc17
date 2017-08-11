MPICC=mpicc
MPIF90=mpif90
MPIRUN=mpirun

all: ring_c ring_f
# Flags for compiler inlining: MAP works whether inlining is on or off,
# but you'll typically see more intuitive stacks with it turned off.
# The major compilers are discussed here:
#
# Intel: -g -fno-inline-functions -O3 is recommended. At O3 the compiler doesn't
# produce enough unwind info even with -debug inline-debug-info set.
#
# PGI: -g -Meh_frame -O3 is recommended. Other settings dont produce enough
# unwind information for inlined functions otherwise. This adds some
# performance penalty - around 8% is typical.
#
# GNU: -g -O3 -fno-inline is recommended. You might be lucky without -fno-inline,
# as it should produce enough information to unwind those calls. You will see
# my_function [inlined] in the MAP stack for functions that were inline.
# -fno-inline-functions appears with newer gnu compilers, just to confuse

# gnu
ring_c: ring.c
	${MPICC} -g -O3 -fno-inline ring.c -o ring_c -lm -lrt
ring_f: ring.f90
	${MPIF90} -g -O3 -fno-inline ring.f90 -o ring_f -lm -lrt
# intel
#	${MPICC} -g -fno-inline -no-ip -no-ipo -O3 ring.c -o ring_c -lm -lrt
#	${MPIF90} -g -fno-inline -no-ip -no-ipo -O3 ring.f90 -o ring_f -lm -lrt
# pgi
#	${MPICC} -g -Meh_frame -O3 ring.c -o ring_c -lm -lrt
#	${MPIF90} -g -Meh_frame -O3 ring.f90 -o ring_f -lm -lrt

check:
	${MPIRUN} -np 4 ./ring_c 3

clean:
	-rm -f ./ring_c ./ring_f
