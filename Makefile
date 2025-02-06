CC = gcc
CFLAGS = -Wall -Wextra -pedantic -Iinclude
LDFLAGS = -lm -lncurses

SRC_DIR = src
MODULE_DIR = src/modules
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(MODULE_DIR)/*.c)
OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SOURCES))

TARGET = synlay

.PHONY: all clean install

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

install: $(TARGET)
	install -m 0755 $(TARGET) /usr/local/bin
	install -m 0644 synlay.conf /etc/synlay.conf