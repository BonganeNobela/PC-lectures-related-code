#!/bin/bash

# Add Microsoft MPI to PATH for this session
export PATH="/c/Program Files/Microsoft MPI/Bin:$PATH"

# Compile the program
gcc -I"/c/Program Files/Microsoft MPI/Inc" round-robin-basic.c -o round-robin-basic.exe -L"/c/Program Files/Microsoft MPI/Lib/x64" -lmsmpi

# Run the program with 4 processes
mpiexec -n 4 ./round-robin-basic.exe