#include "MOC_UART.h"

void MOC_move(MotorHandle *handle, MOTOR_DIR direction, uint8_t speed)
{
    handle = handle;
    setMoving(false);
    setDirection(direction);
    setSpeed(speed);
    setMoving(true);
}

void MOC_stop(MotorHandle *handle)
{
    handle = handle;
    setMoving(false);
    setSpeed(0);
}
