# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O0 -g

# Directories
SRC_DIR = ../src/
BUILD_DIR = build

# Source files and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Main target
TARGET = main

# Default target
all: $(BUILD_DIR) $(TARGET)

# Create build directory
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

# Link the target executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	$(RM) -r $(BUILD_DIR) $(TARGET)

.PHONY: all clean
