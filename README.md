# Python bindings for RAPL

Capture RAPL energy on Intel CPUs in Python.

## Build shared library

Build the rapl.cpp code as shared library using the provided Makefile. This will create a `librapl.so` file.
```
# clone repository
cd pyrapl
make all
```

## Import python package

In your python code:
```
import pyrapl

energy_start = pyrapl.get_joules_rapl()
C = matmul(A, B)
energy_end = pyrapl.get_joules_rapl()

total_energy = energy_end - energy_start
print(total_energy)
```
