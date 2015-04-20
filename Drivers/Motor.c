#include "Motor.h"

MotorHandle Motor(void (*mover)(MotorHandle *, MOTOR_DIR, uint8_t),
                  void (*stopper)(MotorHandle *),
                  void (*error)(char *))
{
    MotorHandle handle;
    handle.onError = error;
    handle.onMove = mover;
    handle.onStop = stopper;
    return handle;
}

void Motor_move(MotorHandle *handle, MOTOR_DIR direction, uint8_t speed)
{
    handle->onMove(handle, direction, speed);
}

void Motor_stop(MotorHandle *handle)
{
    handle->onStop(handle);
}
