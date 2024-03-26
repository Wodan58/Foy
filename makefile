#
#   module  : makefile
#   version : 1.2
#   date    : 03/23/24
#
.POSIX:
.SUFFIXES:

CC = gcc
CF = -O3 -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter
LF = -lm -lgc
CFLAGS = $(CF) -DCOMP="\"$(CF)\"" -DLINK="\"$(LF)\"" -DVERS="\"Release 1.0\""
HDRS = globals.h
OBJS = main.o scan.o symb.o read.o writ.o otab.o modl.o save.o arty.o prog.o \
       parm.o undf.o

joy:	prep $(OBJS)
	$(CC) -o$@ $(OBJS) $(LF)

$(OBJS): $(HDRS)

prep:
	sh prim.sh .
	sh tabl.sh .

clean:
	rm -f *.o

.SUFFIXES: .c .o

.c.o:
	$(CC) -o$@ $(CFLAGS) -c $<
