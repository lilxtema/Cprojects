CC = gcc
CFLAGS = -Wall -Wextra -std=c11
BUILD_DIR = ../build

# Список подпроектов
PROGRAMS = queue queue_in_coffeshop stack_calculator

all: $(PROGRAMS)

queue:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -Iqueue/queue_list -o $(BUILD_DIR)/queue queue/main.c queue/queue_list/queue.c

queue_in_coffeshop:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -Iqueue_in_coffeshop/customer_queue -o $(BUILD_DIR)/queue_in_coffeshop queue_in_coffeshop/main.c queue_in_coffeshop/customer_queue/customer_queue.c

stack_calculator:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -Istack_calculator/stack -o $(BUILD_DIR)/stack_calculator stack_calculator/main.c stack_calculator/stack/stack.c

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all

.PHONY: all clean $(PROGRAMS)