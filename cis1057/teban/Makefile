# Makefile for Teban project
# Simple build system for object-oriented C game engine

<<<<<<< Updated upstream
# Detect OS for cross-platform commands
ifeq ($(OS),Windows_NT)
    MKDIR = if not exist "$@" mkdir "$@"
    RMDIR = if exist "$(1)" rmdir /s /q "$(1)" 2>nul || echo.
    RM = del /q
    EXE = .exe
else
    MKDIR = mkdir -p $@
    RMDIR = rm -rf $(1)
    RM = rm -f
    EXE =
endif

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g

# Directories
SRC_DIR = src
TEST_DIR = test
OBJ_DIR = obj
BIN_DIR = bin
COMMON_DIR = ../common
TARGET = teban

# Source files
MAIN_SRC = $(SRC_DIR)/main.c
ALLOCATOR_SRCS = $(wildcard $(COMMON_DIR)/allocator/$(SRC_DIR)/*.c)
SRCS = $(MAIN_SRC) $(ALLOCATOR_SRCS)

# Object files
MAIN_OBJ = $(OBJ_DIR)/main.o
ALLOCATOR_OBJS = $(patsubst $(COMMON_DIR)/allocator/$(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(ALLOCATOR_SRCS))
OBJS = $(MAIN_OBJ) $(ALLOCATOR_OBJS)

# Header dependencies
INCLUDES = -Iinclude -I$(COMMON_DIR)/allocator/include

# Default target
all: $(TARGET)

# Create build directory if it doesn't exist
$(OBJ_DIR) $(BIN_DIR):
	$(MKDIR)

# Link the final executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)


# Compile source files to objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile allocator source files
$(OBJ_DIR)/%.o: $(COMMON_DIR)/allocator/$(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	$(call RMDIR,$(OBJ_DIR))
	$(call RMDIR,$(BIN_DIR))

# Rebuild everything
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug with gdb
debug: $(TARGET)
	gdb ./$(TARGET)

# Show variables (for debugging Makefile)
info:
	@echo "SRC_DIR: $(SRC_DIR)"
	@echo "COMMON_DIR: $(COMMON_DIR)"
	@echo "OBJ_DIR: $(OBJ_DIR)"
	@echo "BIN_DIR: $(BIN_DIR)"
	@echo "MAIN_SRC: $(MAIN_SRC)"
	@echo "ALLOCATOR_SRCS: $(ALLOCATOR_SRCS)"
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"
	@echo "INCLUDES: $(INCLUDES)"

# Phony targets
.PHONY: all clean rebuild run debug info
=======
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g
INCLUDES = -Iinclude

# Source and object directories
SRCDIR = src
TESTDIR = test
OBJDIR = obj
BINDIR = bin

# Source files (only Allocator for now)
SOURCES = $(SRCDIR)/Allocator.c
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Test files
TEST_SOURCES = $(wildcard $(TESTDIR)/*.c)
TEST_BINARIES = $(TEST_SOURCES:$(TESTDIR)/%.c=$(BINDIR)/%)

# Default target
all: $(TEST_BINARIES)

# Create directories
$(OBJDIR) $(BINDIR):
	mkdir -p $@

# Compile source files to objects
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build test executables
$(BINDIR)/%: $(TESTDIR)/%.c $(OBJECTS) | $(BINDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< $(OBJECTS) -o $@

# Run specific tests
test-allocator: $(BINDIR)/test_allocator
	./$(BINDIR)/test_allocator

# Run all tests
test: $(TEST_BINARIES)
	@for test in $(TEST_BINARIES); do \
		echo "Running $$test..."; \
		./$$test; \
		echo; \
	done

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Phony targets
.PHONY: all test test-allocator clean

# Dependencies
$(BINDIR)/test_allocator: $(OBJDIR)/Allocator.o
>>>>>>> Stashed changes
