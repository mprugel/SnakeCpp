#include "snakeElement.h"
SnakeElement::SnakeElement(uint32_t xPos, uint32_t yPos,std::shared_ptr<IOutput> output) : GraphicElement(xPos,yPos,output)
{}

void SnakeElement::draw()
{
    this->output->drawPoint(this->xPos, this->yPos);
}
