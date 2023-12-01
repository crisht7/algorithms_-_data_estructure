#!/bin/bash

make

./a.out < entrada.in > salidaActual.out

meld salidaActual.out salidaEsperada.out

time ./a.out < entrada.in