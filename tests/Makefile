# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -I../src -Ilib/googletest/googletest/include -Ilib/googletest/googlemock/include -Ilib/googletest/googletest
LDFLAGS = -pthread

# Test source files
TEST_SRCS = gtest_main.cpp

# Project source files to be tested
PROJECT_SRCS =

# GoogleTest source files
GTEST_SRCS = lib/googletest/googletest/src/gtest-all.cc

# Object files
TEST_OBJS = $(patsubst %.cpp,../build/%.o,$(TEST_SRCS))
PROJECT_OBJS = $(patsubst ../src/%.cpp,../build/%.o,$(PROJECT_SRCS))
GTEST_OBJECTS = $(patsubst lib/googletest/googletest/src/%.cc,../build/%.o,$(GTEST_SRCS))

OBJS = $(TEST_OBJS) $(PROJECT_OBJS) $(GTEST_OBJECTS)

# Test executable
TEST_EXEC = ../build/run_tests

.PHONY: all clean

# Default target
all: $(TEST_EXEC) run

# Rule to link the test executable
$(TEST_EXEC): $(OBJS) | ../build
	$(CXX) $(LDFLAGS) -o $@ $^

# Rule to create the build directory
../build:
	mkdir -p ../build

# Rule to compile test source files
../build/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile project source files
../build/%.o: ../src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile gtest source files
../build/%.o: lib/googletest/googletest/src/%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TEST_EXEC)
	./$(TEST_EXEC)

# Rule to clean up generated files
clean:
	rm -f $(OBJS) $(TEST_EXEC)
