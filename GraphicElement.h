#ifndef GRAPHIC_ELEMENT_H
#define GRAPHIC_ELEMENT_H
#include <stdint.h>
#include <memory>
#include "GraphicOutput.h"
/**
 * @brief Base Class for Graphic Elements
 * 
 */
class GraphicElement
{
    private:
        uint32_t xPos;
        uint32_t yPos;
        std::shared_ptr<GraphicOutput> graphicOutput;

    public:
        GraphicElement(uint32_t xPos, uint32_t yPos,std::shared_ptr<GraphicOutput> graphicOutput);
        /**
         * @brief Draws the Element on the Screen:
         * 
         */
        virtual void draw() = 0;
        void setPosition(uint32_t xPos, uint32_t yPos);

};


#endif