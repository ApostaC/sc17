EXECS=send_recv MatrixVectorMul MatrixVectorMul2
MPICC=mpicc
MPICPP=mpic++

#for all obj
all: ${EXECS}

#for send_recv
send_recv: send_recv.c
	${MPICC} send_recv.c -o send_recv

#for MatrixVectorMul
MatrixVectorMul: MatrixVectorMul.cpp
	${MPICPP} MatrixVectorMul.cpp -o MatrixVectorMul

#for MatrixVectorMul2
MatrixVectorMul2: MatrixVectorMul2.cpp
	${MPICPP} MatrixVectorMul2.cpp -o MatrixVectorMul2 

#clean here
clean:
	rm -f ${EXECS}

#help
help:
	@echo "type 'make <option>'"
	@echo "<option> can be 'all' 'send_recv' 'MatrixVectorMul' 'clean'"
