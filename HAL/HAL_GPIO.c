#include "HAL_GPIO.h"

void HAL_GPIO_IRQ(uint8_t value)
{
    trigger_handle.onTrigger(&trigger_handle, value);
}
