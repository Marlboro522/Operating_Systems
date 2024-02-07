CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SOURCE = list.c list_test.c
TARGER = list_test

all: $(TARGER)

$(TARGER): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGER)

run: $(TARGER)
	./$(TARGER)

clean:
	rm -f $(TARGER)

.PHONY: all run clean

.DEFAULT_GOAL := run
