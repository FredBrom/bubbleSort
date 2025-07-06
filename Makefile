 # === Configs ===

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -MMD -MP 
LDFLAGS = -lprintVector
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib
TEST_DIR = test

# === source Files and Obj ===

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEP_FILES := $(OBJ_FILES:.o=.d)

# === Tests ===

TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_BINS := $(patsubst $(TEST_DIR)/%.c,$(BIN_DIR)/%,$(TEST_SRC))

# === Main file ===

#MAIN_EXEC = $(BIN_DIR)/main

# === Rules ===

.PHONY: all clean test run make_dirs

all: make_dirs $(OBJ_FILES) $(TEST_BINS)

# compile .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -L$(LIB_DIR) -c $< -o $@

# compile test
$(BIN_DIR)/%: $(TEST_DIR)/%.c $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCLUDE_DIR) -L$(LIB_DIR) $(OBJ_FILES) $< -o $@

# main exex
$(MAIN_EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -L$(LIB_DIR) -I$(INCLUDE_DIR) -o $@ $^

# run tests
test: make_dirs $(OBJ_FILES) $(TEST_BINS)
	@echo "Running tests..."
	@for bin in $(TEST_BINS); do \
		echo "==> $$bin"; \
		./$$bin; \
		echo ""; \
	done

# main execution
run: $(MAIN_EXEC)
	./$(MAIN_EXEC)

# make dirs
make_dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

# clean all
clean:
	rm -rf $(OBJ_FILES) $(TEST_BINS) $(DEP_FILES) $(BIN_DIR)/*

# Dependece files .d
-include $(DEP_FILES)
