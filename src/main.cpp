#include "main.h"

pid_t pid;

volatile int set_point = (int)((SETPOINT * 32767L + 50L) / 100L);
volatile double speed = 0.0;
volatile uint8_t power = 0;

void setup() 
{
    own_stdio_setup();
    timer_init_ISR_100Hz(TIMER_DEFAULT); 

    encode_setup();
    pid_init(&pid, set_point, KP, KI, KD, PWM_MIN, PWM_MAX);

    digitalWrite(IN_A, HIGH);
    digitalWrite(IN_B, LOW);
}

void loop() 
{
    static uint32_t last_print = 0;

    if(last_print < millis())
    {
        // Convert set_point в проценты с округлением
        int set_point_percent = (int)(( (long)set_point * 100 + 16383 ) / 32767 );
        printf("Speed: %d, Set point: %d%%, Power: %d\n\r", (int)speed, set_point_percent, power);

        last_print = millis() + PRINT_RECURENCE;
    }
}

void timer_handle_interrupts(int timer)
{
    static uint16_t count;

    count = encode_get_count();
    count = meanFilter(count);
    speed = count * CONSTANT_TO_RPM;
 
    power = pid_compute(&pid, speed);
    analogWrite(IN_EN, power);
}

void serialEvent()
{
    char str[32] = {0};
    scanf("%s", str);

    int percent = atoi(str);

    if(percent < 0)
    {
        percent = 0;
    }
    else if(percent > 100)
    {
        percent = 100;
    }

    // Convert проценты в диапозон 0-32767 с округлением
    set_point = (int)(( (long)percent * 32767 + 50 ) / 100 );
    pid_set_setpoint(&pid, set_point);
}