#!/bin/bash
echo 'INPUT SIZE PLEASE(less than 1,000,000)'
read SIZE
time mpirun -np 2 ./send_recv ${SIZE}
