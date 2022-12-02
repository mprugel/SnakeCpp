#include "GraphicOutput.h"


void GraphicOutput::initialize(uint32_t u32Width, uint32_t u32Height)
{
    initscr(); 
    cbreak(); 
    noecho(); 
    keypad(stdscr, TRUE); 
    nodelay(stdscr, TRUE);
    curs_set(0); // Hide Cursor
    //start_color();
    refresh();

    //start_color();

    this->win = newwin(u32Height, u32Width, 0, 0); 
    wmove(this->win, 2, 2); 
    box(win,0,0);
    // Draw Border around the window:
    wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
    // Set Color: 
    init_pair(COLOR_GREEN,COLOR_GREEN,COLOR_BLACK);
    //wattron(win,COLOR_PAIR(2));

    //drawLine(0,0,10,10);
    //drawPoint(2,2);
    wrefresh(win);
}


void GraphicOutput::drawRect(uint32_t u32xPos, uint32_t u32yPos, uint32_t u32Width, uint32_t u32Height)
{
    // Move the Cursor:
    wmove(this->win, u32xPos, u32yPos); 

    // Draw the Character:
    waddch(this->win, '#');
}

void GraphicOutput::drawLine(uint32_t u32x1, uint32_t u32y1, uint32_t u32x2, uint32_t u32y2)
{
    wmove(this->win, u32x1, u32y2); 

    whline(win, ACS_HLINE, 20);
    wrefresh(win);
}

void GraphicOutput::drawPoint(uint32_t u32xPos, uint32_t u32yPos)
{
    wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);

    // Move the Cursor:
    wmove(this->win, u32yPos, u32xPos); 

    // Draw the Character:
    waddch(this->win, '#');
    wrefresh(win);
}
void GraphicOutput::clear()
{
    wclear(win);
}

void GraphicOutput::drawText(uint32_t u32x, uint32_t u32y, std::string text)
{
    wmove(this->win, u32y, u32x); 
    waddstr(this->win,text.c_str());
    wrefresh(win);
}

void GraphicOutput::update()
{
    wrefresh(win);
}
