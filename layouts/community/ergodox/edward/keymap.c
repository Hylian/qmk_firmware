#include QMK_KEYBOARD_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "debug.h"
#include "action_layer.h"
#include "version.h"
#ifdef ST7565_ENABLE
#include "split_util.h"
#endif

//#define REPEAT_DELAY_MS  (17)
#define REPEAT_KEYCODE  (KC_SPC)

#define BASE 0
#define SYMB 1
#define MDIA 2
#define SWAY 3
#define GAME 4

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  KVM_CTRL,
  KVM1,
  KVM2,
  REPEAT_KEY,
  DELAY_INC,
  DELAY_DEC,
  SOCD_A,
  SOCD_D,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   \    |   1  |   2  |   3  |   4  |   5  |   6  |           |   5  |   6  |   7  |   8  |   9  |   0  |   _    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   [  |           |  {   |   Y  |   U  |   I  |   O  |   P  |   |    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|   ]  |           |  }   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  ~   |   +  |   =  |   -  |  Alt |                                       | Left | Down |  Up  |Right |   `  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Esc  | Sway |       | PgDn | PgUp |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Super |       | Media|        |      |
 *                                 |Space |Enter |------|       |------|  Del   | Bksp |
 *                                 |      |      | Ctrl |       | Symb |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(  // Layer 0 : default
  // Left Hand
  KC_BSLS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,
  KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_RBRC,
  KC_TILDE, KC_PLUS,  KC_EQL,   KC_MINS,  KC_LALT,
                                                    KC_ESC,   MO(SWAY),
                                                              KC_LGUI,
                                          KC_SPC,   KC_ENT,   KC_LCTL,
  // Right Hand
  KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_UNDS,
  KC_LCBR,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_PIPE,
            KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
  KC_RCBR,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLASH, KC_RSFT,
                      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_GRV,
  KC_PGDN,  KC_PGUP,
  MO(MDIA),
  MO(SYMB), KC_DEL,   KC_BSPC
),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | PrSrn   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  Bksp   |   7  |   8  |   9  |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    .    |   4  |   5  |   6  |   *  |   /  |------|           |------|      |   !  |   &  |   *  |  %   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    0    |   1  |   2  |   3  |   +  |   -  |      |           |      |      |   #  |   ^  |   $  |  @   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |   +  |   =  |   -  | Alt  |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | BL   |       | End  | Home |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Space |Enter |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Symbols
[SYMB] = LAYOUT_ergodox(
  // Left Hand
  KC_PSCR,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
  KC_BSPC,  KC_7,     KC_8,     KC_9,     KC_NO,    KC_NO,    KC_NO,
  KC_DOT,   KC_4,     KC_5,     KC_6,     KC_ASTR,  KC_SLASH,
  KC_0,     KC_1,     KC_2,     KC_3,     KC_PLUS,  KC_MINS,  KC_NO,
  KC_NO,    KC_PLUS,  KC_EQL,   KC_MINS,  KC_LALT,
                                                    KC_NO,    QK_BOOTLOADER,
                                                              KC_NO,
                                TG(GAME), KC_ENT,   KC_NO,
  // Right Hand
  KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_F12,
            KC_NO,    KC_EXLM,  KC_AMPR,  KC_ASTR,  KC_PERC,  KC_RCTL,
  KC_NO,    KC_NO,    KC_HASH,  KC_CIRC,  KC_DLR,   KC_AT,    KC_NO,
                      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_END,   KC_HOME,
  KC_NO,
  KC_NO,    KC_NO,    KC_NO
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|Scl L |Scr Dn|Scl Up|Scl R |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |Prev  |VolDn |VolUp | Next |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Mclk |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------| Play | Mute |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Media
[MDIA] = LAYOUT_ergodox(
  // Left Hand
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_MS_U,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                                    KC_BTN3,  KC_NO,
                                                              KC_WH_U,
                                          KC_BTN1,  KC_BTN2,  KC_WH_D,
  // Right Hand
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
            KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                      KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_NO,
  KC_NO,    KC_NO,
  KC_NO,
  KC_NO,    KC_MPLY,  KC_MUTE
),

/* Keymap 3: Sway
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  G1  |  G2  |  G3  |  G4  |  G5  |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  G6  |  G7  |  G8  |  G9  |  G0  |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |      |      |      |      |      |------|           |------| GH   | GJ   | GK   | GL   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |  Alt |                                       |GLeft |GDown | GUp  |GRight|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Sway
[SWAY] = LAYOUT_ergodox(
  // Left Hand
  KC_NO,     LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), KC_NO,
  KC_NO,     LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), KC_NO,
  KC_LCTL,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
  KC_LSFT,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
  KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_LALT,
                                                             KC_NO,      KC_NO,
                                                                         KC_NO,
                                                 KC_NO,      KC_NO,      KC_NO,
  // Right Hand
  KC_NO,     KC_NO,      KC_NO,         KC_NO,         KC_NO,       KC_NO,          KVM1,
  KC_NO,     KC_NO,      KC_NO,         KC_NO,         KC_NO,       KC_NO,          KVM2,
             LGUI(KC_H), LGUI(KC_J),    LGUI(KC_K),    LGUI(KC_L),  KC_NO,          KVM_CTRL,
  KC_NO,     KC_NO,      KC_NO,         KC_NO,         KC_NO,       KC_NO,          KC_NO,
                         LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_UP), LGUI(KC_RIGHT), KC_NO,
  KC_NO,     KC_NO,
  KC_NO,
  KC_NO,     KC_NO,      KC_NO
),

[GAME] = LAYOUT_ergodox(
  // Left Hand
  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   SOCD_A,    KC_TRNS,   SOCD_D,    KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
                                                             KC_TRNS,    KC_TRNS,
                                                                         KC_TRNS,
                                              KC_TRNS/*REPEAT_KEY*/,    KC_TRNS,    KC_TRNS,

  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
             KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
                        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
  DELAY_DEC, DELAY_INC,
  KC_TRNS,
  TO(BASE),   KC_TRNS,  KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),               // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(MDIA),               // FN2 - Momentary Layer 2 (Media)
    [3] = ACTION_LAYER_TAP_TOGGLE(SWAY)                // FN3 - Momentary Layer 3 (Sway)
};

static int32_t s_prev_time = 0;
static bool s_repeat_enabled = false;
static uint8_t s_repeat_delay_ms = 62;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool a_pressed = false;
    static bool a_active = false;
    static bool d_pressed = false;
    static bool d_active = false;

    switch (keycode) {
        case SOCD_A:
            if (record->event.pressed) {
                if (d_pressed) {
                    unregister_code(KC_D);
                    d_active = false;
                }
                register_code(KC_A);
                a_pressed = true;
                a_active = true;
            } else {
                unregister_code(KC_A);
                a_pressed = false;
                a_active = false;
                if (d_pressed && !d_active) {
                    register_code(KC_D);
                    d_active = true;
                }
            }
            return false;
        case SOCD_D:
            if (record->event.pressed) {
                if (a_pressed) {
                    unregister_code(KC_A);
                    a_active = false;
                }
                register_code(KC_D);
                d_pressed = true;
                d_active = true;
            } else {
                unregister_code(KC_D);
                d_pressed = false;
                d_active = false;
                if (a_pressed && !a_active) {
                    register_code(KC_A);
                    a_active = true;
                }
            }
            return false;
        case KVM1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_TAP(X_RCTL) "1");
            }
            break;
        case KVM2:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_TAP(X_RCTL) "2");
            }
            break;
        case KVM_CTRL:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_TAP(X_RCTL));
            }
            break;
        case DELAY_INC:
            if (record->event.pressed) {
                s_repeat_delay_ms++;
            }
            break;
        case DELAY_DEC:
            if (record->event.pressed) {
                if (s_repeat_delay_ms > 0) {
                    s_repeat_delay_ms--;
                }
            }
            break;
        case REPEAT_KEY:
            if (record->event.pressed) {
                tap_code(REPEAT_KEYCODE);
                s_prev_time = timer_read32();
                s_repeat_enabled = true;
            } else {
                s_repeat_enabled = false;
            }
            break;
        default:
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

void matrix_scan_user(void) {
    if (s_repeat_enabled) {
        if (timer_elapsed32(s_prev_time) >= s_repeat_delay_ms) {
            s_prev_time = timer_read32();
            tap_code(REPEAT_KEYCODE);
        }
    }
};

void keyboard_post_init_user(void) {
  //debug_enable = true;
}

#ifdef ST7565_ENABLE
void st7565_task_user(void) {
  static uint8_t prev_layer = 255;
  uint8_t layer = get_highest_layer(layer_state);
  char buf[32] = {0};

  if (layer != prev_layer) {
    prev_layer = layer;

    switch (layer) {
      case BASE:
        st7565_clear();
        ergodox_infinity_lcd_color(0, 0, 0);
        break;

      case SYMB:
        ergodox_infinity_lcd_color(60395, 52942, 15677);
        if (is_keyboard_left()) {
          st7565_set_cursor(0, 1);
          st7565_write("Symbol", false);
        } else {
          st7565_write_ln("! & * %", false);
          st7565_write_ln("# ^ $ @", false);
        }
        break;

      case MDIA:
        ergodox_infinity_lcd_color(5911, 53713, 40092);
        if (is_keyboard_left()) {
          st7565_set_cursor(0, 1);
          st7565_write("Mouse", false);
        }
        break;

      case SWAY:
        ergodox_infinity_lcd_color(17219, 27756, 59624);
        if (is_keyboard_left()) {
          st7565_set_cursor(0, 1);
          st7565_write("Sway", false);
        }
        break;

      case GAME:
        ergodox_infinity_lcd_color(8000, 8000, 100);
        if (is_keyboard_left()) {
          st7565_clear();
        }
        sprintf(buf, "%i", s_repeat_delay_ms);
        st7565_set_cursor(0, 1);
        st7565_write(buf, false);
        break;

      default:
        ergodox_infinity_lcd_color(0, 0, 0);
        st7565_clear();
        break;
    }
  }


  static uint8_t prev_delay = 0;
  if (layer == GAME &&
      is_keyboard_left() &&
      prev_delay != s_repeat_delay_ms) {
    sprintf(buf, "%i", s_repeat_delay_ms);
    st7565_set_cursor(0, 1);
    st7565_write(buf, false);
    prev_delay = s_repeat_delay_ms;
  }
};
#endif
