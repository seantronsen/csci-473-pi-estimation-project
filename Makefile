CC=gcc
CFLAGS=-g -Wall -Wstrict-prototypes -std=gnu99 -fopenmp
LFLAGS=-lm -fopenmp

all: pi_serial pi_parallel

# EXECUTABLES
pi_serial: pi_serial.o
	$(CC) $(LFLAGS) -o pi_serial ./pi_serial.o
pi_parallel: pi_parallel.o
	$(CC) $(LFLAGS) -o pi_parallel ./pi_parallel.o

# BASE EXECUTABLES - OBJECT FILES
pi_serial.o: pi_serial.c
	$(CC) $(CFLAGS) -c ./pi_serial.c
pi_parallel.o: pi_parallel.c
	$(CC) $(CFLAGS) -c ./pi_parallel.c

# MISC COMMANDS
clean:
	rm -f *.o core* *.h.gch *.out pi_serial pi_parallel