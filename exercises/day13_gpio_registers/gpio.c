#include "gpio.h"

void gpio_set_output(volatile uint8_t *direction_reg, uint8_t pin)
{
    *direction_reg |= (1u << pin);
}

void gpio_set_input(volatile uint8_t *direction_reg, uint8_t pin)
{
    *direction_reg &=~(1u<<pin);

}
void gpio_write_high(volatile uint8_t *output_reg, uint8_t pin)
{
    *output_reg |= (1u << pin);
}
void gpio_write_low(volatile uint8_t *output_reg, uint8_t pin)
{
    *output_reg &= ~(1u << pin);
}
int gpio_read(const volatile uint8_t *input_reg, uint8_t pin)
{
    return (*input_reg & (1u << pin)) != 0u;
}