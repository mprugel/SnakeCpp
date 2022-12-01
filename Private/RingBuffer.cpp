#include "RingBuffer.h"

void RingBuffer::write(const uint32_t& u32Val)
{
    std::lock_guard<std::mutex> g(this->mtx);
    this->u32Buffer[this->u32WritePos] = u32Val;
    this->u32WritePos = (this->u32WritePos + 1) & BUFFER_MASK;
    if(this->u32ElementCount < BUFFER_SIZE)
    {
        this->u32ElementCount++;
    }
}

enum ReturnCode RingBuffer::read(uint32_t& u32Value)
{
    std::lock_guard<std::mutex> g(this->mtx);
    if(this->u32ElementCount == 0)
    {
        return ReturnCode::EMPTY;
    }

    u32Value = this->u32Buffer[this->u32ReadPos];
    this->u32ReadPos = (this->u32ReadPos + 1) & BUFFER_MASK;
    this->u32ElementCount--;

    return ReturnCode::OK;
}