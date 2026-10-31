#ifndef SC_INPUTMANAGER_H
#define SC_INPUTMANAGER_H

#include "common.h"

#include <stdbool.h>
#include <stdint.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>

#include "controller.h"
#include "file_pusher.h"
#include "options.h"
#include "trait/gamepad_processor.h"
#include "trait/key_processor.h"
#include "trait/mouse_processor.h"

struct sc_touch_binding {
    SDL_Keycode key;
    int32_t x;
    int32_t y;
    char *label;
    uint64_t pointer_id;
    bool pressed;
};

struct sc_input_manager {
    struct sc_controller *controller;
    struct sc_file_pusher *fp;
    struct sc_screen *screen;

    struct sc_key_processor *kp;
    struct sc_mouse_processor *mp;
    struct sc_gamepad_processor *gp;

    bool camera;

    struct sc_mouse_bindings mouse_bindings;
    bool legacy_paste;
    bool clipboard_autosync;

    struct sc_touch_binding *touch_bindings;
    size_t touch_bindings_count;

    // Visual editor state (BlueStacks-like)
    bool edit_mode;
    bool touch_dragging;
    struct sc_touch_binding *drag_binding;
    int drag_offset_x; // in window pixels
    int drag_offset_y;
    bool touch_placing; // waiting for a key after empty click
    int place_x; // window pixels
    int place_y;

    uint16_t sdl_shortcut_mods;

    bool vfinger_down;
    bool vfinger_invert_x;
    bool vfinger_invert_y;

    uint8_t mouse_buttons_state; // OR of enum sc_mouse_button values

    // Tracks the number of identical consecutive shortcut key down events.
    // Not to be confused with event->repeat, which counts the number of
    // system-generated repeated key presses.
    unsigned key_repeat;
    SDL_Keycode last_keycode;
    uint16_t last_mod;

    uint64_t next_sequence; // used for request acknowledgements

    bool disconnected;

    const char *touch_map_file;
    int touch_grid;
};

struct sc_input_manager_params {
    struct sc_controller *controller;
    struct sc_file_pusher *fp;
    struct sc_screen *screen;
    struct sc_key_processor *kp;
    struct sc_mouse_processor *mp;
    struct sc_gamepad_processor *gp;
    bool camera;

    struct sc_mouse_bindings mouse_bindings;
    bool legacy_paste;
    bool clipboard_autosync;
    const char *touch_map_file;
    int touch_grid;
    uint8_t shortcut_mods; // OR of enum sc_shortcut_mod values
};

void
sc_input_manager_init(struct sc_input_manager *im,
                      const struct sc_input_manager_params *params);

void
sc_input_manager_handle_event(struct sc_input_manager *im,
                              const SDL_Event *event);

void
sc_input_manager_release_touch_bindings(struct sc_input_manager *im);

#endif
