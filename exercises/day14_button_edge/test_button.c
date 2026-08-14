#include <assert.h>
#include <stdio.h>
#include "button.h"


int main(void)
{
    Button button;

    button_init(&button, 0u);
    assert(button.previous_state == 0u);

    assert(button_update(&button, 0u) == BUTTON_EVENT_NONE);
    assert(button.previous_state == 0u);

    assert(button_update(&button, 1u) == BUTTON_EVENT_PRESSED);
    assert(button.previous_state == 1u);

    assert(button_update(&button, 1u) == BUTTON_EVENT_NONE);
    assert(button.previous_state == 1u);

    assert(button_update(&button, 0u) == BUTTON_EVENT_RELESED);
    assert(button.previous_state == 0u);

    Button pressed_button;

    button_init(&pressed_button, 1u);
    assert(pressed_button.previous_state == 1u);
    assert(button_update(&pressed_button, 1u) == BUTTON_EVENT_NONE);
    printf("All button tests passed.\n");
    return 0;
}