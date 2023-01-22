#include QMK_KEYBOARD_H

#define SPLIT_LAYOUT( \
    L00, L01, L02, L03, L04, L05, \
    L10, L11, L12, L13, L14, L15, \
    L20, L21, L22, L23, L24, L25, \
    L30, L31, L32, L33, L34, L35, L45, \
              L40, L41, L42, L43, L44, \
\
         R00, R01, R02, R03, R04, R05, \
         R10, R11, R12, R13, R14, R15, \
         R20, R21, R22, R23, R24, R25, \
    R40, R30, R31, R32, R33, R34, R35, \
    R41, R42, R43, R44, R45            \
) \
    { \
        { L00, L01, L02, L03, L04, L05 }, \
        { L10, L11, L12, L13, L14, L15 }, \
        { L20, L21, L22, L23, L24, L25 }, \
        { L30, L31, L32, L33, L34, L35 }, \
        { L40, L41, L42, L43, L44, L45 }, \
        { R05, R04, R03, R02, R01, R00 }, \
        { R15, R14, R13, R12, R11, R10 }, \
        { R25, R24, R23, R22, R21, R20 }, \
        { R35, R34, R33, R32, R31, R30 }, \
        { R45, R44, R43, R42, R41, R40 } \
    }


#define SKC_DEAD_GRAVE ALGR(KC_GRAVE)
#define SKC_DEAD_SHARP ALGR(KC_E)
#define SKC_DEAD_CIRCUMFLEX ALGR(KC_I)
#define SKC_DEAD_UMLAUT ALGR(KC_U)


enum sofle_layers {
    _QWERTY,
    _ACCENT,
    // Using a separate layer instead of key override seems more space-efficient
    // accent won't work nicely with CAPSLOCK but I never need it.
    _SHIFT_ACCENT,
    _FUNCTION,
};

enum custom_keycodes {
    // _ACCENT
    SKC_OE = SAFE_RANGE,
    SKC_O_CIRCUMFLEX,
    SKC_E_GRAVE,
    SKC_E_SHARP,
    SCK_E_CIRCUMFLEX,
    SKC_A_GRAVE,
    SKC_A_UMLAUT,
    SKC_I_CIRCUMFLEX,
    SKC_I_UMLAUT,
    SKC_U_UMLAUT,
    SKC_U_GRAVE,
    SKC_C_CEDILLE,
    SKC_ESZETT,
    SKC_MICRO,
    SKC_EURO,
    SKC_DEGREE,
    // _SHIFT_ACCENT
    SKC_S_OE,
    SKC_S_O_CIRCUMFLEX,
    SKC_S_E_GRAVE,
    SKC_S_E_SHARP,
    SKC_S_E_CIRCUMFLEX,
    SKC_S_A_GRAVE,
    SKC_S_UMLAUT,
    SKC_S_I_CIRCUMFLEX,
    SKC_S_I_UMLAUT,
    SKC_S_U_UMLAUT,
    SKC_S_U_GRAVE,
    SKC_S_C_CEDILLE,
    // App-specific
    NEOVIM_KC_SAVE_ALL,
};

# define KITTY_MOD MOD_LCTL | MOD_LSFT
# define NEOVIM_W_KC_BSPC LT(0, KC_BSPC)


// ==============
// === LAYERS ===
// ==============

// XXXXXXX => Nothing
// _______ => transparent
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * _QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ↹  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   =  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+-------.    ,-------+------+------+------+------+------+------|
 * |   ⇧  |   Z  |   X  |   C  |   V  |   B  |       |    |       |   N  |   M  |   ,  |   .  |   /  |   ⇧  |
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+------+------'
 *               |   ⇱  |   ←  |   →  | ⎵  /F| Esc /K|    |  ⌫  /V| ↵  /A|   ↓  |   ↑  |   ⇲  |
 *               `-----------------------------------'    '-----------------------------------'
 */
[_QWERTY] = SPLIT_LAYOUT(
           KC_GRV,             KC_1,             KC_2,             KC_3,             KC_4,             KC_5,
           KC_TAB,             KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,
         KC_EQUAL,             KC_A,             KC_S,             KC_D,             KC_F,             KC_G,
          KC_LSFT,             KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,          XXXXXXX,
                                      LCTL_T(KC_HOME),  LALT_T(KC_LEFT), LGUI_T(KC_RIGHT), LT(_FUNCTION, KC_SPACE), MT(KITTY_MOD, KC_ESC),
// --------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----
                               KC_6,             KC_7,             KC_8,             KC_9,             KC_0,         KC_MINUS,
                               KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,     KC_BACKSLASH,
                               KC_H,             KC_J,             KC_K,             KC_L,          KC_SCLN,          KC_QUOT,
          XXXXXXX,             KC_N,             KC_M,          KC_COMM,           KC_DOT,          KC_SLSH,          KC_RSFT,
 NEOVIM_W_KC_BSPC, LT(_ACCENT, KC_ENT), RGUI_T(KC_DOWN),  RALT_T(KC_UP),   RCTL_T(KC_END)
    ),

/*
 * _ACCENT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |   €  |      |                    |      |      |   °  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   œ  |   è  |   é  |   ê  |      |                    |   ù  |   ü  |   î  |   ô  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  CW  |   à  |   ß  |   [  |   ]  |      |                    |      |      |   ï  |      |      |      |
 * |------+------+------+------+------+------+-------.    ,-------+------+------+------+------+------+------|
 * |   ⇧  |   ä  |   {  |   ç  |   }  |      |       |    |       |      |   µ  |      |      |      |   ⇧  |
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+------+------'
 *               |      |      |      |      |       |    |     /A|      |      |      |      |
 *               `-----------------------------------'    '-----------------------------------'
 */
[_ACCENT] = SPLIT_LAYOUT(
          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,         SKC_EURO,          XXXXXXX,
          KC_CAPS,           SKC_OE,      SKC_E_GRAVE,      SKC_E_SHARP, SCK_E_CIRCUMFLEX,          XXXXXXX,
          CW_TOGG,      SKC_A_GRAVE,       SKC_ESZETT,  KC_LEFT_BRACKET, KC_RIGHT_BRACKET,          XXXXXXX,
MO(_SHIFT_ACCENT),     SKC_A_UMLAUT, S(KC_LEFT_BRACKET),  SKC_C_CEDILLE, S(KC_RIGHT_BRACKET),       XXXXXXX,        XXXXXXX,
                                              XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
// --------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----
                            XXXXXXX,          XXXXXXX,       SKC_DEGREE,          XXXXXXX,          XXXXXXX,          XXXXXXX,
                        SKC_U_GRAVE,     SKC_U_UMLAUT, SKC_I_CIRCUMFLEX, SKC_O_CIRCUMFLEX,          XXXXXXX,          XXXXXXX,
                            XXXXXXX,          XXXXXXX,     SKC_I_UMLAUT,          XXXXXXX,          XXXXXXX,          XXXXXXX,
          XXXXXXX,          XXXXXXX,        SKC_MICRO,          XXXXXXX,          XXXXXXX,          XXXXXXX,MO(_SHIFT_ACCENT),
          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX
    ),

/*
 * _SHIFT_ACCENT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Œ  |   È  |   É  |   Ê  |      |                    |   Ù  |   Ü  |   Î  |   Ô  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   À  |      |      |      |      |                    |      |      |   Ï  |      |      |      |
 * |------+------+------+------+------+------+-------.    ,-------+------+------+------+------+------+------|
 * |      |   Ä  |      |   Ç  |      |      |       |    |       |      |      |      |      |      |      |
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+------+------'
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               `-----------------------------------'    '-----------------------------------'
 */
[_SHIFT_ACCENT] = SPLIT_LAYOUT(
          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
          XXXXXXX,         SKC_S_OE,    SKC_S_E_GRAVE,    SKC_S_E_SHARP, SKC_S_E_CIRCUMFLEX,        XXXXXXX,
          XXXXXXX,    SKC_S_A_GRAVE,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
          XXXXXXX,     SKC_S_UMLAUT,          XXXXXXX,  SKC_S_C_CEDILLE,          XXXXXXX,          XXXXXXX,          XXXXXXX,
                                              XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
// --------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----
                            XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
                      SKC_S_U_GRAVE,   SKC_S_U_UMLAUT, SKC_S_I_CIRCUMFLEX, SKC_S_O_CIRCUMFLEX,      XXXXXXX,          XXXXXXX,
                            XXXXXXX,          XXXXXXX,   SKC_S_I_UMLAUT,          XXXXXXX,          XXXXXXX,          XXXXXXX,
          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX
    ),

/*
 * _FUNCTION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F11 |  F12 |  F13 |  F14 |  F15 |                    |  F16 |  F17 |  F18 |  F19 |  F20 |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+-------.    ,-------+------+------+------+------+------+------|
 * |   ⇧  |      |      |      | Save |      |       |    |       |      |      |      |      |      |   ⇧  |
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+------+------'
 *               |   ⌃  |   ⌥  |   ⌘  |    /F|       |    |       |      |   ⌘  |   ⌥  |   ⌃  |
 *               `-----------------------------------'    '-----------------------------------'
 */
[_FUNCTION] = SPLIT_LAYOUT(
          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
          XXXXXXX,           KC_F11,           KC_F12,           KC_F13,           KC_F14,           KC_F15,
          XXXXXXX,            KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,
          KC_LSFT,          XXXXXXX,          XXXXXXX,          XXXXXXX, NEOVIM_KC_SAVE_ALL,        XXXXXXX,          XXXXXXX,
                                              KC_LCTL,          KC_LALT,          KC_LGUI,          XXXXXXX,          XXXXXXX,
// --------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----
                            XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
                             KC_F16,           KC_F17,           KC_F18,           KC_F19,           KC_F20,          XXXXXXX,
                              KC_F6,            KC_F7,            KC_F8,            KC_F9,           KC_F10,          XXXXXXX,
          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          KC_RSFT,
          XXXXXXX,          XXXXXXX,          KC_RGUI,          KC_RALT,          KC_RCTL
    ),

/*
 * EMPTY HOLD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------+-------.    ,-------+------+------+------+------+------+------|
 * |    ⇧ |    ⌃ |    ⌥ |    ⌘ |      |      |       |    |       |      |      |    ⌘ |    ⌥ |    ⌃ |    ⇧ |
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+------+------'
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               `-----------------------------------'    '-----------------------------------'
 */
// [_EMPTY_HOLD] = SPLIT_LAYOUT(
//           XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//           XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//           XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//   LSFT_T(XXXXXXX),  LCTL_T(XXXXXXX),  LALT_T(XXXXXXX),  LGUIT_(XXXXXXX),          XXXXXXX,          XXXXXXX,          XXXXXXX,
//                                               XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
// // --------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----
//                             XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//                             XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//                             XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//           XXXXXXX,          XXXXXXX,          XXXXXXX,  RGUI_T(XXXXXXX),  RALT_T(XXXXXXX),  RCTL_T(XXXXXXX),  RSFT_T(XXXXXXX),
//           XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX
//     ),
/*
 * EMPTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------+-------.    ,-------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+------+------'
 *               |      |      |      |      |       |    |       |      |      |      |      |
 *               `-----------------------------------'    '-----------------------------------'
 */
// [_EMPTY] = SPLIT_LAYOUT(
//           XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//           XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//           XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//           XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//                                               XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
// // --------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----
//                             XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//                             XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//                             XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//           XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,
//           XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX
//     ),
};


bool is_neovim_window_active = false;
bool delkey_registered = false;
uint8_t mod_state;
// Initialize variable holding the binary
// representation of active modifiers.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();

    switch (keycode) {
        case NEOVIM_W_KC_BSPC:
            if (!record->tap.count && record->event.pressed) { // Intercept hold function
                is_neovim_window_active = true;
                return false;
            } else {
                is_neovim_window_active = false;
                if (record->event.pressed) {
                    // Detect the activation of either shift keys
                    if (mod_state & MOD_MASK_SHIFT) {
                        // First temporarily canceling both shifts so that
                        // shift isn't applied to the KC_DEL keycode
                        del_mods(MOD_MASK_SHIFT);
                        register_code(KC_DEL);
                        // Update the boolean variable to reflect the status of KC_DEL
                        delkey_registered = true;
                        // Reapplying modifier state so that the held shift key(s)
                        // still work even after having tapped the Backspace/Delete key.
                        set_mods(mod_state);
                        return false;
                    }
                } else { // on release of KC_BSPC
                    // In case KC_DEL is still being sent even after the release of KC_BSPC
                    if (delkey_registered) {
                        unregister_code(KC_DEL);
                        delkey_registered = false;
                        return false;
                    }
                }
                return true;
            }
    }

    // Custom key codes
    if (record->event.pressed) {
        if (is_neovim_window_active) {
            clear_mods();
            tap_code16_delay(C(KC_W), 50);
            set_mods(mod_state);
        }

        switch (keycode) {
            case SKC_OE:
                tap_code16(ALGR(KC_Q));
                return false;
            case SKC_O_CIRCUMFLEX:
                tap_code16(SKC_DEAD_CIRCUMFLEX);
                tap_code(KC_O);
                return false;
            case SKC_E_GRAVE:
                tap_code16(SKC_DEAD_GRAVE);
                tap_code(KC_E);
                return false;
            case SKC_E_SHARP:
                tap_code16(SKC_DEAD_SHARP);
                tap_code(KC_E);
                return false;
            case SCK_E_CIRCUMFLEX:
                tap_code16(SKC_DEAD_CIRCUMFLEX);
                tap_code(KC_E);
                return false;
            case SKC_A_GRAVE:
                tap_code16(SKC_DEAD_GRAVE);
                tap_code(KC_A);
                return false;
            case SKC_A_UMLAUT:
                tap_code16(SKC_DEAD_UMLAUT);
                tap_code(KC_A);
                return false;
            case SKC_I_CIRCUMFLEX:
                tap_code16(SKC_DEAD_CIRCUMFLEX);
                tap_code(KC_I);
                return false;
            case SKC_I_UMLAUT:
                tap_code16(SKC_DEAD_UMLAUT);
                tap_code(KC_I);
                return false;
            case SKC_U_UMLAUT:
                tap_code16(SKC_DEAD_UMLAUT);
                tap_code(KC_U);
                return false;
            case SKC_U_GRAVE:
                tap_code16(SKC_DEAD_GRAVE);
                tap_code(KC_U);
                return false;
            case SKC_C_CEDILLE:
                tap_code16(ALGR(KC_C));
                return false;
            case SKC_ESZETT:
                tap_code16(ALGR(KC_C));
                return false;
            case SKC_MICRO:
                tap_code16(ALGR(KC_M));
                return false;
            case SKC_EURO:
                tap_code16(ALGR(S(KC_2)));
                return false;
            case SKC_DEGREE:
                tap_code16(ALGR(S(KC_8)));
                return false;
            // _SHIFT_ACCENT
            case SKC_S_OE:
                tap_code16(ALGR(S(KC_Q)));
                return false;
            case SKC_S_O_CIRCUMFLEX:
                tap_code16(SKC_DEAD_CIRCUMFLEX);
                tap_code16(S(KC_O));
                return false;
            case SKC_S_E_GRAVE:
                tap_code16(SKC_DEAD_GRAVE);
                tap_code16(S(KC_E));
                return false;
            case SKC_S_E_SHARP:
                tap_code16(SKC_DEAD_SHARP);
                tap_code16(S(KC_E));
                return false;
            case SKC_S_E_CIRCUMFLEX:
                tap_code16(SKC_DEAD_CIRCUMFLEX);
                tap_code16(S(KC_E));
                return false;
            case SKC_S_A_GRAVE:
                tap_code16(SKC_DEAD_GRAVE);
                tap_code16(S(KC_A));
                return false;
            case SKC_S_UMLAUT:
                tap_code16(SKC_DEAD_UMLAUT);
                tap_code16(S(KC_A));
                return false;
            case SKC_S_I_CIRCUMFLEX:
                tap_code16(SKC_DEAD_CIRCUMFLEX);
                tap_code16(S(KC_I));
                return false;
            case SKC_S_I_UMLAUT:
                tap_code16(SKC_DEAD_UMLAUT);
                tap_code16(S(KC_I));
                return false;
            case SKC_S_U_UMLAUT:
                tap_code16(SKC_DEAD_UMLAUT);
                tap_code16(S(KC_U));
                return false;
            case SKC_S_U_GRAVE:
                tap_code16(SKC_DEAD_GRAVE);
                tap_code16(S(KC_U));
                return false;
            case SKC_S_C_CEDILLE:
                tap_code16(ALGR(S(KC_C)));
                return false;
            case NEOVIM_KC_SAVE_ALL;
                tap_code(KC_ESC);
                tap_code(KC_SCLN);
                tap_code(KC_W);
                tap_code(KC_A);
                tap_code(KC_ENT);
                return false
        }
    }
    return true;
}

# define NEOVIM_UP C(KC_Y)
# define NEOVIM_DOWN C(KC_E)
# define NEOVIM_SCROLL_MULTIPLIER 5

// Meant for neovim
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Inversed
        if (clockwise) {
            for (uint8_t j = 0; j < NEOVIM_SCROLL_MULTIPLIER; j++) {
                tap_code16(NEOVIM_UP);
            }
        } else {
            for (uint8_t j = 0; j < NEOVIM_SCROLL_MULTIPLIER; j++) {
                tap_code16(NEOVIM_DOWN);
            }
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code16(NEOVIM_DOWN);
        } else {
            tap_code16(NEOVIM_UP);
        }
    }
    return true;
}

