#include <stdio.h>

typedef struct {
    float kp;
    float ki;
    float kd;
    float integral;
    float previous_error;
    float output;
} PID;

void pid_init(PID *pid, float kp, float ki, float kd)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;

    pid->integral = 0;
    pid->previous_error = 0;
    pid->output = 0;
}

int main(void)
{
    PID motor_pid;

    pid_init(&motor_pid, 1.0f, 0.1f, 0.01f);

    printf("kp = %.2f\n", motor_pid.kp);
    printf("ki = %.2f\n", motor_pid.ki);
    printf("kd = %.2f\n", motor_pid.kd);
    printf("integral = %.2f\n", motor_pid.integral);

    return 0;
}