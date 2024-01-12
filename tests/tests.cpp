#include <cstdint>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "RingBuffer.h"

int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("Test Ringbuffer Empty") {
    RingBuffer buffer{};
    uint32_t val{0};
    ReturnCode ret = buffer.read(val);
    CHECK(ret == ReturnCode::OK);
}
