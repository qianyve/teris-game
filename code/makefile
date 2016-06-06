CC=g++
CFLAGS=-Wall -std=c++11
PROG=teris
OBJS=teris.o Win.o Figure.o Block.o

LIBS=-lglut -lGLU -lGL

all:$(PROG)

$(PROG):$(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LIBS)

teris.o:teris.cpp
	$(CC) $(CFLAGS) -c teris.cpp

Win.o:Win.cpp
	$(CC) $(CFLAGS) -c Win.cpp

Figure.o:Figure.cpp
	$(CC) $(CFLAGS) -c Figure.cpp

Block.o:Block.cpp
	$(CC) $(CFLAGS) -c Block.cpp

clear:
	rm -f $(PROG) $(OBJS)
