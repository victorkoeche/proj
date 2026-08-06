CC = gcc
CFLAGS = -Wall -Wextra -I include

SRC = src/main.c src/project.c src/filesystem_linux.c src/template.c src/commands.c
TARGET = proj

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

