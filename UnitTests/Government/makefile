# Directories
SRC_DIR := ../../src
TEST_DIR := .
BIN_DIR := bin

# Source files
SRC_FILES := \
    $(SRC_DIR)/Citizen.cpp \
    $(SRC_DIR)/EmploymentStatus.cpp \
    $(SRC_DIR)/Satisfied.cpp \
    $(SRC_DIR)/Unsatisfied.cpp \
    $(SRC_DIR)/OfficeJob.cpp \
    $(SRC_DIR)/IndustrialJob.cpp \
    $(SRC_DIR)/Unemployed.cpp \
    $(SRC_DIR)/TaxBracket.cpp \
    $(SRC_DIR)/LowestTaxBracket.cpp \
    $(SRC_DIR)/MiddleTaxBracket.cpp \
    $(SRC_DIR)/HighestTaxBracket.cpp \
    $(SRC_DIR)/Government.cpp \
    $(SRC_DIR)/Building.cpp \
    $(SRC_DIR)/BuildingFactory.cpp \
    $(SRC_DIR)/Underconstruction.cpp \
    $(SRC_DIR)/Built.cpp \
    $(SRC_DIR)/Destroyed.cpp \
    $(SRC_DIR)/Residential.cpp \
    $(SRC_DIR)/Commercial.cpp \
    $(SRC_DIR)/Industrial.cpp \
    $(SRC_DIR)/Landmark.cpp \
    $(SRC_DIR)/ResidentialFactory.cpp \
    $(SRC_DIR)/CommercialFactory.cpp \
    $(SRC_DIR)/IndustrialFactory.cpp \
    $(SRC_DIR)/LandmarkFactory.cpp \
    $(SRC_DIR)/Emergencies.cpp \
    $(SRC_DIR)/Fires.cpp \
    $(SRC_DIR)/Earthquake.cpp \
    $(SRC_DIR)/Thieves.cpp \
    $(SRC_DIR)/CityGrowthObserver.cpp \
    $(SRC_DIR)/CategorizationStrategy.cpp \
    $(SRC_DIR)/EconomyCategorization.cpp \
    $(SRC_DIR)/PopulationCategorization.cpp \
    $(SRC_DIR)/Population.cpp \
    $(SRC_DIR)/PopulationGrowth.cpp \
    $(SRC_DIR)/Infrastructure.cpp \
    $(SRC_DIR)/Housing.cpp \
    $(SRC_DIR)/Economy.cpp

# Test files
TEST_FILES := $(TEST_DIR)/GovernmentUnitTests.cpp

# Object files
OBJ_FILES := $(SRC_FILES:.cpp=.o) $(TEST_FILES:.cpp=.o)

# Output executable name
TARGET := $(BIN_DIR)/GovernmentUnitTests

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I. -I$(SRC_DIR) -I..

# Default target
all: $(TARGET)

# Ensure bin directory exists, then link the executable
$(TARGET): $(BIN_DIR) $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_FILES)

# Rule to create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ_FILES) $(TARGET)

# Run the executable
run: all
	./$(TARGET)

# Phony targets
.PHONY: all clean run
