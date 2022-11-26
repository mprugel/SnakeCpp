#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <list>
#include <memory>
#include "GraphicOutput.h"

#include "GraphicElement.h"
#include "snakeElement.h"
#include "RingBuffer.h"
enum Direction
{
    RIGHT, LEFT, UP, DOWN
};

class SnakeGame
{
    private:
        std::shared_ptr<GraphicOutput> graphicOutput;
        uint32_t u32TickRate = 1;
        std::list<std::shared_ptr<GraphicElement>> lGraphicElements;
        RingBuffer keyboardInputs;
        void drawSnake();
        void moveSnake();
        void initialize();

    public:
        void addKeyboardInput(enum Direction eDirection); 
        SnakeGame(uint32_t u32TickRate);
        void tick();
        uint32_t getTickRate();


        
};


#endif