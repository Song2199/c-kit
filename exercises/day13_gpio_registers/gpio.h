#ifndef GPIO_H
#define GPIO_H

#include<stdint.h>

void gpio_set_output(volatile uint8_t *direction_reg,uint8_t pin);
void gpio_set_input(volatile  uint8_t *direction_reg,uint8_t pin);

void gpio_write_high(volatile uint8_t *output_reg, uint8_t pin);
void gpio_write_low(volatile uint8_t *output_reg, uint8_t pin);

int gpio_read(const volatile uint8_t *input_reg, uint8_t pin);

#endif