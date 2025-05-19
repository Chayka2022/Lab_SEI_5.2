#include "dd_h_bridge.h"

void dd_h_bridge_setup()
{
    digitalWrite(IN_A, HIGH);
    digitalWrite(IN_B, LOW);
}

void set_h_bridge_power(uint8_t power)
{
    analogWrite(IN_EN, power);
}