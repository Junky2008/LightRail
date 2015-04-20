#ifndef HAL_UART_H
#define HAL_UART_H

#include <stdint.h>

#include "../Drivers/Motor.h"

void move(MotorHandle *handle, MOTOR_DIR direction, uint8_t speed);
void stop(MotorHandle *handle);

#endif //HAL_UART_H
