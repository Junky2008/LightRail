#ifndef TRIGGERSENSOR_H
#define TRIGGERSENSOR_H

#include <stdint.h>

typedef struct TriggerHandle TriggerHandle;

struct TriggerHandle
{
    void (*onTrigger)(TriggerHandle *handle, uint8_t status);
    void (*postTrigger)(TriggerHandle *handle, uint8_t status);
    void (*onError)(char *error);

    uint8_t _status;
};

TriggerHandle Trigger(void (*trigger)(TriggerHandle *handle, uint8_t status),
                      void (*error)(char *error));

void preTrigger(TriggerHandle *handle, uint8_t status);

uint8_t Trigger_getStatus(TriggerHandle *handle);

#endif //TRIGGERSENSOR
