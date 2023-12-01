#!/bin/bash

make

time ./a.out < entrada.in > salidaActual.out

meld salidaActual.out salidaEsperada.out