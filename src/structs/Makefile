CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
TARGET = ../build/product_app
TEST_TARGET = ../build/product_tests

SRC = main.c tests/test.c products/product.c
TEST_SRC = main.c tests/test.c products/product.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(BUILD)$@ $^

$(TEST_TARGET): $(TEST_SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Запуск всех тестов
test: $(TEST_TARGET)
	./$(TEST_TARGET) all

# Запуск только теста сортировки
test_sorting: $(TEST_TARGET)
	./$(TEST_TARGET) sorting

# Запуск только теста поиска
test_search: $(TEST_TARGET)
	./$(TEST_TARGET) search

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all test test-sorting test-search run clean