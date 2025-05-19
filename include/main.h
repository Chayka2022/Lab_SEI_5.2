#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <timer-api.h>
#include "own_stdio.h"
#include "encode.h"
#include "pid.h"
#include "MeanFilter.h"
#include "simpleMeanFilter.h"

void setup(void);

void loop(void);

void timer_handle_interrupts(int timer);

void serialEvent();

#endif // !MAIN_H