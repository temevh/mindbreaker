CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11 -Iinclude -Iexternal

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Executable name
TARGET = $(BIN_DIR)/mindbreaker

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJ_FILES) -o $(TARGET)

# Compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the program (ensure correct working directory for JSON file access)
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
