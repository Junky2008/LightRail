#include "Drivers/Motor.h"
#include "Drivers/TriggerSensor.h"
#include "Drivers/LightSensor.h"

#ifndef TESTING
#include "HAL/HAL_UART.h"
#include "HAL/HAL_GPIO.h"
#include "HAL/HAL_ADC.h"
#endif //TESTING

#include <iostream>
#include <stdint.h>

#define SPEED 100

void update();
void onTrigger(TriggerHandle *handle, uint8_t status);

#ifndef TESTING
MotorHandle motor_handle;
TriggerHandle trigger_handle;
LightHandle light_handle;


void onError(char* error)
{
    std::cout << error << std::endl;
}

void init()
{
    motor_handle = Motor(move, stop, onError);
    trigger_handle = Trigger(onTrigger, onError);
    light_handle = Light(getADCValue, onError);

}

int main()
{
    init();
    while(1)
    {
       update();
    }
}
#else //TESTING
extern MotorHandle motor_handle;
extern TriggerHandle trigger_handle;
extern LightHandle light_handle;
#endif //TESTING

void onTrigger(TriggerHandle *handle, uint8_t status)
{
    if(status)
        Motor_stop(&motor_handle);
}

void update()
{
    float lightValue = Light_getValue(&light_handle);
    if(lightValue > 1000 && Trigger_getStatus(&trigger_handle) == 1)
    {
        Motor_move(&motor_handle, FORWARDS, SPEED);
    }
    if(lightValue < 100 && Trigger_getStatus(&trigger_handle) == 2)
    {
        Motor_move(&motor_handle, BACKWARDS, SPEED);
    }
}
