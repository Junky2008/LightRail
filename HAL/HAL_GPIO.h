#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <stdint.h>

#include "../Drivers/TriggerSensor.h"

extern TriggerHandle trigger_handle;

void HAL_GPIO_IRQ(uint8_t value);

#endif //HAL_GPIO_H
