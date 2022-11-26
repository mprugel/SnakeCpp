#include "RingBuffer.h"

void RingBuffer::write(uint32_t& u32Val)
{
    std::lock_guard<std::mutex> g(this->mtx);
    this->u32Buffer[this->u32WritePos] = u32Val;
    this->u32WritePos = (this->u32WritePos + 1) & BUFFER_MASK;
}

uint32_t RingBuffer::read()
{
    mtx.lock();
    uint32_t u32RetValue = this->u32Buffer[this->u32ReadPos];
    this->u32ReadPos = (this->u32ReadPos + 1) & BUFFER_MASK;
    mtx.unlock();
    return u32RetValue;
}