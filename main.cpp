#include <iostream>
#include <ncurses.h>
#include <thread>
#include <chrono>
#include "SnakeGame.h"


/**
 * @brief Thread for listening to the Keyboard Input.
 * 
 */
void threadKeyboardListener(SnakeGame& game)
{
    int ch;
    nodelay(stdscr, TRUE);
    while(1) 
    {
       ch = getch();
        switch (ch) 
        {
            case 'a':
            break;

            case 'q':
            return;
        }
    }
}
void threadGameTick(SnakeGame& game)
{
    uint32_t u32TickRate = game.getTickRate();
    uint32_t u32SleepTime =  (uint32_t)(1000 / u32TickRate);
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(u32SleepTime));
        game.tick();
    }
}  

int main()
{
    initscr(); 
    cbreak();
    noecho(); 
    keypad(stdscr, TRUE); 
    SnakeGame game(1);
    std::thread tickThread(threadGameTick,std::ref(game));
    std::thread keyboardThread(threadKeyboardListener,std::ref(game));

    keyboardThread.join();    
    // Terminate curses mode:
    endwin();
    std::cout << "Left Game" << std::endl;
    tickThread.detach();

    
    return 0;
}