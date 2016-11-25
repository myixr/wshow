#ifndef _H_DISPLAY_
#define _H_DISPLAY_

#include "ledbar.h"


typedef struct Display *display_t;

void display_init( display_t *display );
void display_setImage( display_t display, int size, const color_t *img );
void display_show( float angle );

void display_setSize( float size );
float display_getSize( void );

void display_addBar( ledbar_t bar );
void display_delBar( ledbar_t bar );

#endif
