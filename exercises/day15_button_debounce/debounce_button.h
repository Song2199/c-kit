#ifndef DEBOUNCE_BUTTON_H
#define DEBOUNCE_BUTTON_H

#include<stdint.h>

typedef enum
{
    BUTTON_EVENT_NONE,
    BUTTON_EVENT_PRESSED,
    BUTTON_EVENT_RELESED
}ButtonEvent;

typedef struct
{
    uint8_t stable_state;
    uint8_t candidate_state;
    uint8_t consecutive_count;
    uint8_t threshold;

}DebounceButton;
void debounce_button_init(DebounceButton *button,uint8_t initial_state,uint8_t threshold);
ButtonEvent debounce_button_update(DebounceButton *button,uint8_t raw_state);

#endif