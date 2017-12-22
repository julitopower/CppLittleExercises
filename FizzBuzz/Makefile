# My First TDD example
TST = $(wildcard tst/*.cpp)
SRCS = $(wildcard src/*.cpp)
# Headers
HDRS = $(wildcard src/*.hpp) 
# Project Name
PROJ = fizzbuzz

# Remaining lines shouldn't need changing
# Here's what they do:
#   - rebuild if any header file changes
#   - include CppUnit as dynamic library
#   - search /opt/local for MacPorts
#   - generate .exe files for Windows
#   - add -enable-auto-import flag for Cygwin only

CC = g++
OBJS = $(SRCS:.cpp=.o)
APP = $(PROJ).exe
CFLAGS = -c -g -Wall
ifeq (,$(findstring CYGWIN,$(shell uname)))
  LDFLAGS = -L/opt/local/lib
else
  LDFLAGS = -L/opt/local/lib -enable-auto-import
endif
LIBS = -lcppunit -ldl

all: clean $(APP)
	./$(APP)
$(APP): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(APP) $(LIBS)

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f src/*.o tst/*.o *.exe

test:	clean
	make -f MakeTest all_t