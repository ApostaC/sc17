#!/bin/sh

getData(){
	echo "Input the directory of Data folder :"
	read dataDir
	touch ./HPL.dat
	for file in ${dataDir}/*; do
		echo "COPY ${file} to ./HPL.dat"
		cp -f ${file} ./HPL.dat
		echo "starting xhpl"
		mpirun -np 2 ./xhpl
	done
}

analysis(){
	echo "starting analysiser..."
	for file in ./out/*; do
		echo "ANAL ${file}"
		./analysiser ${file}
	done
}

#getData
analysis
