import ctypes
import os

# Load the shared library
libpath = os.path.join(os.path.dirname(__file__), "build/librapl.so")
rapl = ctypes.CDLL(libpath)

# Define function signatures
rapl.get_epoch.restype = ctypes.c_long
rapl.get_timing.argtypes = [ctypes.c_long, ctypes.c_long]
rapl.get_timing.restype = ctypes.c_double
rapl.get_joules_rapl.restype = ctypes.c_double

# Python wrapper functions
def get_epoch():
    return rapl.get_epoch()

def get_timing(end_time, start_time):
    return rapl.get_timing(end_time, start_time)

def get_joules_rapl():
    return rapl.get_joules_rapl()
