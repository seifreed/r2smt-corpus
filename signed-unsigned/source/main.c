#include <stdint.h>

__attribute__((noinline)) int signed_gate(int32_t value) {
    return value < 0 ? -1 : 1;
}

__attribute__((noinline)) uint32_t unsigned_gate(uint32_t value) {
    return value >= 0x80000000U ? value - 1U : value + 1U;
}

int main(int argc, char **argv) {
    (void)argv;
    uint32_t value = (uint32_t)argc;
    return signed_gate((int32_t)unsigned_gate(value));
}
