#ifndef MOC_SYS_H
#define MOC_SYS_H

#include "../../Drivers/Motor.h"
#include "MOC_GPIO.h"
#include <pthread.h>
#include <unistd.h>
#include <iostream>

void sysinit();
void sysdeinit();
void setLength(int length);
float getLightValue();
void setLightValue(float value);
void setMoving(bool moving);
void setSpeed(uint8_t speed);
void setDirection(MOTOR_DIR dir);
bool getMoving();

#endif //MOC_SYS_H
