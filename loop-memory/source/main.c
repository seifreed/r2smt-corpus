#include <stdint.h>

static volatile uint32_t loop_sink;

__attribute__((noinline)) uint32_t loop_memory(uint32_t value) {
    uint32_t total = 0;
    for (uint32_t index = 0; index < value && index < 8U; ++index) {
        loop_sink ^= value + index;
        total += loop_sink;
    }
    return total + loop_sink;
}

int main(int argc, char **argv) {
    (void)argv;
    return (int)loop_memory((uint32_t)argc);
}
