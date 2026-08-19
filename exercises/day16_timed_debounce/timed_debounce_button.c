#include "timed_debounce_button.h"

void timed_debounce_button_init(TimedDebounceButton *button,uint8_t initial_state,uint32_t debounce_ms)
{
    button->stable_state = initial_state;
    button->candidate_state = initial_state;
    button->candidate_since_ms = 0u;
    button->debounce_ms = debounce_ms;
}
ButtonEvent timed_debounce_button_update(TimedDebounceButton *button,uint8_t raw_state,uint32_t now_ms)
{
    uint32_t elapsed_ms;
    if(raw_state == button->stable_state)
    {
        button->candidate_state = button->stable_state;
        button->candidate_since_ms = 0u;
        return BUTTON_EVENT_NONE;
    }
    if (raw_state != button->candidate_state)
    {
        button->candidate_state = raw_state;
        button->candidate_since_ms = now_ms;
    }
    elapsed_ms = now_ms - button->candidate_since_ms;
    if (elapsed_ms < button->debounce_ms)
    {
        return BUTTON_EVENT_NONE;
    }

    button->stable_state = button->candidate_state;
    button->candidate_since_ms = 0u;

    if (button->stable_state == 1u)
    {
        return BUTTON_EVENT_PRESSED;
    }

    return BUTTON_EVENT_RELEASED;
}
