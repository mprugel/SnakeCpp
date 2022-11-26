#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <list>
#include <memory>

#include "GraphicElement.h"
#include "RingBuffer.h"
enum Direction
{
    RIGHT, LEFT, UP, DOWN
};

class SnakeGame
{
    private:
        uint32_t u32TickRate = 1;
        std::list<std::unique_ptr<GraphicElement>> vGraphicElements;
        RingBuffer keyboardInputs;
        void addKeyboardInput(enum Direction eDirection);

    public: 
        SnakeGame(uint32_t u32TickRate);
        void tick();
        uint32_t getTickRate();


        
};


#endif