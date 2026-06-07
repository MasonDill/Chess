PROJECT_DIR = ..

# Host OS detection -> platform-specific shell commands
ifeq ($(OS),Windows_NT)
    # Windows (cmd.exe): convert forward slashes to backslashes for mkdir/rmdir
    MKDIR = if not exist "$(subst /,\,$1)" mkdir "$(subst /,\,$1)"
    RMDIR = if exist "$(subst /,\,$1)" rmdir /s /q "$(subst /,\,$1)"
else
    # POSIX (macOS, Linux)
    MKDIR = mkdir -p "$1"
    RMDIR = rm -rf "$1"
endif

# Include header files
INCLUDE_DIR := $(PROJECT_DIR)/include
INCLUDE_FLAGS := $(patsubst %,-I%,$(wildcard $(INCLUDE_DIR)/*))

# Debug flag (can be overridden via command line)
DBG ?= 0
ifeq ($(DBG),0)
    CXXFLAGS_DEBUG := -O0 -g
else
    CXXFLAGS_DEBUG := -O0 -g
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
	$(call MKDIR,$(BUILD_DIR))
	$(call MKDIR,$(BIN_DIR))

# Create build directory and subdirectories
create_obj_dirs:
	@$(call MKDIR,$(BUILD_DIR)/game)
	@$(call MKDIR,$(BUILD_DIR)/core)
	@$(call MKDIR,$(BUILD_DIR)/pieces)

# Link the target executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile source files
$(BUILD_DIR)/%.o: $(PROJECT_DIR)/src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	$(call RMDIR,$(BUILD_DIR))
	$(call RMDIR,$(BIN_DIR))

.PHONY: all clean create_obj_dirs
