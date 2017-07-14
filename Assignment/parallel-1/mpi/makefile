EXECS=send_recv MatrixVectorMul
MPICC=mpicc
MPICPP=mpic++

all: ${EXECS}

send_recv: send_recv.c
	${MPICC} send_recv.c -o send_recv

MatrixVectorMul: MatrixVectorMul.cpp
	${MPICPP} MatrixVectorMul.cpp -o MatrixVectorMul

#clean here

clean:
	rm -f ${EXECS}
