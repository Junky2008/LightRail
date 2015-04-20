#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>

enum MOTOR_DIR
{
    FORWARDS = 0,
    BACKWARDS = 1
};

typedef struct MotorHandle MotorHandle;
struct MotorHandle
{
    void (*onMove)(MotorHandle *handle, MOTOR_DIR direction, uint8_t speed);
    void (*onStop)(MotorHandle *handle);
    void (*onError)(char *handle);
};

MotorHandle Motor(void (*mover)(MotorHandle *handle, MOTOR_DIR direction, uint8_t speed),
                  void (*stopper)(MotorHandle *handle),
                  void (*error)(char *handle));


void Motor_move(MotorHandle *handle, MOTOR_DIR direction = FORWARDS, uint8_t speed = 100);

void Motor_stop(MotorHandle *handle);

#endif //MOROT_H
