#ifndef __KEY_EVENT_HANDLER_H__
#define __KEY_EVENT_HANDLER_H__

#include "Config.h"
#include "HSM.h"
#include "TouchKey.h"

extern Event_t evt;

void onShortPress(u8 index);
void onLongPress(u8 index);

#endif  // __KEY_EVENT_HANDLER_H__