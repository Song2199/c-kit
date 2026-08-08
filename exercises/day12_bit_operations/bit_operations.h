#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

#include <stdint.h>

void bit_set(uint8_t *reg,uint8_t bit);
void bit_clear(uint8_t *reg,uint8_t bit);
void bit_toggle(uint8_t *reg,uint8_t bit);
int bit_is_set(uint8_t reg,uint8_t bit);

#endif
