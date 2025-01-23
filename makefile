# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Target executable
TARGET = main

# Directories
SRCDIR = src
OBJDIR = src

# Source and object files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/*.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

# Phony targets
.PHONY: clean