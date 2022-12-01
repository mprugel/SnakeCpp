#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include "SnakeGame.h"
#include "GraphicOutput.h"
#include "Input.h"


/**
 * @brief Thread for listening to the Keyboard Input.
 * 
 */
void threadKeyboardListener(SnakeGame& game)
{
    std::shared_ptr<IInput> input(new Input());
    int ch;
    while(1) 
    {
        ch = input->getPressedKey();
        switch (ch) 
        {
            case 'a':
                game.addKeyboardInput(Direction::LEFT);
            break;
            case 'd':
                game.addKeyboardInput(Direction::RIGHT);
            break;
             case 'w':
                game.addKeyboardInput(Direction::UP);
            break;
             case 's':
                game.addKeyboardInput(Direction::DOWN);
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
        if(!game.tick())
        {
            return;
        }
    }
}  

int main()
{
    std::shared_ptr<IOutput> output(new GraphicOutput(100U,30U));
    SnakeGame game(8, output);
    std::thread tickThread(threadGameTick,std::ref(game));
    std::thread keyboardThread(threadKeyboardListener,std::ref(game));

    keyboardThread.join();    
    // Terminate curses mode:
    endwin();
    std::cout << "Left Game" << std::endl;
    tickThread.detach();

    
    return 0;
}