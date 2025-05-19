#ifndef CONFIG_H
#define CONFIG_H

#define BAUDRATE 115200

#define PRINT_RECURENCE 1000 //ms
#define SCANF_RECURENCE 2100 //ms

#define ENCODER_TICKS_PER_REV 20.0f
#define PID_INTERVAL_MS  10.0f //PID update interval, ms (100 Hz)

#define CONSTANT_TO_RPM (60.0f * 1000.0f / (ENCODER_TICKS_PER_REV * PID_INTERVAL_MS ))  //constant to convert count to RPM  

//PID coefficients
#define KP 2.52
#define KI 10.1
#define KD 0.16

#define PWM_MIN 0
#define PWM_MAX 255

//H Bridge pins for DC motor
#define IN_A 4
#define IN_B 5
#define IN_EN 3

//Encoder pins
#define ENC_A 2

#define MEAN_FILTER_SIZE 5

#endif // !CONFIG_H