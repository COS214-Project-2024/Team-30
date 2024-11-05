# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -std=c++14 -Wall -Wextra

# Define the executable name
TARGET = citizens
EMERGENCY_TARGET = emergencyMain

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
       Government.cpp \
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
       LandmarkFactory.cpp \
       Emergencies.cpp \
       Fires.cpp \
       Earthquake.cpp \
       Thieves.cpp \
       CityGrowthObserver.cpp\
       CategorizationStrategy.cpp\
       EconomyCategorization.cpp\
       PopulationCategorization.cpp\
       Population.cpp\
       PopulationGrowth.cpp\
       Infrastructure.cpp\
       Housing.cpp\
       Economy.cpp\
       PowerPlant.cpp\
       Resource.cpp\
       Steel.cpp\
       Wood.cpp\
       Concrete.cpp\
       Coal.cpp\
       Water.cpp\
       SewageSystem.cpp\
       WaterSupply.cpp\
       WasteManagement.cpp\
       Utilities.cpp
       Road.cpp\
       Transport.cpp\
       PrivateTransport.cpp\
       PublicTransport.cpp\
       Plane.cpp\
       SetRedLightsCommand.cpp\
       Sign.cpp\
       Taxi.cpp\
       Train.cpp\
       Roadsign.cpp\
       BillboardSign.cpp\
       TrafficLight.cpp\
       Area.cpp\
       trafficCommand.cpp


# Add emergencyMain.cpp to the source files
EMERGENCY_SRCS = emergencyMain.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Define the object files for emergencyMain
EMERGENCY_OBJS = $(EMERGENCY_SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the main executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the emergencyMain executable
$(EMERGENCY_TARGET): $(EMERGENCY_OBJS) $(OBJS)  # Link with main target objects if needed
	$(CXX) $(CXXFLAGS) -o $@ $^

# Run the main executable
run: $(TARGET)
	./$(TARGET)

# Run the emergencyMain executable
runEmergency: $(EMERGENCY_TARGET)
	./$(EMERGENCY_TARGET)

# Clean up the directory by removing the executable and object files
clean:
	rm -f $(TARGET) $(EMERGENCY_TARGET) $(OBJS) $(EMERGENCY_OBJS)

# Phony targets
.PHONY: all clean run rebuild runEmergency

# Recompile everything
rebuild: clean all
