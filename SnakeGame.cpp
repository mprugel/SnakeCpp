#include "SnakeGame.h"

void SnakeGame::drawSnake()
{

}

void SnakeGame::moveSnake()
{

}

void SnakeGame::initialize()
{
    // Create Basic Snake:
    for(uint32_t i = 0; i < 5; i++)
    {
        std::shared_ptr<SnakeElement> ptr = std::shared_ptr<SnakeElement>( new SnakeElement(i,10,this->graphicOutput));
        this->lGraphicElements.push_back(ptr);
    }
}

void SnakeGame::tick()
{
    // Add new Element to List:

}

void SnakeGame::addKeyboardInput(enum Direction eDirection)
{
    this->keyboardInputs.write((uint32_t&)eDirection);
}
SnakeGame::SnakeGame(uint32_t u32TickRate) : u32TickRate(u32TickRate)
{

}
uint32_t SnakeGame::getTickRate()
{
    return this->u32TickRate;
}

