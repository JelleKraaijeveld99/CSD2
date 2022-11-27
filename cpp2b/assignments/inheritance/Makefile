
# Makefile voor inheritance 
#
# Marc_G 2012

CC = g++
CFLAGS = -Wall
PROG = inheritance
SRC = instrument.cpp keys.cpp woodwind.cpp strings.cpp inheritance_main.cpp 
OBJS = instrument.o keys.o woodwind.o strings.o inheritance_main.o 

$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	/bin/rm -f $(PROG) $(OBJS)

depend:
	makedepend $(SRC)