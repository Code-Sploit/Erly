#!/bin/bash

C_SOURCES=`find ./ -name "*.c"`

mkdir -p build

for c_file in $C_SOURCES
do
    gcc -c -O3 -Wall -I. -D DEBUG $c_file -o ./build/$c_file.o
done

OBJECTS=`find ./build -name "*.c.o"`
gcc $OBJECTS -o ./erly