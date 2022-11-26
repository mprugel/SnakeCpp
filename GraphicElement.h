#ifndef GRAPHIC_ELEMENT_H
#define GRAPHIC_ELEMENT_H
#include <stdint.h>
/**
 * @brief Base Class for Graphic Elements
 * 
 */
class GraphicElement
{
    private:
        uint32_t xPos;
        uint32_t yPos;
    public:
        GraphicElement(uint32_t xPos, uint32_t yPos);
        /**
         * @brief Draws the Element on the Screen:
         * 
         */
        virtual void draw() = 0;
        void setPosition(uint32_t xPos, uint32_t yPos);

};


#endif