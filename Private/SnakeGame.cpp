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
    sPosition sPos = {0,0};   
    auto it = this->lGraphicElements.end();
    it--;
    auto head = *it;
   
    sPos = head->getPosition();

    switch (eDirection)
    {
        case Direction::DOWN :
            sPos.y++;
            break;
         case Direction::UP :
            sPos.y--;
            break;
         case Direction::RIGHT :
            sPos.x++;
            break;
         case Direction::LEFT :
            sPos.x--;
            break;
    }

    auto newHead = std::shared_ptr<SnakeElement>(new SnakeElement(sPos,this->output));

    if(head->getPosition() == this->gFood->getPosition())
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
    // initialze Graphic Output:
    this->output->initialize(this->u32GameWidth, this->u32GameHeight);

    // Create Basic Snake:
    for(int32_t i = 0; i < INITIAL_LENGTH; i++)
    {
        std::shared_ptr<SnakeElement> ptr = std::shared_ptr<SnakeElement>( new SnakeElement({i + 5,10},this->output));
        this->lGraphicElements.push_back(ptr);
    }
    // Create the Food Object:
    this->gFood = std::shared_ptr<SnakeElement>(new SnakeElement({0,0}, this->output));
    this->createFood();

    drawSnake();
}

void SnakeGame::createFood()
{
    // Create the Food randomly;
    std::srand(std::time(nullptr));
    sPosition sPos{-1,-1};
    do 
    {
        sPos.x = (std::rand() % (this->u32GameWidth - 10U)) + 5U;
        sPos.y = (std::rand() % (this->u32GameHeight - 10U)) + 5U;
    }
    while(isPosInSnake(sPos));
   
    this->gFood->setPosition(sPos);
    
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

bool SnakeGame::isPosInSnake(sPosition sPos)
{
    for(auto el : this->lGraphicElements)
    {
        if(el->getPosition() == sPos)
        {
            return true;
        }
    }
    return false;
}

bool SnakeGame::detectCollision()
{
    auto head = this->lGraphicElements.back();
    auto end = this->lGraphicElements.end();
    end--;
    for(auto it = this->lGraphicElements.begin(); it != end; it++)
    {
        if((*it)->getPosition() == head->getPosition())
        {
            return true;
        }
    }
    sPosition headPos = head->getPosition();
    if(headPos.x < 0 || headPos.y < 0 || headPos.y >= this->u32GameHeight || headPos.x >= u32GameWidth)
    {
        return true;
    }
    return false;
}


void SnakeGame::addKeyboardInput(enum Direction eDirection)
{
    this->keyboardInputs.write((uint32_t&)eDirection);
}

SnakeGame::SnakeGame(uint32_t u32TickRate, uint32_t u32Width, uint32_t u32Height, std::shared_ptr<IOutput> output)
 : u32TickRate(u32TickRate), output(output), u32GameWidth(u32Width), u32GameHeight(u32Height)
{
    this->initialize();
}

uint32_t SnakeGame::getTickRate()
{
    return this->u32TickRate;
}

