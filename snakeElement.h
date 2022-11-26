#ifndef SNAKE_ELEMENT_H
#define SNAKE_ELEMENT_H
#include "GraphicElement.h"

class SnakeElement : public GraphicElement
{
    public:
    SnakeElement(uint32_t xPos, uint32_t yPos,std::shared_ptr<GraphicOutput> graphicOutput);
    virtual void draw();
};

#endif