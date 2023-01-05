#include QMK_KEYBOARD_H

#include <stdbool.h>
#include <stdint.h>

#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
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
 *                                        | Esc  | Tab  |       | PgDn | PgUp |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Super |       | Symb |        |      |
 *                                 |Space |Enter |------|       |------|  Del   | Bksp |
 *                                 |      |      | Ctrl |       |Media |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(  // Layer 0 : default
  // Left Hand
  KC_BSLS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LBRC,
  KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_RBRC,
  KC_TILDE, KC_PLUS,  KC_EQL,   KC_MINS,  KC_LALT,
                                                    KC_ESC,   KC_TAB,
                                                              KC_LGUI,
                                          KC_SPC,   KC_ENT,   KC_LCTL,
  // Right Hand
  KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_UNDS,
  KC_LCBR,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_PIPE,
            KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
  KC_RCBR,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLASH, KC_RSFT,
                      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_GRV,
  KC_PGDN,  KC_PGUP,
  MO(SYMB),
  MO(MDIA), KC_DEL,   KC_BSPC
),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | PrSrn   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  Bksp   |   7  |   8  |   9  |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   4  |   5  |   6  |   *  |   /  |------|           |------|      |   !  |   &  |   *  |  %   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    0    |   1  |   2  |   3  |   +  |   -  |      |           |      |      |   #  |   ^  |   $  |  @   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |   +  |   =  |   -  |   .  |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
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
  KC_NO,    KC_4,     KC_5,     KC_6,     KC_ASTR,  KC_SLASH,
  KC_0,     KC_1,     KC_2,     KC_3,     KC_PLUS,  KC_MINS,  KC_NO,
  KC_NO,    KC_PLUS,  KC_EQL,   KC_MINS,  KC_DOT,
                                                    KC_NO,    KC_NO,
                                                              KC_NO,
                                          KC_SPC,   KC_ENT,   KC_NO,
  // Right Hand
  KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_F12,
            KC_NO,    KC_EXLM,  KC_AMPR,  KC_ASTR,  KC_PERC,  KC_NO,
  KC_NO,    KC_NO,    KC_HASH,  KC_CIRC,  KC_DLR,   KC_AT,    KC_NO,
                      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,
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
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),               // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(MDIA)                // FN2 - Momentary Layer 2 (Media)
};

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
*/

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

void keyboard_post_init_user(void) {
  //debug_enable = true;
}

void st7565_task_user(void) {
  uint8_t layer = get_highest_layer(layer_state);

  switch (layer) {
    case SYMB:
      ergodox_infinity_lcd_color(60395, 52942, 15677);
      st7565_write("Symbol", false);
      break;
    case MDIA:
      ergodox_infinity_lcd_color(5911, 53713, 40092);
      st7565_write("Mouse", false);
      break;
    default:
      ergodox_infinity_lcd_color(800, 800, 800);
      st7565_clear();
      break;
  }
};
