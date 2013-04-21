# Location of test files
TST = $(wildcard tst/*.cpp)

# Location of source files
SRCS = $(wildcard src/*.cpp)

# Headers for sources
HDRS = $(wildcard src/*.hpp)

# Project Name
PROJ = TemplateProject

# Compiler
CC = g++

# Expand the contents of source and change the cpp with an o
OBJS = $(SRCS:.cpp=.o)

# Name of the application
APP = $(PROJ).exe

# Compiler flags, warning optmizations, etc...
CFLAGS = -c -g -Wall

ifeq (,$(findstring CYGWIN,$(shell uname)))
  LDFLAGS = -L/opt/local/lib
else
  LDFLAGS = -L/opt/local/lib -enable-auto-import
endif

# Libraries to link with
LIBS = -lcppunit -ldl -lGL -lGLU -lglut

all: clean $(APP)
	./$(APP)
$(APP): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(APP) $(LIBS)

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) $< -o $@ -std=c++0x

clean:
	rm -f src/*.o tst/*.o *.exe

test:	clean
	make -f MakeTest all_t
