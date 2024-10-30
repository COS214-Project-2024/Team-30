# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -std=c++14 -Wall -Wextra

# Define the executable name
TARGET = citizens

# Define the source files
SRCS = main.cpp \
       Citizen.cpp \
       EmploymentStatus.cpp \
       Satisfied.cpp \
       Unsatisfied.cpp \
       OfficeJob.cpp \
       IndustrialJob.cpp \
       Unemployed.cpp \
       TaxBracket.cpp \
       LowestTaxBracket.cpp \
       MiddleTaxBracket.cpp \
       HighestTaxBracket.cpp \
       Government.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up the directory by removing the executable and object files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean run

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -Wall

# Executable name
TARGET = building_sim

# Source files
SOURCES = buildingMain.cpp \
          Building.cpp \
          BuildingFactory.cpp \
          Underconstruction.cpp \
          Built.cpp \
          Destroyed.cpp \
          Residential.cpp \
          Commercial.cpp \
          Industrial.cpp \
          Landmark.cpp \
          ResidentialFactory.cpp \
          CommercialFactory.cpp \
          IndustrialFactory.cpp \
          LandmarkFactory.cpp

# Object files (replace .cpp extensions with .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Default target to compile and link the program
all: $(TARGET)

# Link all object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile each .cpp file into .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up all compiled files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Recompile everything
rebuild: clean all
