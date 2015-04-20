#include "MOC_SYS.h"

float _lightValue;
int _length;
int _position;
bool _moving;
int _speed;
MOTOR_DIR _direction;
bool _working;
pthread_t worker;

void *sysupdate(void*)
{
    while(_working)
    {
        usleep(1000000);
        if(_moving)
        {
            if(_direction == FORWARDS)
                _position += _speed;
            else
                _position -= _speed;
            if(_position >= _length)
            {
                _position = _length;
                MOC_GPIO_IRQ(2);
            }
            else if(_position <= 0)
            {
                _position = 0;
                MOC_GPIO_IRQ(1);
            }
            std::cout << "[ INFO ] Position: " << _position << "/" << _length << std::endl;
        }
    }
}

void sysinit()
{
    _working = true;
    _position = 0;
    _direction = FORWARDS;
    _speed = 0;
    _moving = false;
    _length = 1000;
    pthread_create(&worker, NULL, sysupdate, NULL);
}

void sysdeinit()
{
    _working = false;
}

void setLength(int length)
{
    _length = length;
}

float getLightValue()
{
    return _lightValue;
}

void setLightValue(float value)
{
    _lightValue = value;
}

void setMoving(bool moving)
{
    _moving = moving;
    if(_moving)
        MOC_GPIO_IRQ(0);
    std::cout << "[ INFO ] Moving: " << _moving << std::endl;
}

bool getMoving()
{
    return _moving;
}

void setSpeed(uint8_t speed)
{
    _speed = speed;
}

void setDirection(MOTOR_DIR dir)
{
    _direction = dir;
}
