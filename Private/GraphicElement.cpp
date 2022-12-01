#include "GraphicElement.h"

GraphicElement::GraphicElement(uint32_t xPos, uint32_t yPos,std::shared_ptr<IOutput> output)
 : xPos(xPos), yPos(yPos), output(output)
{

}

void GraphicElement::setPosition(uint32_t xPos, uint32_t yPos)
{
    this->xPos = xPos;
    this->yPos = yPos;
}

uint32_t GraphicElement::getX()
{
    return this->xPos;
}
uint32_t GraphicElement::getY()
{
    return this->yPos;
}

