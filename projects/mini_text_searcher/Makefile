CC = gcc
CFLAGS = -Wall -Wextra -std=c11
BUILD_DIR = ../build

TARGET = ../build/mini_text_searcher
SRC = main.c file_searcher/searcher.c

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p ../build
	$(CC) $(CFLAGS) -o $(BUILD)$@ $^

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all

.PHONY: all clean $(PROGRAMS)