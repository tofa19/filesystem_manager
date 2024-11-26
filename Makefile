CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/file_operations.c src/directory_operations.c
OBJ = $(SRC:.c=.o)
EXEC = filesystem_manager

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)