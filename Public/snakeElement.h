#ifndef SNAKE_ELEMENT_H
#define SNAKE_ELEMENT_H
#include "GraphicElement.h"

class SnakeElement : public GraphicElement
{
    public:
    SnakeElement(sPosition sPos,std::shared_ptr<IOutput> output);
    virtual void draw();
};

#endif