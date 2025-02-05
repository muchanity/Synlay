CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include
LDFLAGS =

# Verzeichnisse
SRC_DIR = src
OBJ_DIR = obj
MODULES_DIR = $(SRC_DIR)/modules
DISPLAY_DIR = $(SRC_DIR)/display

# Quelldateien
SRCS = $(SRC_DIR)/main.c \
       $(DISPLAY_DIR)/screen.c \
       $(MODULES_DIR)/system.c \
       $(MODULES_DIR)/network.c \
       $(MODULES_DIR)/temps.c \
       $(MODULES_DIR)/storage.c

# Objektdateien
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Zielname
TARGET = mscad

# Standard-Build-Ziel
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Kompilieren von Quelldateien
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/modules
	@mkdir -p $(OBJ_DIR)/display
	$(CC) $(CFLAGS) -c $< -o $@

# Clean-Target
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Install-Target
install: $(TARGET)
	mkdir -p /usr/local/bin
	cp $(TARGET) /usr/local/bin/
	mkdir -p /etc/mscad/configs
	cp configs/* /etc/mscad/configs/

# Uninstall-Target
uninstall:
	rm -f /usr/local/bin/$(TARGET)
	rm -rf /etc/mscad

# Entwickler-Targets
debug: CFLAGS += -g
debug: $(TARGET)

.PHONY: all clean install uninstall debug
