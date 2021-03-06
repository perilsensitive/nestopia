#ifndef _VIDEO_H_
#define _VIDEO_H_

#define TV_WIDTH 292
#define OVERSCAN_LEFT 0
#define OVERSCAN_RIGHT 0
#define OVERSCAN_BOTTOM 8
#define OVERSCAN_TOP 8

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_endian.h>
#include "GL/glu.h"

// This is part of an elaborate hack to embed the SDL window
struct SDL_Window {
	const void *magic;
	Uint32 id;
	char *title;
	SDL_Surface *icon;
	int x, y;
	int w, h;
	int min_w, min_h;
	int max_w, max_h;
	Uint32 flags;
};
typedef struct SDL_Window SDL_Window;
//

typedef struct {
	int w;
	int h;
} dimensions_t;

void opengl_init_structures();
void opengl_cleanup();
void opengl_blit();

void video_init();
void video_create_standalone();
void video_create_embedded();
void video_create();
void video_toggle_fullscreen();
void video_toggle_filter();
void video_toggle_filterupdate();
void video_toggle_scalefactor();
void video_set_filter();
void video_set_dimensions();
void video_set_cursor();
void video_set_title(const char *title);

long video_lock_screen(void*& ptr);
void video_unlock_screen(void*);

#endif
