#include "SnakeGame.h"
#include <iostream>
void SnakeGame::drawSnake()
{
    this->output->clear();
    for(auto el : this->lGraphicElements)
    {
        el->draw();
    }
    this->gFood->draw();

}

void SnakeGame::moveSnake(Direction eDirection)
{
    uint32_t u32x, u32y;
    auto it = this->lGraphicElements.end();
    it--;
    auto head = *it;
   
    u32x = head->getX(); 
    u32y = head->getY(); 

    switch (eDirection)
    {
        case Direction::DOWN :
            u32y++;
            break;
         case Direction::UP :
            u32y--;
            break;
         case Direction::RIGHT :
            u32x++;
            break;
         case Direction::LEFT :
            u32x--;
            break;
    }

    auto newHead = std::shared_ptr<SnakeElement>(new SnakeElement(u32x,u32y,this->output));

    if(head->getX() == this->gFood->getX() && head->getY() == this->gFood->getY())
    {
        this->createFood();
    }
    else
    {
        this->lGraphicElements.pop_front();
    }
    this->lGraphicElements.push_back(newHead);

}

void SnakeGame::initialize()
{
    // Create Basic Snake:
    for(uint32_t i = 0; i < INITIAL_LENGTH; i++)
    {
        std::shared_ptr<SnakeElement> ptr = std::shared_ptr<SnakeElement>( new SnakeElement(i + 5,10,this->output));
        this->lGraphicElements.push_back(ptr);
    }
    // Create the Food Object:
    this->gFood = std::shared_ptr<SnakeElement>(new SnakeElement(0,0, this->output));
    this->createFood();

    drawSnake();
}

void SnakeGame::createFood()
{
    // Create the Food randomly;
    std::srand(std::time(nullptr));
    uint32_t u32x = (std::rand() % (this->u32GameWidth - 10U)) + 5U;
    uint32_t u32y = (std::rand() % (this->u32GameHeight - 10U)) + 5U;
    
    this->gFood->setPosition(u32x,u32y);
    
}

bool SnakeGame::tick()
{
    static Direction lastDirecton = Direction::RIGHT;

    // Read Direction from Ringbuffer:
    Direction eDirection;
    if(this->keyboardInputs.read((uint32_t&)eDirection) == ReturnCode::EMPTY)
    {
        eDirection = lastDirecton;
    }
    
    if( eDirection == Direction::DOWN  && lastDirecton != Direction::UP || 
        eDirection == Direction::UP && lastDirecton != Direction::DOWN ||
        eDirection == Direction::LEFT && lastDirecton != Direction::RIGHT ||
        eDirection == Direction::RIGHT && lastDirecton != Direction::LEFT
      )
    {
        lastDirecton = eDirection;     
    }
    else
    {
        eDirection = lastDirecton;
    }

    auto head = this->lGraphicElements.back();

    
    


    
    // Move Snake one position further:
    this->moveSnake(eDirection);
    this->drawSnake();
    // Detect Kollision:
    if(detectCollision())
    {
        this->output->drawText(10,10,"Game Over!\n");
        return false;
    }
    return true;

}

bool SnakeGame::detectCollision()
{
    auto head = this->lGraphicElements.back();
    auto end = this->lGraphicElements.end();
    end--;
    for(auto it = this->lGraphicElements.begin(); it != end; it++)
    {
        if((*it)->getX() == head->getX() && (*it)->getY() == head->getY())
        {
            return true;
        }
    }
    return false;
}


void SnakeGame::addKeyboardInput(enum Direction eDirection)
{
    this->keyboardInputs.write((uint32_t&)eDirection);
}

SnakeGame::SnakeGame(uint32_t u32TickRate, std::shared_ptr<IOutput> output)
 : u32TickRate(u32TickRate), output(output)
{
    this->initialize();
}

uint32_t SnakeGame::getTickRate()
{
    return this->u32TickRate;
}

