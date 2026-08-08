#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "bit_operations.h"

static void test_bit_set(void)
{
    uint8_t reg = 0;
    bit_set(&reg,3u);

    assert(reg == 8u);
    printf("test_bit_set passed\n");
}



static void test_bit_clear(void)
{
    uint8_t reg = 14u;  /* 00001110 */

    bit_clear(&reg, 3u);

    assert(reg == 6u);
    printf("test_bit_clear passed\n");
}
static void test_bit_toggle(void)
{
    uint8_t reg = 9u;

    bit_toggle(&reg, 3u);

    assert(reg == 1u);
    printf("test_bit_toggle passed\n");
}
static void test_bit_is_set(void)
{
    uint8_t reg = 18u;  /* 00010010 */

    assert(bit_is_set(reg, 4u) == 1);
    assert(bit_is_set(reg, 2u) == 0);

    printf("test_bit_is_set passed\n");
}
int main(void)
{
    test_bit_set();
    test_bit_clear();
    test_bit_toggle();
    test_bit_is_set();
    return 0;
}