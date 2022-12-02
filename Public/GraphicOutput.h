#ifndef GRAPHIC_OUTPUT_H
#define GRAPHIC_OUTPUT_H
#include <ncurses.h>
#include "IOutput.h"
#include <stdint.h>


class GraphicOutput : public IOutput
{
    private:
        uint32_t u32WindowWidth;
        uint32_t u32WindowHeight;
        // ncurses Window:
        WINDOW* win; 
    public:
        void drawRect(uint32_t u32xPos, uint32_t u32yPos, uint32_t u32Width, uint32_t u32Height);
        void drawLine(uint32_t u32x1, uint32_t u32y1, uint32_t u32x2, uint32_t u32y2);
        void drawPoint(uint32_t u32xPos, uint32_t u32yPos);
        virtual void clear();
        virtual void update();
        virtual void drawText(uint32_t u32x, uint32_t u32y,std::string text);
        virtual void initialize(uint32_t u32Width, uint32_t u32Height);




};

#endif