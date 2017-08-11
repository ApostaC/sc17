MPICC := mpicc
MPIF90 := mpif90
MPIRUN := mpirun

all: openmp_c openmp_f slow_openmp wave_openmp

# Flags for compiler inlining: MAP works whether inlining is on or off,
# but you'll typically see more intuitive stacks with it turned off.
# The major compilers are discussed here:
#
# Intel: -g -fno-inline-functions -fno-omit-frame-pointer -O3 is recommended.
#
# PGI: -g -O3 -Meh_frame -Mframe is recommended. -Bdynamic is required to identify 
# OpenMP regions.
#
# GNU: -g -O3 -fno-inline is recommended. You might be lucky without -fno-inline,
# as it should produce enough information to unwind those calls. You will see
# my_function [inlined] in the MAP stack for functions that were inline.
# -fno-inline-functions appears with newer gnu compilers, just to confuse

# gnu
openmp_c: openmp.c
	${MPICC} -g -O3 -fopenmp -fno-inline openmp.c -o openmp_c -lm -lrt

openmp_f: openmp.f90
	${MPIF90} -g -O3 -fopenmp -fno-inline openmp.f90 -o openmp_f -lm -lrt
# intel
#	${MPICC}  -g -fno-inline -no-ip -no-ipo -fno-omit-frame-pointer -O3 -openmp openmp.c   -o openmp_c -lm -lrt
#	${MPIF90} -g -fno-inline -no-ip -no-ipo -fno-omit-frame-pointer -O3 -openmp openmp.f90 -o openmp_f -lm -lrt
# pgi
#	${MPICC}  -g -Bdynamic -Meh_frame -Mframe -O3 -mp openmp.c   -o openmp_c -lm -lrt
#	${MPIF90} -g -Bdynamic -Meh_frame -Mframe -O3 -mp openmp.f90 -o openmp_f -lm -lrt

# gnu

slow_openmp: slow_openmp.f90
	${MPIF90} -g -O3 -fno-inline -fopenmp slow_openmp.f90 -o slow_openmp -lm -lrt
# intel
#	${MPIF90} -g -fno-inline -no-ip -no-ipo -fno-omit-frame-pointer -O3 -openmp slow_openmp.f90 -o slow_openmp -lm -lrt
# pgi
#	${MPIF90} -g -Bdynamic -Meh_frame -Mframe -O3 -mp slow_openmp.f90 -o slow_openmp -lm -lrt

wave_openmp: wave_openmp.c
	${MPICC} -g -O0 -fno-inline -fopenmp wave_openmp.c -o wave_openmp -lm -lrt
# intel
#	${MPICC} -g -fno-inline -no-ip -no-ipo -fno-omit-frame-pointer -O3 -openmp wave_openmp.c -o wave_openmp -lm -lrt
# pgi
#	${MPICC} -g -Bdynamic -Meh_frame -Mframe -O3 -mp wave_openmp.c -o wave_openmp -lm -lrt

check:
	OMP_NUM_THREADS=4 ${MPIRUN} -np 4 ./openmp_f 3
	OMP_NUM_THREADS=4 ${MPIRUN} -np 4 ./openmp_c 3
	OMP_NUM_THREADS=4 ${MPIRUN} -np 4 ./slow_openmp
	OMP_NUM_THREADS=4 ${MPIRUN} -np 4 ./wave_openmp 3

clean:
	-rm -f ./openmp_f ./openmp_c ./slow_openmp ./wave_openmp

