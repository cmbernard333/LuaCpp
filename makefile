LUAPATH := /Users/christian/Documents/Code/lua-5.2.3/src
CFLAGS := -Wall -Wextra -ansi -pedantic -I./include -I$(LUAPATH)
LDFL := -L$(LUAPATH)
LIBS := -llua
ARCH := $(shell uname -m)
OBJDIR := $(ARCH)-optim

# Compile all the objects
.cpp.o :  
	$(CC) $(CFLAGS) $(CPPFL) -c $*.cpp

# define objects
OBJmain = main.o

# build targets
all : build

build: main

main : $(OBJmain)
	$(CC) $(LDFLAGS) $(LDFL) -o $@ $(OBJmain) $(LIBS)

clean :
	rm -f *.o main
