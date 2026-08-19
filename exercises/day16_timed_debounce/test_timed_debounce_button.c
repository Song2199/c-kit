#include <assert.h>
#include <stdio.h>

#include "timed_debounce_button.h"

static void test_initialization(void)
{
    TimedDebounceButton button;

    timed_debounce_button_init(&button, 0u, 30u);

    assert(button.stable_state == 0u);
    assert(button.candidate_state == 0u);
    assert(button.candidate_since_ms == 0u);
    assert(button.debounce_ms == 30u);

    printf("Initialization test passed.\n");
}
static void test_press_timing(void)
{
    TimedDebounceButton button;
    ButtonEvent event;

    timed_debounce_button_init(&button, 0u, 30u);

    /* 10 ms：第一次出现候选状态 1 */
    event = timed_debounce_button_update(&button, 1u, 10u);

    assert(event == BUTTON_EVENT_NONE);
    assert(button.stable_state == 0u);
    assert(button.candidate_state == 1u);
    assert(button.candidate_since_ms == 10u);

    /* 39 ms：只持续了 29 ms，还不能确认 */
    event = timed_debounce_button_update(&button, 1u, 39u);

    assert(event == BUTTON_EVENT_NONE);
    assert(button.stable_state == 0u);
    assert(button.candidate_since_ms == 10u);

    /* 40 ms：刚好持续 30 ms，确认按下 */
    event = timed_debounce_button_update(&button, 1u, 40u);

    assert(event == BUTTON_EVENT_PRESSED);
    assert(button.stable_state == 1u);
    assert(button.candidate_since_ms == 0u);

    /* 50 ms：继续按住，不应重复产生事件 */
    event = timed_debounce_button_update(&button, 1u, 50u);

    assert(event == BUTTON_EVENT_NONE);
    assert(button.stable_state == 1u);

    printf("Press timing test passed.\n");
}

static void test_bounce_cancels_candidate(void)
{
    TimedDebounceButton button;
    ButtonEvent event;

    timed_debounce_button_init(&button, 0u, 30u);

    /* 10 ms：开始观察候选状态 1 */
    event = timed_debounce_button_update(&button, 1u, 10u);

    assert(event == BUTTON_EVENT_NONE);
    assert(button.candidate_state == 1u);
    assert(button.candidate_since_ms == 10u);

    /* 20 ms：抖动回到稳定状态 0，旧候选作废 */
    event = timed_debounce_button_update(&button, 0u, 20u);

    assert(event == BUTTON_EVENT_NONE);
    assert(button.stable_state == 0u);
    assert(button.candidate_state == 0u);
    assert(button.candidate_since_ms == 0u);

    /* 40 ms：再次出现 1，必须从 40 ms 重新计时 */
    event = timed_debounce_button_update(&button, 1u, 40u);

    assert(event == BUTTON_EVENT_NONE);
    assert(button.candidate_since_ms == 40u);

    /* 69 ms：新候选只持续 29 ms */
    event = timed_debounce_button_update(&button, 1u, 69u);

    assert(event == BUTTON_EVENT_NONE);
    assert(button.stable_state == 0u);

    /* 70 ms：从 40 ms 起刚好持续 30 ms */
    event = timed_debounce_button_update(&button, 1u, 70u);

    assert(event == BUTTON_EVENT_PRESSED);
    assert(button.stable_state == 1u);

    printf("Bounce cancellation test passed.\n");
}

static void test_release_timing(void)
{
    TimedDebounceButton button;
    ButtonEvent event;

    timed_debounce_button_init(&button, 1u, 30u);

    /* 100 ms：第一次出现候选状态 0 */
    event = timed_debounce_button_update(&button, 0u, 100u);

    assert(event == BUTTON_EVENT_NONE);
    assert(button.stable_state == 1u);
    assert(button.candidate_state == 0u);
    assert(button.candidate_since_ms == 100u);

    /* 129 ms：只持续了 29 ms */
    event = timed_debounce_button_update(&button, 0u, 129u);

    assert(event == BUTTON_EVENT_NONE);
    assert(button.stable_state == 1u);

    /* 130 ms：刚好持续 30 ms，确认释放 */
    event = timed_debounce_button_update(&button, 0u, 130u);

    assert(event == BUTTON_EVENT_RELEASED);
    assert(button.stable_state == 0u);
    assert(button.candidate_since_ms == 0u);

    /* 140 ms：继续保持释放，不重复产生事件 */
    event = timed_debounce_button_update(&button, 0u, 140u);

    assert(event == BUTTON_EVENT_NONE);
    assert(button.stable_state == 0u);

    printf("Release timing test passed.\n");
}

int main(void)
{
    test_initialization();
    test_press_timing();
    test_bounce_cancels_candidate();
    test_release_timing();
    return 0;
}