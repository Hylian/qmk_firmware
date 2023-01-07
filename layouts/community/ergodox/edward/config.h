#pragma once

#undef  MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       20
#undef  MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef  MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    60
#undef  MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      7
#undef  MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0

/* Set 0 if debouncing isn't needed */
#undef DEBOUNCE
#define DEBOUNCE  3

#ifdef ST7565_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define ST7565_TIMEOUT 0
#define usb_lld_disconnect_bus(usbp) do {} while(0)
#endif
