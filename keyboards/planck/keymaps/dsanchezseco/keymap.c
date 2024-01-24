#include QMK_KEYBOARD_H
#include "muse.h"

#include "keymap_dvorak.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ESC_CTL LCTL_T(KC_ESC)

extern keymap_config_t keymap_config;

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_grid(
    // SC_SENT -> space cadet enter key, shift when hold, enter when tap 
    KC_TAB,  DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    DV_F,    DV_G,    DV_C,    DV_R,    DV_L,    DV_SLSH,
    ESC_CTL, DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_D,    DV_H,    DV_T,    DV_N,    DV_S,    DV_MINS,
    KC_LSFT, DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,    DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,    SC_SENT, 
    KC_LCTL, _______, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_RGUI, KC_RALT, _______, KC_RCTL
),

[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RIGHT,KC_RPRN,
    _______, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_LEFT, DV_LCBR, DV_RCBR, DV_EQL,  KC_PIPE,
    _______, _______, _______, KC_DOWN, KC_UP,   _______, _______, _______, _______, KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_RIGHT, KC_0,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, DV_LBRC, DV_RBRC, DV_PLUS,  DV_BSLS,
    _______, _______, _______, KC_DOWN, KC_UP,   _______, _______, _______, _______, KC_PGUP, KC_PGDN,  _______,
    _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______,  _______
),

[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, _______, _______, _______,  _______,
    _______, KC_PSCR, _______, KC_DOWN, KC_UP,   _______, _______, _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
)

};

//void matrix_init_user(void) {
//        eeconfig_init();
//}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
