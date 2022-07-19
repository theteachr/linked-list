CC      = clang
CFLAGS  = -Wall -Werror -g

SRC     = $(wildcard src/*.c)
OBJ     = $(SRC:.c=.o)
TARGET  = bin/main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

test: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJ) $(TARGET)

.PHONY: clean test
