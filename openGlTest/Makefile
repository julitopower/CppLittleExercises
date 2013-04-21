# My First TDD example
TST = $(wildcard tst/*.cpp)
SRCS = $(wildcard src/*.cpp)
# Headers
HDRS = $(wildcard src/*.hpp) 
# Project Name
PROJ = OpenGlTest


CC = g++
OBJS = $(SRCS:.cpp=.o)
APP = $(PROJ).exe
CFLAGS = -c -g -Wall
ifeq (,$(findstring CYGWIN,$(shell uname)))
  LDFLAGS = -L/opt/local/lib
else
  LDFLAGS = -L/opt/local/lib -enable-auto-import
endif
LIBS = -lcppunit -ldl -lGL -lGLU -lglut

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
