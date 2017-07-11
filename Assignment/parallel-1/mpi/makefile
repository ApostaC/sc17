EXECS=send_recv
MPICC=mpicc

all: ${EXECS}

send_recv: send_recv.c
	${MPICC} send_recv.c -o send_recv

#clean here

clean:
	rm -f ${EXECS}
