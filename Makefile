# create the executable for calc_lvalues
all: lab2

lab2: main.c
	gcc -O3 -std=c11 -Wall main.c transformMat_lab2.o -lrt -fopenmp -o main

clean:
	rm -f main
