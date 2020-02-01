OBJ=bitcoup.o

CC=gcc

CFLAGS=-c -Wall -O2

LDFLAGS=-L. -lcoupon -lgsl -lgslcblas -lm

bitcoup:				$(OBJ) libcoupon.a
		$(CC) -Wall -O2 $(OBJ) -o bitcoup $(LDFLAGS)

bitcoup.o:			bitcoup.c
		$(CC) $(CFLAGS) bitcoup.c

clean:
		rm -f $(OBJ) bitcoup
