CC ?= gcc
CFLAGS ?= -Wall -Wextra -Wpedantic -O2
CPPFLAGS = -Iinclude

SRC_DIR = src
BUILD_DIR = build
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

TARGET = proj

PREFIX ?= $(HOME)/.local
BINDIR = $(PREFIX)/bin
DATADIR = $(PREFIX)/share/proj

.PHONY: all clean install uninstall

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

install: $(TARGET)
	install -d $(BINDIR)
	install -m 755 $(TARGET) $(BINDIR)/$(TARGET)
	install -d $(DATADIR)/templates
	cp -r templates/* $(DATADIR)/templates/

uninstall:
	rm -f $(BINDIR)/$(TARGET)
	rm -rf $(DATADIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

