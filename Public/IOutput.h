#ifndef IOUTPUT_H
#define IOUTPUT_H
#include <stdint.h>
#include <string>

class IOutput
{
    public:
        virtual void drawRect(uint32_t u32xPos, uint32_t u32yPos, uint32_t u32Width, uint32_t u32Height) = 0;
        virtual void drawLine(uint32_t u32x1, uint32_t u32y1, uint32_t u32x2, uint32_t u32y2) = 0;
        virtual void drawPoint(uint32_t u32xPos, uint32_t u32yPos) = 0;
        virtual void clear() = 0;
        virtual void drawText(uint32_t u32x, uint32_t u32y,std::string text) = 0;
        virtual void update() = 0;

};

#endif
