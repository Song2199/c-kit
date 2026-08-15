#include "debounce_button.h"

void debounce_button_init(DebounceButton *button,uint8_t initial_state,uint8_t threshold)
{
    button->stable_state = initial_state;
    button->candidate_state = initial_state;
    button->consecutive_count = 0u;
    button->threshold = threshold;
}
ButtonEvent debounce_button_update(DebounceButton *button,uint8_t raw_state)
{
    if(raw_state == button->stable_state)
    {
        button->consecutive_count = 0u;
        return BUTTON_EVENT_NONE;
    }
    if(raw_state != button->candidate_state)
    {
        button->candidate_state = raw_state;
        button->consecutive_count=1u;
    }
        else
    {
        button->consecutive_count++;
    }
    if(button->consecutive_count < button->threshold)
    {
        return BUTTON_EVENT_NONE;
    }
    button->stable_state = button->candidate_state;
    button->consecutive_count = 0u;
    if(button->stable_state == 1u)
    {
        return  BUTTON_EVENT_PRESSED;
    }
    return BUTTON_EVENT_RELESED;
}