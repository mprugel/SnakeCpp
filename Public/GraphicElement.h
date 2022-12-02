#ifndef GRAPHIC_ELEMENT_H
#define GRAPHIC_ELEMENT_H
#include <stdint.h>
#include <memory>
#include "IOutput.h"
/**
 * @brief Base Class for Graphic Elements
 * 
 */
struct sPosition
{
    int32_t x;
    int32_t y;

    sPosition operator+(sPosition other)
    {
        sPosition newPos;
        newPos.x = this->x + other.x;
        newPos.y = this->y + other.y;
        return newPos;
    }
    sPosition operator-(sPosition other)
    {
        sPosition newPos;
        newPos.x = this->x -other.x;
        newPos.y = this->y - other.y;
        return newPos;
    }
    bool operator==(sPosition other)
    {
        return this->x == other.x && this->y == other.y;
    }

};

class GraphicElement
{
    protected:
        sPosition sPos;
        std::shared_ptr<IOutput> output;

    public:
        GraphicElement(sPosition sPos,std::shared_ptr<IOutput> output);
        /**
         * @brief Draws the Element on the Screen:
         * 
         */
        virtual void draw() = 0;
        void setPosition(sPosition sPos);
        sPosition getPosition();



};


#endif