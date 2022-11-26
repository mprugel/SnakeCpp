#include "GraphicOutput.h"


GraphicOutput::GraphicOutput(uint32_t u32Width, uint32_t u32Height) :
u32Width(u32Width), u32Height(u32Height)
{
    this->win = newwin(u32Height, u32Width, 0, 0); 
}

void GraphicOutput::drawRect(uint32_t u32xPos, uint32_t u32yPos, uint32_t u32Width, uint32_t u32Height)
{
    // Move the Cursor:
    wmove(this->win, u32xPos, u32yPos); 

    // Draw the Character:
    waddch(this->win, '#');
}
