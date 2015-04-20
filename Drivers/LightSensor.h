#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include <stdint.h>

typedef struct LightHandle LightHandle;
struct LightHandle
{
    float (*getValue)();
    void (*onError)(char *handle);
};

LightHandle Light(float (*getter)(),
                  void (*error)(char *handle));

float Light_getValue(LightHandle *handle);

#endif //LIGHTSENSOR_H
