#!/bin/bash
gcc -Wall -c myio.c
gcc -Wall -c example1.c
gcc -Wall example1.o -lgsl -lgslcblas -lm -lglobes myio.o -o example1
./example1
