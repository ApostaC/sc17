#!/bin/sh
echo "Input the directory of Data folder :"
read dataDir
touch ./HPL.dat
for file in ${dataDir}/*; do
	echo "copy ${file} to ./HPL.dat"
	cp -f ${file} ./HPL.dat
	echo "starting xhpl"
	mpirun -np 2 ./xhpl
	echo "starting analysiser"
	read a
done
