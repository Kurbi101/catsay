#!/bin/bash

CFLAGS="-Wall -Wextra -pedantic -Wunreachable-code"
file="catsay.c"

gcc -std=c99 $CFLAGS -o "${file%.c}" "$file" 
echo "Build completed."