#ifndef INPUT_H
#define INPUT_H

#include <ncurses.h>
#include "IInput.h"

class Input : public IInput
{
    public:
        Input();
        virtual char getPressedKey();
};

#endif