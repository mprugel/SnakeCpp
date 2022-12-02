#include "GraphicElement.h"

GraphicElement::GraphicElement(sPosition sPos,std::shared_ptr<IOutput> output)
 : sPos(sPos), output(output)
{

}

void GraphicElement::setPosition(sPosition sPos)
{
    this->sPos = sPos;
}

sPosition GraphicElement::getPosition()
{
    return this->sPos;
}


