CXX = g++
CXXFLAGS = -std=c++17 -Wall -I include

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)
TARGET = lab4

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

obj/%.o: src/%.cpp | obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj:
	@mkdir -p obj

clean:
	@rm -rf obj
	@rm -f $(TARGET).exe $(TARGET)

.PHONY: all clean
