CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = queue_list/result_queue
BUILD = ../../build

SRC = main.c queue_list/queue.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(BUILD)/result_queue $^

clean:
	rm -f $(BUILD)/result_queue
