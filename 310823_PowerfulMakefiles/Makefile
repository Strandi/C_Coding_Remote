CC = gcc
CFLAGS = -Wall

BINARY = maketest

CFILES = main.c plus.c plums.c
OBJECTS = main.o plus.o plums.o



all: clean $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
	./$(BINARY)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)

