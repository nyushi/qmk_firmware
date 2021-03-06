
#include QMK_KEYBOARD_H
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _MOVE 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  MOVE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOVE MO(_MOVE)

#define KC_LSANDS MT(MOD_LSFT, KC_SPC)
#define KC_RSANDS MT(MOD_RSFT, KC_SPC)
#define KC_LGUIE MT(MOD_LGUI, KC_LANG2)
#define KC_RGUIK MT(MOD_RGUI, KC_LANG1)
#define KC_LALTE MT(MOD_LALT, KC_LANG2)
#define KC_RALTK MT(MOD_RALT, KC_LANG1)
#define KC_LCANDE MT(MOD_LCTL, KC_ESC)
#define KC_LSFTANDE MT(MOD_LSFT, KC_ESC)
#define LOWERE LT(LOWER, KC_LANG2)
#define RAISEK LT(RAISE, KC_LANG1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             ,-----------------------------------------.
 * | `    |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | ESC  |Enter |   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |Lower | Alt  | GUI  |SandS | Ctrl |Bksp  |SandS | GUI  |  Alt |Raise |
 *               `---------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL, \
  KC_LCTL,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFTANDE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLASH , \
               KC_LALTE ,KC_LGUI,  KC_LSANDS,LOWER,    KC_BSPC, KC_ENT, RAISE,KC_RSANDS, KC_RGUI, KC_RALTK\
),

/* Colemak
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI | Ctrl |Lower |Space | Ctrl |Enter |Space |Raise |  Alt | GUI |
 *               `---------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_B,    KC_R,    KC_S,    KC_T,    KC_D,                   KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
                 KC_LGUI, KC_LALT,   LOWER,  KC_SPC, KC_LCTL,  KC_ENT, KC_SPC, RAISE,    KC_RALT, KC_RGUI\
),

/* Dvorak
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   [  |   ]  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI | Ctrl |Lower |Space | Ctrl |Enter |Space |Raise |  Alt |  GUI |
 *               `---------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                   KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, KC_LBRC, KC_RBRC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
                 KC_LGUI, KC_LALT,   LOWER,  KC_SPC, KC_LCTL,  KC_ENT, KC_SPC, RAISE,    KC_RALT, KC_RGUI\
),

/* Lower
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |  |   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |      |   \  |  |   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |ISO ~ |ISO | |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,  \
  _______, _______, _______, _______, _______, _______,                  KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT,  KC_COLN ,KC_DQT, \
  _______, _______, _______, _______, _______, _______,  _______, KC_MS_BTN2,_______,KC_MS_WH_UP,  KC_MS_WH_DOWN,    KC_GT, KC_QUES, KC_PIPE,\
                    _______, _______, KC_SPC, LOWER, _______, KC_MS_BTN1,  RAISE, KC_SPC, _______, _______\
),

/* Raise
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |   `  |   1  |   ↑  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * | Del  |   ←  |   ↓  |   →  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |ISO # |ISO / |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, \
  _______, _______, _______, _______, _______, _______,                    KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______, \
  KC_LSFT, KC_ACL0, KC_ACL1, KC_ACL2,   KC_F10,  KC_F11,  _______, _______,  _______,  KC_PGDOWN, KC_PGUP, _______, _______, _______, \
              _______, _______, KC_SPC, LOWER, MOVE, _______,  RAISE, KC_SPC, _______, _______\
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|             |Sat Up|Sat Dn|Val Up|Val Dn|      | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|             |AGswap|      |BL TOG|BL STP|      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  RESET,   RGB_TOG, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI,           RGB_VAD,   RGB_VAI,   RGB_M_P,   _______,  KC_SLCK,  KC_PAUSE, \
  KC_F1, KC_F2 , KC_F3, KC_F4, KC_F5, KC_F6,                   _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
  KC_F7, KC_F8, KC_F9,KC_F10,KC_F11, KC_F12,                 _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
  KC_LSFT, RGB_M_P,  RGB_M_B, RGB_M_R,  RGB_M_K, RGB_MOD, _______, _______, RGB_RMOD, KC_BTN1,KC_BTN2, _______, _______, _______, \
                    _______, _______, KC_SPC, _______, _______, _______, _______, KC_SPC, KC_BTN1, KC_BTN2\
),

[_MOVE] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______,   _______,   _______,   _______,  KC_SLCK,  KC_PAUSE, \
  _______, _______  , _______, _______, _______, _______,                  KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, _______, _______, \
  _______,  _______, _______,_______,_______, _______,                     _______, _______, _______, _______, _______, _______, \
  KC_LSFT, _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______,_______, _______, _______, \
                           _______, _______, KC_SPC, LOWER, MOVE,   _______, _______, KC_SPC, _______, _______\
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


static bool pressed = false;
static uint16_t now;
static uint16_t last;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(keycode != KC_COMMA){
    last = now;
    now = keycode;
  }
  if(!pressed && record->event.pressed){
    //rgblight_enable();
    rgblight_increase_val();
  }else if(pressed && !record->event.pressed){
    //rgblight_disable();
    rgblight_decrease_val();
  }
  pressed = record->event.pressed;

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case KC_EQL:
      // ctrl-= -> ctrl-[ 主にtmux用で、貼り付けはprefix =のchoose bufferを使うことにする
      if(keyboard_report->mods ==(MOD_BIT(KC_LCTRL)) && record->event.pressed){
          register_code(KC_LBRACKET);
          unregister_code(KC_LBRACKET);
          return false;
      }
      return true;
    case KC_COMMA:
      if(keyboard_report->mods ==(MOD_BIT(KC_LCTRL)) && record->event.pressed){
          unregister_code(KC_LCTRL);
          register_code(last);
          unregister_code(last);
          return false;
      }
      return true;
  }
  return true;
}

