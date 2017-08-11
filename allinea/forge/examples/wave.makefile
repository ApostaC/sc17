MPICC=mpicc
MPIF90=mpif90
MPIRUN=mpirun

all: wave_c wave_f
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
wave_c: wave.c
	${MPICC} -g -O3 -fno-inline wave.c -o wave_c -lm -lrt

wave_f: wave.f90
	${MPIF90} -g -O3 -fno-inline wave.f90 -o wave_f -lm -lrt

# intel 
#	${MPICC}  -g -fno-inline -no-ip -no-ipo -fno-omit-frame-pointer -O3 wave.c   -o wave_c -lm -lrt
#	${MPIF90} -g -fno-inline -no-ip -no-ipo -fno-omit-frame-pointer -O3 wave.f90 -o wave_f -lm -lrt
# pgi
#	${MPICC}  -g -O3 -Meh_frame -Mframe wave.c   -o wave_c -lm -lrt
#	${MPIF90} -g -O3 -Meh_frame -Mframe wave.f90 -o wave_f -lm -lrt

check:
	${MPIRUN} -np 4 ./wave_c 3

clean:
	-rm -f ./wave_c ./wave_f ./wave.mod
