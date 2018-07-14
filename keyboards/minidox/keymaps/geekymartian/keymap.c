#include "minidox.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  VIM_NEXT_TAB,
  VIM_PREV_TAB,
  VIM_PANE_DOWN,
  VIM_PANE_LEFT,
  VIM_PANE_RIGHT,
  VIM_PANE_UP,
  VIM_NEW_TAB,
  TMUX_NEXT_TAB,
  TMUX_PREV_TAB,
  TMUX_PANE_DOWN,
  TMUX_PANE_UP,
  TMUX_PANE_RIGHT,
  TMUX_PANE_LEFT,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |Shft/A|   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |Shft/;|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |ctl/Z |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |Ctl / |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | GUI | Space |LOWER |    |RAISE |Enter | alt  |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  SFT_T(KC_A),    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    SFT_T(KC_SCLN), \
  CTL_T(KC_Z),    KC_X,    KC_C,    KC_V, KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH), \
                    KC_LGUI, KC_SPC, LOWER,         RAISE, KC_ENT, KC_LALT                 \
),

/* Raise
 *
 * ,-----------------------------------.           ,----------------------------------.
 * | Tab  |  |   |  {   |  }   |Ctl+w  |           |  `   |      |  -   |   =  | BKspc|
 * |------+------+------+------+-------|           |------+------+------+------+------|
 * | Esc  |  ~   |  (   |  )   |c+gui+a|           |      |      |  Up  |      |      |
 * |------+------+------+------+-------|           |------+------+------+------+------|
 * |      |  '   |  [   |  ]   |       |           |      | Left | Down |Right |      |
 * `-----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | GUI | Space |LOWER |    |RAISE |Enter | Alt  |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
*/
[_RAISE] = LAYOUT( \
  KC_TAB, KC_BSLASH, KC_LCBR, KC_RCBR, LCTL(KC_W),           KC_GRAVE, _______, KC_MINUS, KC_EQUAL, KC_BSPC, \
  KC_ESC, KC_TILD, KC_LPRN, KC_RPRN, OSM(LCTL(LALT(KC_LGUI))),      _______, _______, KC_UP, _______, _______ , \
  _______, KC_QUOTE, KC_LBRC, KC_RBRC, _______,                 _______, KC_LEFT, KC_DOWN, KC_RGHT,  _______, \
                    _______, _______, _______,                 _______, _______, _______                    \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |MouseU|      |      |           |ViPTab|      |      |ViNTab|      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |MouseL|MouseD|MouseR|      |           |tmxPtb|      |      |tmxNtb|      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | GUI | Space |LOWER |    |RAISE |RmoBTN|LmoBTN|
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  _______,  _______, KC_MS_U, _______, _______,      VIM_PREV_TAB, _______, _______, VIM_NEXT_TAB, _______, \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,      TMUX_PREV_TAB, _______, _______, TMUX_NEXT_TAB, _______, \
                    _______, _______, _______,      _______,  KC_BTN1, KC_BTN2 \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      | Mute |VolUP |           |ViPanL|ViPanD|ViPanU|ViPanR|      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |VolDwn|           |TxPanL|TxPanD|TxPanU|TxPanR|      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | GUI | Space |LOWER |    |RAISE |Enter | Alet |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, KC__MUTE, KC__VOLUP,        VIM_PANE_LEFT, VIM_PANE_DOWN, VIM_PANE_UP, VIM_PANE_RIGHT, _______ , \
  RESET,   _______, _______, _______, KC__VOLDOWN,      TMUX_PANE_LEFT, TMUX_PANE_DOWN, TMUX_PANE_UP, TMUX_PANE_RIGHT,  _______, \
                    _______, _______, _______,      _______,  _______, _______                    \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    // TMUX shortcuts
    case TMUX_PREV_TAB:
      if (record->event.pressed) {
        SEND_STRING("`p");
      }
      return false;
      break;
    case TMUX_NEXT_TAB:
      if (record->event.pressed) {
        SEND_STRING("`n");
      }
      return false;
      break;
    case TMUX_PANE_LEFT:
      if (record->event.pressed) {
        SEND_STRING("`h");
      }
      return false;
      break;
    case TMUX_PANE_RIGHT:
      if (record->event.pressed) {
        SEND_STRING("`l");
      }
      return false;
      break;
    case TMUX_PANE_UP:
      if (record->event.pressed) {
        SEND_STRING("`k");
      }
      return false;
      break;
    case TMUX_PANE_DOWN:
      if (record->event.pressed) {
        SEND_STRING("`j");
      }
      return false;
      break;
    // VIM shortcuts
    case VIM_NEW_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)":tabe");
      }
      return false;
      break;
    case VIM_PANE_UP:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)SS_LCTRL("w")"k");
      }
      return false;
      break;
    case VIM_PANE_DOWN:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)SS_LCTRL("w")"j");
      }
      return false;
      break;
    case VIM_PANE_RIGHT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)SS_LCTRL("w")"l");
      }
      return false;
      break;
    case VIM_PANE_LEFT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)SS_LCTRL("w")"h");
      }
      return false;
      break;
    case VIM_PREV_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)"gT");
      }
      return false;
      break;
    case VIM_NEXT_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)"gt");
      }
      return false;
      break;
  }
  return true;
}
