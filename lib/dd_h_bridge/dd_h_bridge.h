#ifndef H_BRIDGE_H
#define H_BRIDGE_H

#include <Arduino.h>
#include "config.h"

void dd_h_bridge_setup(void);

void set_h_bridge_power(uint8_t power);

#endif // !H_BRIDGE_H