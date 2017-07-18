EXECS=send_recv MatrixVectorMul
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

#clean here
clean:
	rm -f ${EXECS}

#help
help:
	@echo "type 'make <option>'"
	@echo "<option> can be 'all' 'send_recv' 'MatrixVectorMul' 'clean'"
