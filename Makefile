CC = g++
CFLAGS = -Wall -I. -g
SUB_DIRS = analyser filemanager compiler parser
BUILD_DIR = build
TARGET = ts-transpiler

.PHONY: all clean $(SUB_DIRS)

all: $(SUB_DIRS) $(BUILD_DIR)/main.o
	$(CC) $(CFLAGS) -o $(TARGET) \
	$(BUILD_DIR)/main.o \
	$(BUILD_DIR)/analyser/*.o \
	$(BUILD_DIR)/filemanager/*.o \
	$(BUILD_DIR)/compiler/*.o \
	$(BUILD_DIR)/parser/*.o

$(SUB_DIRS):
	$(MAKE) -C $@

$(BUILD_DIR)/main.o: main.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	for dir in $(SUB_DIRS); do \
		$(MAKE) -C $$dir clean; \
	done
