CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
TARGET = ../build/product_app
TEST_TARGET = ../build/product_tests

SRC = main.c tests/test.c products/product.c
TEST_SRC = main.c tests/test.c products/product.c

all: $(TARGET) 

$(TARGET): $(SRC)
	@mkdir -p ../build
	$(CC) $(CFLAGS) -o $(BUILD)$@ $^

$(TEST_TARGET): $(TEST_SRC)
	@mkdir -p ../build
	$(CC) $(CFLAGS) -o $@ $^

# Запуск всех тестов
test: $(TEST_TARGET)
	@mkdir -p ../build
	./$(TEST_TARGET) all

# Запуск только теста сортировки
test_sorting: $(TEST_TARGET)
	@mkdir -p ../build
	./$(TEST_TARGET) sorting

# Запуск только теста поиска
test_search: $(TEST_TARGET)
	@mkdir -p ../build
	./$(TEST_TARGET) search

# Запуск только теста сортировки стран по кол-ву товаров
test_country_products_sort: $(TEST_TARGET)
	@mkdir -p ../build
	./$(TEST_TARGET) country

test_country_unique_products_sort: $(TEST_TARGET)
	@mkdir -p ../build
	./$(TEST_TARGET) unique_country

run: $(TARGET)
	@mkdir -p ../build
	./$(TARGET)

rebuild: clean all

clean:
	rm -rf ../build

.PHONY: all test test-sorting test-search run clean