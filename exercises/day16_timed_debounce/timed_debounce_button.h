#ifndef TIMED_DEBOUNCE_BUTTON_H
#define TIMED_DEBOUNCE_BUTTON_H

#include<stdint.h>

typedef enum
{
    BUTTON_EVENT_NONE,
    BUTTON_EVENT_PRESSED,
    BUTTON_EVENT_RELEASED
}ButtonEvent;

typedef struct
{
    uint8_t stable_state;
    uint8_t candidate_state;
    uint32_t candidate_since_ms;
    uint32_t debounce_ms;
} TimedDebounceButton;

void timed_debounce_button_init(TimedDebounceButton *button,uint8_t initial_state,uint32_t debounce_ms);

ButtonEvent timed_debounce_button_update(TimedDebounceButton *button,uint8_t raw_state,uint32_t now_ms
);
#endif