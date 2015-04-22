#include "include/gtest/gtest.h"
#include <pthread.h>

#define TESTING

#include "../HAL/MOC/MOC_SYS.h"

#include "../Drivers/Motor.h"
#include "../Drivers/LightSensor.h"
#include "../Drivers/TriggerSensor.h"

#include "../HAL/MOC/MOC_ADC.h"
#include "../HAL/MOC/MOC_GPIO.h"
#include "../HAL/MOC/MOC_UART.h"

#include "../main.c"

MotorHandle motor_handle;
LightHandle light_handle;
TriggerHandle trigger_handle;

void MOC_error(char* error)
{
    std::cout << error << std::endl;
}

void init()
{
    motor_handle = Motor(MOC_move, MOC_stop, MOC_error);
    light_handle = Light(MOC_getADCValue, MOC_error);
    trigger_handle = Trigger(onTrigger, MOC_error);
    sysinit();
}

void deinit()
{
    sysdeinit();
}

class UnitTest : public testing::Test
{
};

TEST_F(UnitTest, success)
{
    EXPECT_EQ(1, 1);
}

TEST_F(UnitTest, close)
{
    setLightValue(2000);
    bool running = true;
    while(running)
    {
        update();
        if(!getMoving())
            break;
    }
}

TEST_F(UnitTest, open)
{
    setLightValue(0);
    bool running = true;
    while(running)
    {
        update();
        if(!getMoving())
            break;
    }
}

TEST_F(UnitTest, fail)
{
    EXPECT_EQ(1, 2);
}

int main (int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    int returnValue;
    init();
    returnValue = RUN_ALL_TESTS();
    deinit();
    return returnValue;
}
