# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I. -I../../src -I.. # Includes src and parent directory for doctest.h

# Directories
SRC_DIR = ../../src
TEST_DIR = .
BUILD_DIR = ./build

# Source files
SRC_FILES := $(SRC_DIR)/Citizen.cpp $(SRC_DIR)/Building.cpp $(SRC_DIR)/Residential.cpp
TEST_FILES := $(TEST_DIR)/CitizenUnitTests.cpp
OBJS := $(SRC_FILES:.cpp=.o) $(TEST_FILES:.cpp=.o)

# Target executable
TARGET = CitizenUnitTests

# Main rule
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile sources and tests
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
test: $(TARGET)
	./$(TARGET)

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(BUILD_DIR)

# PHONY targets
.PHONY: all clean test
