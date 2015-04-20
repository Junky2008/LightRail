#include "MOC_GPIO.h"

void MOC_GPIO_IRQ(uint8_t value)
{
    trigger_handle.onTrigger(&trigger_handle, value);
}
