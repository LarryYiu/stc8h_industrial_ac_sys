#ifndef __BUSSINESS_CONFIG_H__
#define __BUSSINESS_CONFIG_H__

#define TIMER0_INTERVAL_MS 50

// Touch Key configuration
#define TK_IDX_POWER 14
#define TK_IDX_MANUAL 13
#define TK_IDX_DOWN 12
#define TK_IDX_UP 7
#define TK_IDX_SETTING 6

#define TK_CHANNEL_ENABLED 0x70c0

// btn_power: 15101/16088 - 987- 0.06135
// btn_manual: 16430/17355 - 925 - 0.05330
// btn_down: 17171/18414 - 1243 - 0.06750
// btn_up: 16731/17854 - 1123 - 0.06290
// btn_setting: 15279/16217 - 938 - 0.05784

#define TK_PRESS_THRESHOLD_MULTIPLIER 0.05F
#define TK_UNPRESS_THRESHOLD_MULTIPLIER 0.07F

#define TK_LONG_PRESS_THRESHOLD 10
#define TK_CONTINUOUS_PRESS_THRESHOLD 6

#define TK_ALLOW_ZERO_FOLLOWING TRUE
#define TK_LOWPASS_ENABLED FALSE
#define TK_DEBUG TRUE
// End of Touch Key configuration

// AHT21 configuration
#define AHT21_USE_CRC FALSE
// End of AHT21 configuration

// STATE MACHINE configuration
#define FSM_DEBUG TRUE
#define BACKLIGHT_CD 2
// End of STATE MACHINE configuration

#endif  // __BUSSINESS_CONFIG_H__