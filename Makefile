all:
	g++ -o bin/ping src/*.cpp -I inc -g -std=c++11 -Wall -lsfml-graphics -lsfml-window -lsfml-system
