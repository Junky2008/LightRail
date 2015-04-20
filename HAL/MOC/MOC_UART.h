#ifndef MOC_UART_H
#define MOC_UART_H

#include <stdint.h>

#include "../../Drivers/Motor.h"
#include "MOC_SYS.h"

void MOC_move(MotorHandle *handle, MOTOR_DIR direction, uint8_t speed);
void MOC_stop(MotorHandle *handle);

#endif //MOC_UART_H
