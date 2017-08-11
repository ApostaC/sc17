MPICC=mpicc
MPIF77=mpif77
MPIF90=mpif90

all: hello_c hello_f hello_f90

hello_c: hello.c
	${MPICC} -g -O0 hello.c -o hello_c

hello_f: hello.f
	${MPIF77} -g -O0 hello.f -o hello_f

hello_f90: hello.f90
	${MPIF90} -g -O0 hello.f90 -o hello_f90

clean:
	-rm -f hello_c hello_f hello_f90
