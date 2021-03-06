#ifndef HOWM_H
#define HOWM_H

#include <stdbool.h>
#include <stdint.h>
#include <xcb/xcb.h>
#include <xcb/xcb_ewmh.h>
#include <xcb/xproto.h>

#include "layout.h"
#include "types.h"

#define VERSION "0.5.1"
#define WM_NAME "howm"
#define CONF_NAME "howmrc"
#define HOWM_PATH "/usr/bin/howm"
#define ENV_SOCK_VAR "HOWM_SOCK"
#define DEF_SOCK_PATH "/tmp/howm"
#define IPC_BUF_SIZE 1024

#define WS_DEF_LAYOUT HSTACK
#define MASTER_RATIO 0.6
#define DEF_BORDER_FOCUS "#D33682"
#define DEF_BORDER_UNFOCUS "#073642"
#define DEF_BORDER_PREV_FOCUS "#B58900"
#define DEF_BORDER_URGENT "#DC322F"
#define GAP 0

/**
 * @file howm.h
 *
 * @author Harvey Hunt
 *
 * @date 2015
 *
 * @brief howm
 */

struct config {
	bool focus_mouse;
	bool focus_mouse_click;
	bool follow_move;
	uint16_t border_px;
	uint32_t border_focus;
	uint32_t border_unfocus;
	uint32_t border_prev_focus;
	uint32_t border_urgent;
	bool bar_bottom;
	uint16_t bar_height;
	uint16_t op_gap_size;
	bool center_floating;
	bool zoom_gap;
	uint16_t float_spawn_width;
	uint16_t float_spawn_height;
	unsigned int delete_register_size;
	uint16_t scratchpad_height;
	uint16_t scratchpad_width;
};

enum states { OPERATOR_STATE, COUNT_STATE, MOTION_STATE, END_STATE };

extern int retval;
extern xcb_connection_t *dpy;
extern uint16_t screen_height;
extern uint16_t screen_width;
extern int cur_state;
extern unsigned int mon_cnt;

extern monitor_t *mon;
extern monitor_t *mon_head;
extern monitor_t *mon_tail;
extern unsigned int workspace_cnt;

extern xcb_screen_t *screen;
extern xcb_ewmh_connection_t *ewmh;
extern bool running;

extern struct config conf;

extern const char *WM_ATOM_NAMES[];
extern xcb_atom_t wm_atoms[];

void howm_info(void);
uint32_t get_colour(char *colour);
void quit(const int exit_status);
void spawn(char *cmd[]);

#endif
