#ifndef GAME_HPP
#define GAME_HPP

#include "Ball.hpp"
#include "Paddle.hpp"

namespace ping
{

	class Game
	{
		Ball ball;
		Paddle leftPaddle, rightPaddle;
	public:
		bool collision();
	};
}
