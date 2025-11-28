# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Isrc -Ilib/SFML/include -DSFML_STATIC
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files and object files
SRCS = src/main.cpp src/DynamicArray.cpp
OBJS = $(patsubst src/%.cpp,build/%.o,$(SRCS))

# Executable name
EXEC = build/boids_simulation

.PHONY: all clean

# Default target
all: $(EXEC) run

# Rule to link the executable
$(EXEC): $(OBJS) | build
	$(CXX) $(LDFLAGS) -o $@ $^

# Rule to create the build directory
build:
	mkdir -p build

# Rule to compile source files into object files
# This is a pattern rule. It will match for each .cpp file.
# $< is the first prerequisite (the .cpp file)
# $@ is the target (the .o file)
# The -Isrc flag is added to tell the compiler where to find headers.
build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(EXEC)
	./$(EXEC)

# Rule to clean up generated files
clean:
	rm -f $(OBJS) $(EXEC)
	rm -rf build
