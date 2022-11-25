
# Makefile voor Gametype
#
# Marc_G 2012

CC = g++
CFLAGS = -Wall
PROG = Gametype
SRC = games.cpp boardgame.cpp gametype_main.cpp
OBJS = games.o boardgame.o gametype_main.o

$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	/bin/rm -f $(OBJS)

depend:
	makedepend $(SRC)