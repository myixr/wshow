#include "ledbar.h"
#include "display.h"
#include "mem.h"
#include "list.h"

typedef struct LedBarListNode{
    ledbar_t ledbar;
    list_node_t list_node;
} ledbar_listnode_t;

typedef struct Display{
    color_t *img;
    int img_size;
    float size;
    list_head_t ledbars;
} *display_t;


void display_init(display_t *display) {
    (*display) = mem_alloc( sizeof(*display) );
    (*display)->img = NULL;
    (*display)->img_size = 0;

    list_init( &(*display)->ledbars );
}

void display_setImage(display_t display, int size, const color_t *img) {
    display->img = mem_alloc( sizeof(color_t)*size*size );
    display->img_size = size;
    mem_copy( display->img, img, sizeof(color_t)*size );
}

void display_show(float angle) {
    ledbar_t bar = NULL;
    color_t buff[20];

    float bar_angle = angle + ledbar_angle( bar );

}

void display_addBar(ledbar_t bar) {
    ledbar_listnode_t *node = mem_alloc( sizeof(ledbar_listnode_t) );
    list_append( bar->ledbars, node );
}


