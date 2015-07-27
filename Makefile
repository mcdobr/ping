all:
	g++ -o bin/ping src/*.cpp -g -I inc -std=c++11 -Wall -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
