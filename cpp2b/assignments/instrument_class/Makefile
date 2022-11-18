
# Makefile voor Instrument
#
# Marc_G 2012

CC = g++
CFLAGS = -Wall
PROG = instrument
SRC = class_impl.cpp instr_main.cpp
OBJS = class_impl.o instr_main.o

$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	/bin/rm -f $(PROG) $(OBJS)

depend:
	makedepend $(SRC)