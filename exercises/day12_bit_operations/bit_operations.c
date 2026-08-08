#include "bit_operations.h"

void bit_set(uint8_t *reg, uint8_t bit)
{
    *reg |= (1u << bit);
}

void bit_clear(uint8_t *reg, uint8_t bit)
{
    *reg &= ~(1u << bit);
}

void bit_toggle(uint8_t *reg, uint8_t bit)
{
    *reg ^= (1u << bit);
}

int bit_is_set(uint8_t reg, uint8_t bit)
{
    return (reg & (1u << bit)) != 0u;
}