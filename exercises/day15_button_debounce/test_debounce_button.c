#include <assert.h>
#include <stdio.h>

#include "debounce_button.h"

int main(void)
{
    DebounceButton button;
    debounce_button_init(&button,0u,3u);

    assert(button.stable_state == 0u);
    assert(button.candidate_state == 0u);
    assert(button.consecutive_count == 0u);
    assert(button.threshold == 3u);

    printf("Initialization test passed .\n");

    ButtonEvent event;

/* 模拟按下过程中的抖动：1 → 0 → 1 → 1 → 1 */

event = debounce_button_update(&button, 1u);
assert(event == BUTTON_EVENT_NONE);
assert(button.consecutive_count == 1u);
assert(button.stable_state == 0u);

event = debounce_button_update(&button, 0u);
assert(event == BUTTON_EVENT_NONE);
assert(button.consecutive_count == 0u);
assert(button.stable_state == 0u);

event = debounce_button_update(&button, 1u);
assert(event == BUTTON_EVENT_NONE);
assert(button.consecutive_count == 1u);

event = debounce_button_update(&button, 1u);
assert(event == BUTTON_EVENT_NONE);
assert(button.consecutive_count == 2u);

event = debounce_button_update(&button, 1u);
assert(event == BUTTON_EVENT_PRESSED);
assert(button.stable_state == 1u);
assert(button.consecutive_count == 0u);

printf("Press debounce test passed.\n");

/* 持续按住，不应重复产生按下事件 */
event = debounce_button_update(&button, 1u);
assert(event == BUTTON_EVENT_NONE);
assert(button.stable_state == 1u);
assert(button.consecutive_count == 0u);

/* 模拟释放过程中的抖动：0 → 1 → 0 → 0 → 0 */

event = debounce_button_update(&button, 0u);
assert(event == BUTTON_EVENT_NONE);
assert(button.consecutive_count == 1u);
assert(button.stable_state == 1u);

event = debounce_button_update(&button, 1u);
assert(event == BUTTON_EVENT_NONE);
assert(button.consecutive_count == 0u);
assert(button.stable_state == 1u);

event = debounce_button_update(&button, 0u);
assert(event == BUTTON_EVENT_NONE);
assert(button.consecutive_count == 1u);

event = debounce_button_update(&button, 0u);
assert(event == BUTTON_EVENT_NONE);
assert(button.consecutive_count == 2u);

event = debounce_button_update(&button, 0u);
assert(event == BUTTON_EVENT_RELESED);
assert(button.stable_state == 0u);
assert(button.consecutive_count == 0u);

printf("Release debounce test passed.\n");

DebounceButton fast_button;

debounce_button_init(&fast_button, 0u, 1u);

event = debounce_button_update(&fast_button, 1u);

assert(event == BUTTON_EVENT_PRESSED);
assert(fast_button.stable_state == 1u);
assert(fast_button.consecutive_count == 0u);

printf("Threshold-one test passed.\n");

    return 0;
}