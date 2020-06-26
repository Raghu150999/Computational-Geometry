CXX = g++
INC_DIR = ./include
SRC_DIR = ./src
BUILD_DIR = ./build
CXXFLAGS = -Wall -O3 -I$(INC_DIR)
INCLUDES = $(INC_DIR)/*.hpp
# All source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# All corresponding object files
BUILD = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

chan: $(BUILD) main.cpp
	$(CXX) $(CXXFLAGS) $^ -o main_chan

graham: $(BUILD) ./tests/main_graham.cpp
	$(CXX) $(CXXFLAGS) $^ -o main_graham

jarvis: $(BUILD) ./tests/main_jarvis.cpp
	$(CXX) $(CXXFLAGS) $^ -o main_jarvis

test_fixed_h: $(BUILD) ./tests/tester_fixed_h.cpp
	$(CXX) $(CXXFLAGS) $^ -o test_fixed_h

test_int: $(BUILD) ./tests/tester.cpp
	$(CXX) $(CXXFLAGS) $^ -o test_int

test_long: $(BUILD) ./tests/tester_long.cpp
	$(CXX) $(CXXFLAGS) $^ -o test_long

test_double: $(BUILD) ./tests/tester_double.cpp
	$(CXX) $(CXXFLAGS) $^ -o test_double

bs_test: $(BUILD) ./tests/bs_tester.cpp
	$(CXX) $(CXXFLAGS) $^ -o bs_test

# Build all source files into corresponding object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDES)
	$(CXX) -c $(CXXFLAGS) $< -o $@

## Notes:
# '$<' : first requirement file
# '$^' : all requirement files
# '$@' : target file