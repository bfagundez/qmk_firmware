#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  VIM_PASTE_LAST_REGISTER,
  VIM_NEXT_TAB,
  VIM_PREV_TAB,
  VIM_PANE_DOWN,
  VIM_PANE_LEFT,
  VIM_PANE_RIGHT,
  VIM_PANE_UP,
  VIM_NEW_TAB,
  VIM_V_SPLIT,
  VIM_H_SPLIT,
  VIM_OPEN_FOLDS,
  VIM_SAVE,
  TMUX_NEXT_TAB,
  TMUX_PREV_TAB,
  TMUX_PANE_DOWN,
  TMUX_PANE_UP,
  TMUX_PANE_RIGHT,
  TMUX_PANE_LEFT,
  TMUX_V_SPLIT,
  TMUX_H_SPLIT,
  TMUX_EDIT_MODE,
  TMUX_ZOOM,
  TMUX_NEW_TAB,
  SPCT_MAXIMIZE,
  SPCT_LEFT_HALF,
  SPCT_RIGHT_HALF,
  SCREENSHOT
};

// Fillers to make layering more clear
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------.               ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |               |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |               |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |               |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * | Ctrl |Adjust| Alt  | GUI  | Space| Lower|               |Raise |Enter | Down |  Up  |Right |      |
 * `-----------------------------------------'               `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
   KC_LCTL, ADJUST,  KC_LALT, KC_LGUI, KC_SPC,  LOWER,       RAISE,   KC_ENT,  KC_LEFT,KC_DOWN,  KC_UP,   KC_RIGHT  \
),

/* Lower
 * ,-----------------------------------------.               ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |               |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |ViPTab|      |viNwtb|viHSpl|viVspl|ViSave|               |ViPanL|ViPanD|ViPanU|ViPanR|      |ViNTab|
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |tmxPtb|txZoom|      |txHspl|txVspl|txEdit|               |TxPanL|TxPanD|TxPanU|TxPanR|      |tmxNtb|
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |ViPast|      |      |      |      |      |               |      |winLef|winMax|winRgt|      |      |
 * `-----------------------------------------'               `-----------------------------------------'
 */

[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRV, KC_1, KC_2,    KC_3,    KC_4,                                           KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  VIM_PREV_TAB, _______, VIM_NEW_TAB, VIM_H_SPLIT,  VIM_V_SPLIT,  VIM_SAVE,       VIM_PANE_LEFT,  VIM_PANE_DOWN,  VIM_PANE_UP,  VIM_PANE_RIGHT, _______, VIM_NEXT_TAB,  \
  TMUX_PREV_TAB, TMUX_ZOOM, _______, TMUX_H_SPLIT, TMUX_V_SPLIT, TMUX_EDIT_MODE,  TMUX_PANE_LEFT, TMUX_PANE_DOWN, TMUX_PANE_UP, TMUX_PANE_RIGHT, _______, TMUX_NEXT_TAB,\
  VIM_PASTE_LAST_REGISTER, _______, _______, _______, _______, _______,           _______, SPCT_LEFT_HALF,SPCT_MAXIMIZE, SPCT_RIGHT_HALF, _______, SCREENSHOT \
),

/* Raise
 * ,-----------------------------------------.               ,-----------------------------------------.
 * |      |      |  @   |  {   |  }   |   |  |               |  `   |  !   |  -   |   =  |      |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |      |  ~   |  (   |  )   |  _   |               | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |  *   |  #   |  [   |  ]   |  &   |               |  %   |   \  |  $   |  +   |  :   |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |      |      |      |      |      |               |      |      |      |      |      |      |
 * `-----------------------------------------'               `-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______,  _______, KC_AT,    KC_LCBR, KC_RCBR, KC_PIPE,      KC_GRAVE,   KC_EXCLAIM, KC_MINUS,  KC_EQUAL, _______, _______, \
  _______, _______, KC_TILD,  KC_LPRN, KC_RPRN, KC_UNDS,      KC_LEFT,KC_DOWN,  KC_UP,   KC_RIGHT, _______, KC_QUOTE,\
  _______, KC_ASTERISK, KC_HASH, KC_LBRC, KC_RBRC,  KC_AMPR,      KC_PERCENT, KC_BSLASH,  KC_DOLLAR, KC_PLUS ,  KC_COLON, _______,\
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______\
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------.               ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |               |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |mbtn1 |mbtn2 |      |mute  | vol+ | vol- |               |MouseL|MouseD|MouseU|MouseR|      |WheelU|
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |rgbhui|rgbvai|rgbsai|      |rgbmd>|VimzR |               |prev  |next  |play/p|      |      |WheelD|
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |rgbhud|rgbvad|rgbsad|rgbtog|<rgbmd|      |               |      |      |      |      |      |      |
 * `-----------------------------------------'               `-----------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  KC_F1,  KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                    KC_F7,   KC_F8,   KC_F9,    KC_F10, KC_F11, KC_F12, \
  KC_BTN1, KC_BTN2, _______, KC__MUTE, KC__VOLDOWN, KC__VOLUP,  KC_MS_L,  KC_MS_D, KC_MS_U, KC_MS_R,  _______, KC_WH_U,\
  RGB_HUI, RGB_VAI, RGB_SAI, _______, RGB_MOD, VIM_OPEN_FOLDS,         KC_MPRV, KC_MNXT, KC_MPLY,  _______, _______,  KC_WH_D, \
  RGB_HUD, RGB_VAD, RGB_SAD, RGB_TOG, RGB_RMOD, _______,        _______, _______, _______, _______,  _______, _______ \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
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
    case TMUX_ZOOM:
      if (record->event.pressed) {
        SEND_STRING("`z");
      }
      return false;
      break;
    case TMUX_EDIT_MODE:
      if (record->event.pressed) {
        SEND_STRING("`[");
      }
      return false;
      break;
    case TMUX_NEW_TAB:
      if (record->event.pressed) {
        SEND_STRING("`c");
      }
      return false;
      break;
    case TMUX_V_SPLIT:
      if (record->event.pressed) {
        SEND_STRING("`b");
      }
      return false;
      break;
    case TMUX_H_SPLIT:
      if (record->event.pressed) {
        SEND_STRING("`v");
      }
      return false;
      break;
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
    case VIM_PASTE_LAST_REGISTER:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)"\"0p");
      }
      return false;
      break;
    case VIM_NEW_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)":tabe"SS_TAP(X_ENTER));
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
    case VIM_H_SPLIT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)":sp"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case VIM_V_SPLIT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)":vsp"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case VIM_PREV_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)"gT");
      }
      return false;
      break;
    case VIM_OPEN_FOLDS:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)"zR");
      }
      return false;
      break;
    case VIM_NEXT_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)"gt");
      }
      return false;
      break;
    case VIM_SAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)":w"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case SPCT_MAXIMIZE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LGUI("m")));
      }
      return false;
      break;
    case SPCT_LEFT_HALF:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LGUI("h")));
      }
      return false;
      break;
    case SPCT_RIGHT_HALF:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LGUI("l")));
      }
      return false;
      break;
    case SCREENSHOT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LGUI("s")));
      }
      return false;
      break;
  }
  return true;
}
