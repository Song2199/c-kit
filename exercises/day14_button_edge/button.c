#include "button.h"

void button_init(Button *button, uint8_t initial_state)
{
    button->previous_state = initial_state;
}

ButtonEvent button_update(Button *button,uint8_t current_state)
{
    ButtonEvent event = BUTTON_EVENT_NONE;

    if (button->previous_state == 0u && current_state == 1u)
{
    event = BUTTON_EVENT_PRESSED;
}

    else if (button->previous_state == 1u && current_state == 0u)
{
    event = BUTTON_EVENT_RELESED;
}

    button->previous_state = current_state;
    return event;

}
