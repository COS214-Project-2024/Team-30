# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -std=c++14 -Wall -Wextra

# Define the executable name
TARGET = citizens

# Define the source files
SRCS = TestingMain.cpp \
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
       Government.cpp\
       CityGrowthObserver.cpp\
       CategorizationStrategy.cpp\
       EconomyCategorization.cpp\
       PopulationCategorization.cpp\
       Population.cpp\
       Infrastructure.cpp\
       Housing.cpp\
       Economy.cpp
       
       

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
