#include "SnakeGame.h"


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

