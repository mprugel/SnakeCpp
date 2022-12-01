#ifndef I_INPUT_H
#define I_INPUT_H

#include <stdint.h>

class IInput
{
    public:
        virtual char getPressedKey() = 0;

};


#endif