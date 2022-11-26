#ifndef GRAPHIC_OUTPUT_H
#define GRAPHIC_OUTPUT_H
#include <ncurses.h>


class GraphicOutput
{
    private:
        uint32_t u32WindowWidth;
        uint32_t u32WindowHeight;
        // ncurses Window:
        WINDOW* win; 
    public:
        GraphicOutput(uint32_t u32Width, uint32_t u32Height);
        void drawRect(uint32_t u32xPos, uint32_t u32yPos, uint32_t u32Width, uint32_t u32Height);

};

#endif