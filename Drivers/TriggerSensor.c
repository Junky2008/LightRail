#include "TriggerSensor.h"

TriggerHandle Trigger(void (*trigger)(TriggerHandle *handle, uint8_t status),
                      void (*error)(char *error))
{
    TriggerHandle handle;
    handle.onTrigger = preTrigger;
    handle.postTrigger = trigger;
    handle.onError = error;
    handle._status = 1;
    return handle;
}

void preTrigger(TriggerHandle *handle, uint8_t status)
{
    handle->_status = status;
    handle->postTrigger(handle, status);
}

uint8_t Trigger_getStatus(TriggerHandle *handle)
{
    return handle->_status;
}
