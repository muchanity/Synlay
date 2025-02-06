CC = gcc
CFLAGS = -Wall -Wextra -I./include
LDFLAGS = 

SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin

# Finde alle .c Dateien
SRCS = $(wildcard $(SRC_DIR)/core/*.c) $(wildcard $(SRC_DIR)/modules/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TARGET = $(BIN_DIR)/synlay

# Hauptziel
all: $(TARGET)

# Linken der Objekt-Dateien
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Kompilieren der Quelldateien
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Aufräumen
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony Targets
.PHONY: all clean
