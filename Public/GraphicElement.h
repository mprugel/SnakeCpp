#ifndef GRAPHIC_ELEMENT_H
#define GRAPHIC_ELEMENT_H
#include <stdint.h>
#include <memory>
#include "IOutput.h"
/**
 * @brief Base Class for Graphic Elements
 * 
 */
struct Position
{
    int32_t x;
    int32_t y;

    Position operator+(Position other)
    {
        Position newPos;
        newPos.x = this->x + other.x;
        newPos.y = this->y + other.y;
        return newPos;
    }
    Position operator-(Position other)
    {
        Position newPos;
        newPos.x = this->x -other.x;
        newPos.y = this->y - other.y;
        return newPos;
    }

};

class GraphicElement
{
    protected:
        uint32_t xPos;
        uint32_t yPos;
        std::shared_ptr<IOutput> output;

    public:
        GraphicElement(uint32_t xPos, uint32_t yPos,std::shared_ptr<IOutput> output);
        /**
         * @brief Draws the Element on the Screen:
         * 
         */
        virtual void draw() = 0;
        void setPosition(uint32_t xPos, uint32_t yPos);
        uint32_t getX();
        uint32_t getY();


};


#endif