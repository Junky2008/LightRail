#include "LightSensor.h"

LightHandle Light(float (*getter)(),
                  void (*error)(char *))
{
    LightHandle handle;
    handle.getValue = getter;
    handle.onError = error;
    return handle;
}

float Light_getValue(LightHandle *handle)
{
    return handle->getValue();
}
