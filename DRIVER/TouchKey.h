#ifndef __TOUCH_KEY_H__
#define __TOUCH_KEY_H__

#include <stc8h.h>
#include <stdio.h>

#include "Config.h"
#include "GPIO.h"
#include "STC8G_H_Delay.h"
#include "STC8G_H_GPIO.h"
#include "STC8G_H_NVIC.h"
#include "STC8G_H_Switch.h"

/**
 * MSB channel 15 ~ LSB channel 0, bit 0 ~ bit 15, 1 for enable, 0 for disable
 */
#ifndef TK_CHANNEL_ENABLED
#define TK_CHANNEL_ENABLED 0x70c0  //  0111 0000 1100 0000
#endif                             // TK_CHANNEL_ENABLED

#ifndef TK_LOWPASS_ENABLED
#define TK_LOWPASS_ENABLED FALSE
#endif  // TK_LOWPASS_ENABLED

#ifndef TK_PRESS_THRESHOLD_MULTIPLIER
#define TK_PRESS_THRESHOLD_MULTIPLIER 0.5F
#endif  // TK_PRESS_THRESHOLD_MULTIPLIER

#ifndef TK_UNPRESS_THRESHOLD_MULTIPLIER
#define TK_UNPRESS_THRESHOLD_MULTIPLIER 0.666F
#endif  // TK_UNPRESS_THRESHOLD_MULTIPLIER

#ifndef TK_LONG_PRESS_THRESHOLD
#define TK_LONG_PRESS_THRESHOLD 5  // 5 * 100ms = 500ms
#endif                             // TK_LONG_PRESS_THRESHOLD

#ifndef TK_CONTINUOUS_PRESS_THRESHOLD
#define TK_CONTINUOUS_PRESS_THRESHOLD 3  // 2 * 100ms = 200ms
#endif                                   // TK_CONTINUOUS_PRESS_THRESHOLD

#ifndef TK_ALLOW_ZERO_FOLLOWING
#define TK_ALLOW_ZERO_FOLLOWING FALSE
#endif  // TK_ALLOW_ZERO_FOLLOWING

/**
 * TouchKey_t is used to store the state of each touch key, including:
 * - keybit: the bit position of the touch key in the touchKeyStatus variable.
 */
typedef struct
{
    u8 keybit;
    u8 pressDuration;
    u8 pressCount;
    u8 lastReleaseDuration;
    u8 isPressing;
} TouchKey_t;

/**
 * @brief touchKeyStatus is a 16-bit variable where each bit represents the
 * current status of a touch key (1 for pressed, 0 for not pressed).
 * MSB 15 ~ LSB 0 corresponds to TK15 ~ TK0. The status is updated in the
 * interrupt handler.
 */
extern u16 xdata touchKeyStatus;

// For auto-calibration, not implemented yet
// extern u16 xdata TK_Neutral[16];
/**
 * @brief KT_READ_DONE_FLAG is a flag that indicates whether the touch key
 * scanning is completed for the current scan cycle. It is set to TRUE in the
 * interrupt handler when the scanning is done. The main loop can check this
 * flag to know when to read the touch key status and perform related actions.
 * After processing the touch key status, the main loop should set this flag
 * back to FALSE to wait for the next scan cycle.
 *
 * @note the flag is not essential if the timer is tuned properly.
 */
extern bit TK_Ready;

/**
 * @brief TouchKey_Config initializes the touch key channels and related GPIOs.
 * It should be called before using any touch key functions. This function WILL
 * configure the GPIO pins for the enabled touch key channels, set up the touch
 * key scanning parameters, and enable the touch key interrupt.
 */
void TouchKey_Config();

/**
 * @brief TouchKey_IsAnyPressed checks if any touch key is currently pressed.
 * @return TRUE if any touch key is pressed, FALSE otherwise.
 * Note: The touch key status is updated in the interrupt handler, so this
 * function should be called after the TK_READ_DONE_FLAG is set to TRUE to get
 * the latest status.
 */
bit TouchKey_IsAnyPressed();

/**
 * @brief TouchKey_GetPressedKeys returns a 16-bit bitmask representing the
 * pressed status of each touch key channel. Each bit corresponds to a touch key
 * channel, where bit 0 corresponds to TK0 and bit 15 corresponds to TK15. A bit
 * value of 1 indicates that the corresponding touch key is pressed, while a bit
 * value of 0 indicates that it is not pressed.
 */
u16 TouchKey_GetPressedKeys();

/**
 * @brief Get the raw data value of a specific touch key channel. Call after
 * TK_READ_DONE_FLAG is set to TRUE to get the latest data.
 *
 * @param channel The touch key channel number (0-15) to check.
 * @return The raw data value of the specified touch key channel.

 */
u16 TouchKey_GetRawData(u8 channel);

/**
 * @brief TouchKey_IsPressed checks if a specific touch key channel is currently
 * pressed. Call after TK_READ_DONE_FLAG is set to TRUE to get the latest
 * status.
 *
 * @param channel The touch key channel number (0-15) to check.
 * @return TRUE if the specified touch key channel is pressed, FALSE otherwise.
 */
u8 TouchKey_IsPressed(u8 channel);

void TouchKey_Calibrate();

void TouchKey_Event(u8 keyIndex, void (*onShortPress)(u8 pressCount),
                    void (*onLongPress)(u8 pressCount));

#endif  // __TOUCH_KEY_H__