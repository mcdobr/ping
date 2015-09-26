CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -Wextra
INCFLAGS = -I inc
LDLIBS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system


all:
	$(CXX) -o ping src/*.cpp $(INCFLAGS) $(CXXFLAGS) $(LDLIBS)
