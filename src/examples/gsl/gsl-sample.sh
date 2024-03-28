#!/bin/bash
gcc -Wall -c gsl-sample.c
gcc -Wall gsl-sample.o -lgsl -lgslcblas -lm -o gsl-sample
./gsl-sample