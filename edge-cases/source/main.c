#include <stdint.h>

static volatile uint32_t edge_sink;

__attribute__((noinline)) static uint32_t fold_and_call(uint32_t value) {
    uint32_t mixed = (value ^ 0x13579bdfU) + ((value & 0x0fU) << 4U);
    if ((mixed & 1U) == 0U) {
        edge_sink += mixed;
    } else {
        edge_sink ^= mixed;
    }
    return edge_sink;
}

__attribute__((noinline)) static uint32_t counted_loop(uint32_t value) {
    uint32_t total = 0;
    for (uint32_t index = 0; index != 4U; ++index) {
        total += value ^ index;
    }
    return total;
}

int main(int argc, char **argv) {
    (void)argv;
    uint32_t value = (uint32_t)argc;
    return (int)(fold_and_call(value) + counted_loop(value));
}
