F90=gfortran
CC=gcc

all: serial_c serial_static_c serial_f serial_static_f
# Flags for compiler inlining: MAP works whether inlining is on or off,
# but you'll typically see more intuitive stacks with it turned off.
# The major compilers are discussed here:
#
# Intel: -g -fno-inline -no-ip -no-ipo -O3 is recommended. At O3 the compiler doesn't
# produce enough unwind info even with -debug inline-debug-info set.
#
# PGI: -g -O3 -Meh_frame is recommended. Other settings dont produce enough
# unwind information for inlined functions otherwise. This adds some
# performance penalty - around 8% is typical.
#
# GNU: -g -O3 -fno-inline is recommended. You might be lucky without -fno-inline,
# as it should produce enough information to unwind those calls. You will see
# my_function [inlined] in the MAP stack for functions that were inline.
# -fno-inline-functions appears with newer gnu compilers, just to confuse
#
# gnu
allinea-profiler.ld:
	@if [ -f ../bin/make-profiler-libraries ]; then ../bin/make-profiler-libraries --lib-type=static; else make-profiler-libraries --lib-type=static; fi > /dev/null

serial_c: serial.c
	${CC}  -g -O3 -fno-inline serial.c -o serial_c -lm -lrt

serial_static_c: serial.c allinea-profiler.ld
	${CC}  -g -O3 -fno-inline serial.c -o serial_static_c -Wl,@allinea-profiler.ld

serial_f: serial.f90
	${F90} -g -O3 -fno-inline serial.f90 -o serial_f -lm -lrt

serial_static_f: serial.f90 allinea-profiler.ld
	${F90} -g -O3 -fno-inline serial.f90 -o serial_static_f -Wl,@allinea-profiler.ld

# intel
#	${MPIF90} -g -fno-inline -no-ip -no-ipo -O3 serial.f90 -o serial_f -lm -lrt
# pgi
#	${MPIF90} -g -Meh_frame -O3 serial.f90 -o serial_f -lm -lrt

check:
	./serial_f

clean:
	-rm -f ./serial_f
	-rm -f ./serial_c
	-rm -f ./serial_static_c
	-rm -f ./serial_static_f
	-rm -f allinea-profiler.ld libmap-sampler.a libmap-sampler-pmpi.a
