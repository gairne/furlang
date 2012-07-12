CFLAGS = -Wall -pedantic

all: furlang

furlang: interpreter.o opcodes.o
	$(CC) $(CFLAGS) -Wall $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o *~ furlang

.c.o:
	$(CC) $(CFLAGS) -c $<
