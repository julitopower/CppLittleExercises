import ctypes
import atexit
import signal

print("HEY")

def f(signum, frame):
    with open("Called.txt") as f:
        f.write("Called indeed")
    print("######Exit handler in python land\n")


def other(*args):
    print("Hi there ")

LIB = ctypes.CDLL("./libl1.so")
LIB.register_signal_handlers()

signal.signal(signal.SIGABRT, other)

LIB2 = ctypes.CDLL("./libl2.so")
LIB2.generate_terminate()



