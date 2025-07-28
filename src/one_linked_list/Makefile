CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_DIR = build
TARGET = build/OneLinkedList
SRC = main.c test/test.c OneLinkedList/OneLinkedList.c

all: $(TARGET) 

$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
	./$(TARGET)

push_back_front: $(TARGET)
	@mkdir -p $(BUILD_DIR)
	./$(TARGET) push_back_front

insert_erase: $(TARGET)
	@mkdir -p $(BUILD_DIR)
	./$(TARGET) insert_erase

sort: $(TARGET)
	@mkdir -p $(BUILD_DIR)
	./$(TARGET) sort

merge: $(TARGET)
	@mkdir -p $(BUILD_DIR)
	./$(TARGET) merge

reverse: $(TARGET)
	@mkdir -p $(BUILD_DIR)
	./$(TARGET) reverse

rebuild: clean all

clean:
	rm -rf build

.PHONY: all test test-sorting test-search run clean