# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Isrc -Ilib/sfml-widgets/src -DSFML_STATIC
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lGL

# --- Submodule Check ---
# This rule checks if the submodule files are present and initializes them if not.
# It makes the build process seamless for new users.
SUBMODULE_SENTINEL := lib/sfml-widgets/src/Gui/Widget.hpp

all: $(SUBMODULE_SENTINEL)
	@$(MAKE) --no-print-directory build_project

$(SUBMODULE_SENTINEL):
	@echo "--- Initializing submodules ---"
	@git submodule update --init --recursive

# --- Project Build ---

# Source files and object files
SRCS = $(wildcard src/*.cpp) $(wildcard src/rules/*.cpp) $(wildcard src/utils/*.cpp)
OBJS = $(patsubst src/%.cpp,build/%.o,$(SRCS))

# sfml-widgets source and object files
WIDGET_SRCS = $(shell find lib/sfml-widgets/src -name "*.cpp")
WIDGET_OBJS = $(patsubst lib/sfml-widgets/src/%.cpp,build/sfml-widgets/%.o,$(WIDGET_SRCS))

# All object files
ALL_OBJS = $(OBJS) $(WIDGET_OBJS)

# Executable name
EXEC = build/boids_simulation

# Create a list of all directories to be created
DIRS = $(sort $(dir $(ALL_OBJS)))

.PHONY: all clean docs build_project

# Real build target
build_project: $(EXEC) run

# Doxygen documentation target
docs:
	doxygen

# Rule to link the executable
$(EXEC): $(ALL_OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Rule to create the build directories
$(DIRS):
	mkdir -p $@

# Rule to compile project source files
build/%.o: src/%.cpp | $(DIRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile sfml-widgets source files
build/sfml-widgets/%.o: lib/sfml-widgets/src/%.cpp | $(DIRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(EXEC)
	./$(EXEC)

# Rule to clean up generated files
clean:
	rm -rf build
	rm -rf docs
