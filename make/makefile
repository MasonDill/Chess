PROJECT_DIR = ..

# Include header files
INCLUDE_DIR := $(PROJECT_DIR)/include
INCLUDE_FLAGS := $(patsubst %,-I%,$(wildcard $(INCLUDE_DIR)/*))

# Debug flag (can be overridden via command line)
DEBUG ?= 0
ifeq ($(DEBUG),1)
    CXXFLAGS_DEBUG := -O0 -g
else
    CXXFLAGS_DEBUG := -O2
endif

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 $(CXXFLAGS_DEBUG) $(INCLUDE_FLAGS)

# Directories
SRC_DIRS = $(PROJECT_DIR)/src/game $(PROJECT_DIR)/src/core $(PROJECT_DIR)/src/pieces
BUILD_DIR = $(PROJECT_DIR)/build
BIN_DIR = $(PROJECT_DIR)/bin

# Source files and object files
SRCS = $(wildcard $(addsuffix /*.cpp,$(SRC_DIRS)))
OBJS = $(SRCS:$(PROJECT_DIR)/src/%.cpp=$(BUILD_DIR)/%.o)

# Main target
TARGET = $(BIN_DIR)/chess

# Default target
prerequisites: create_dirs all
all: $(BUILD_DIR) create_obj_dirs $(TARGET)

create_dirs:
	if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	
# Create build directory and subdirectories
create_obj_dirs:
	@if not exist "$(BUILD_DIR)\game" mkdir "$(BUILD_DIR)\game"
	@if not exist "$(BUILD_DIR)\core" mkdir "$(BUILD_DIR)\core"
	@if not exist "$(BUILD_DIR)\pieces" mkdir "$(BUILD_DIR)\pieces"

# Link the target executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile source files
$(BUILD_DIR)/%.o: $(PROJECT_DIR)/src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	$(RM) -r $(BUILD_DIR) $(TARGET)

.PHONY: all clean create_obj_dirs
