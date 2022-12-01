#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <mutex>

#define BUFFER_SIZE 16
#define BUFFER_MASK (BUFFER_SIZE - 1U)

enum ReturnCode
{
    OK = 0,
    EMPTY
};

class RingBuffer
{
    private:
        uint32_t u32Buffer[BUFFER_SIZE];
        uint32_t u32ReadPos = 0U;
        uint32_t u32WritePos = 0U;
        uint32_t u32ElementCount = 0U;
        std::mutex mtx;
        
    public:
        void write(const uint32_t& u32Val);
        enum ReturnCode read(uint32_t& u32Val);


};


#endif