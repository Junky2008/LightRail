#ifndef MOC_GPIO_H
#define MOC_GPIO_H

#include <stdint.h>

#include "../../Drivers/TriggerSensor.h"
#include "MOC_SYS.h"

extern TriggerHandle trigger_handle;

void MOC_GPIO_IRQ(uint8_t value);

#endif //MOC_GPIO_H
