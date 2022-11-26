#include "GraphicElement.h"

GraphicElement::GraphicElement(uint32_t xPos, uint32_t yPos) : xPos(xPos), yPos(yPos)
{

}

void GraphicElement::setPosition(uint32_t xPos, uint32_t yPos)
{
    this->xPos = xPos;
    this->yPos = yPos;
}

