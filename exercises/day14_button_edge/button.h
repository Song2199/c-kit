#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
typedef enum
{
    BUTTON_EVENT_NONE,
    BUTTON_EVENT_PRESSED,
    BUTTON_EVENT_RELESED
}ButtonEvent;

typedef struct
{
    uint8_t previous_state;
}Button;

void button_init(Button *button,uint8_t initial_state);

ButtonEvent button_update(Button *button,uint8_t current_state);

#endif