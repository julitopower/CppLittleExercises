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
# See: https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_6.html#SEC61
OBJS = $(SRCS:.cpp=.o)
APP = $(PROJ)
CFLAGS = -c -g -Wall
ifeq (,$(findstring CYGWIN,$(shell uname)))
  LDFLAGS = -L/opt/local/lib
else
  APP = $(PROJ).exe
  LDFLAGS = -L/opt/local/lib -enable-auto-import
endif
LIBS = -lcppunit -ldl

all: clean $(APP)
	./$(APP)

$(APP): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(APP) $(LIBS)

# See https://www.gnu.org/software/make/manual/html_node/Pattern-Rules.html
%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean # Execute unconditionally
clean:
	rm -f src/*.o tst/*.o *.exe

.PHONY: test # Execute unconditionally
test: clean
	make -f MakeTest all_t
