
# Makefile voor Game
#
# Marc_G 2012

CC = g++
CFLAGS = -Wall
PROG = Game
SRC = console.cpp headset.cpp controller.cpp game_main.cpp
OBJS = console.o headset.o controller.o game_main.o 

$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	/bin/rm -f $(PROG) $(OBJS)

depend:
	makedepend $(SRC)