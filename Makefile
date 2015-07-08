all:
	g++ -o ping src/*.cpp -g -std=c++11 -Wall -lsfml-graphics -lsfml-window -lsfml-system
