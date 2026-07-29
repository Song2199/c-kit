#include <stdio.h>
static void (*button_callback)(void) = NULL;

void button_register_callback(void (*cb)(void))
{
    button_callback = cb;
}

void button_trigger(void)
{
    if (button_callback != NULL)
    {
       button_callback();
    }
}
void led_on(void)
{
    printf("LED ON\n");
}

void buzzer_on(void)
{
    printf("BUZZER ON\n");
}
int main(void)
{
   

    button_register_callback(led_on);
    button_trigger();

    button_register_callback(buzzer_on);
    button_trigger();

    return 0;

}