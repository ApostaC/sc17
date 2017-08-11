# Make all example programs (except prefix if nvcc is not present and kmeans if upcc is not present)
all:
	make -f count.makefile
	make -f fruit.makefile
	make -f hello.makefile
	make -f heightmap.makefile
	make -f matrix_mult.makefile
	make -f memdebug.makefile
	make -f openmp.makefile
	make -f ring.makefile
	make -f seqtest.makefile
	make -f serial.makefile
	make -f simple.makefile
	make -f slow.makefile
	make -f stl_example.makefile
	make -f stl_example2.makefile
	make -f stl_example3.makefile
	make -f threaded.makefile
	make -f wave.makefile
	(which nvcc >/dev/null 2>/dev/null && make -f prefix.makefile) || echo "Skipping NVIDIA CUDA example (no nvcc in PATH)"; true
	(which upcc >/dev/null 2>/dev/null && make -f kmeans.makefile) || echo "Skipping UPC Example (no upcc in PATH)"; true

clean:
	make -f count.makefile clean
	make -f fruit.makefile clean
	make -f hello.makefile clean
	make -f heightmap.makefile clean
	make -f matrix_mult.makefile clean
	make -f memdebug.makefile clean
	make -f openmp.makefile clean
	make -f ring.makefile clean
	make -f seqtest.makefile clean
	make -f serial.makefile clean
	make -f simple.makefile clean
	make -f slow.makefile clean
	make -f stl_example.makefile clean
	make -f stl_example2.makefile clean
	make -f stl_example3.makefile clean
	make -f threaded.makefile clean
	make -f wave.makefile clean
	make -f prefix.makefile clean
	make -f kmeans.makefile clean
