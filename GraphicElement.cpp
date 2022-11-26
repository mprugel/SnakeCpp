#include "GraphicElement.h"

GraphicElement::GraphicElement(uint32_t xPos, uint32_t yPos,std::shared_ptr<GraphicOutput> graphicOutput)
 : xPos(xPos), yPos(yPos), graphicOutput(graphicOutput)
{

}

void GraphicElement::setPosition(uint32_t xPos, uint32_t yPos)
{
    this->xPos = xPos;
    this->yPos = yPos;
}

