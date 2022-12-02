#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <list>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "IOutput.h"

#include "GraphicElement.h"
#include "snakeElement.h"
#include "RingBuffer.h"



enum Direction
{
    RIGHT=0, LEFT, UP, DOWN
};

#define INITIAL_LENGTH 10

class SnakeGame
{
    private:
        std::shared_ptr<IOutput> output;
        uint32_t u32TickRate = 1;
        std::list<std::shared_ptr<GraphicElement>> lGraphicElements;
        std::shared_ptr<GraphicElement> gFood;
        RingBuffer keyboardInputs;
        void drawSnake();
        void moveSnake(Direction eDirection);
        void initialize();
        void createFood();
        bool detectCollision();
        bool isPosInSnake(sPosition sPos);

        uint32_t u32GameWidth = 30U;
        uint32_t u32GameHeight = 30U;

    public:
        void addKeyboardInput(enum Direction eDirection); 
        SnakeGame(uint32_t u32TickRate, uint32_t u32Width, uint32_t u32Height, std::shared_ptr<IOutput> output);
        bool tick();
        uint32_t getTickRate();
        
};


#endif