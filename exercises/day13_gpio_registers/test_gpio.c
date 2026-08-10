#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "gpio.h"

int main(void)
{
    volatile uint8_t direction_reg = 0u;
    volatile uint8_t output_reg = 0u;
    volatile uint8_t input_reg = 0u;

    gpio_set_output(&direction_reg,3u);
    assert(direction_reg==(1u<<3));

    gpio_set_input(&direction_reg,3u);
    assert(direction_reg == 0u);

    gpio_write_high(&output_reg,2u);
    assert(output_reg == (1u << 2));

    gpio_write_low(&output_reg, 2u);
    assert(output_reg == 0u);

    input_reg=(1u<<4);
    assert(gpio_read(&input_reg, 4u) == 1);

    input_reg = 0u;
    assert(gpio_read(&input_reg, 4u) == 0);

    assert(gpio_read(&input_reg, 3u) == 0);
    printf("All GPIO tests passed.\n");
    return 0;
}