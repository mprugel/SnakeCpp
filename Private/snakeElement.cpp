#include "snakeElement.h"
SnakeElement::SnakeElement(sPosition sPos,std::shared_ptr<IOutput> output) : GraphicElement(sPos,output)
{}

void SnakeElement::draw()
{
    this->output->drawPoint(this->sPos.x, this->sPos.y);
}
