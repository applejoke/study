CC = gcc
CFLAGS = -Wall -g
INCLUDE = -I include
SRC_DIR = code
BUILD_DIR = build
TARGET = test_hash

# 源文件
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/Hash.c

# 目标文件
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/Hash.o

# 默认目标
all: $(BUILD_DIR) $(TARGET)

# 创建构建目录
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 链接目标
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 编译 main.c
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c include/Hash.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# 编译 Hash.c
$(BUILD_DIR)/Hash.o: $(SRC_DIR)/Hash.c include/Hash.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# 运行程序
run: $(TARGET)
	./$(TARGET)

# 清理
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# 重新编译
rebuild: clean all

.PHONY: all run clean rebuild
