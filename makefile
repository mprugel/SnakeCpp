snake: main.cpp SnakeGame.cpp GraphicElement.cpp snakeElement.cpp RingBuffer.cpp
	g++ main.cpp SnakeGame.cpp GraphicElement.cpp snakeElement.cpp RingBuffer.cpp -std=c++11 -lncurses -o snake -lpthread