CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
PROJECT = T01_11200421
C_SOURCE = $(wildcard *.cpp)

all: $(PROJECT)

$(PROJECT): $(C_SOURCE)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(PROJECT)
	./$(PROJECT)

clean:
	rm -f *.o $(PROJECT)