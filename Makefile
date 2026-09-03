CC = gcc

CFLAGS = -Wall -Wextra -I include

SRC = src/main.c src/project.c src/filesystem_linux.c src/template.c src/commands.c

TARGET = proj

PREFIX = $(HOME)/.local
DATADIR = $(PREFIX)/share/proj

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

install: $(TARGET)
	mkdir -p $(PREFIX)/bin
	mkdir -p $(DATADIR)/templates
	cp $(TARGET) $(PREFIX)/bin/$(TARGET)
	cp -r templates/* $(DATADIR)/templates/

uninstall:
	rm -f $(PREFIX)/bin/$(TARGET)
	rm -rf $(DATADIR)

clean:
	rm -f $(TARGET)

