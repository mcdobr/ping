all:
	g++ -o ping main.cpp Button.cpp -g -std=c++11 -Wall -lsfml-graphics -lsfml-window -lsfml-system
