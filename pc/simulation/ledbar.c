#include "ledbar.h"
#include "mem.h"

struct LedBar{
    ledbar_config_t config;
    color_t *display_buffer;
};

void ledbar_init(ledbar_t *bar, const ledbar_config_t *config) {
    (*bar) = (ledbar_t)mem_alloc( sizeof(struct LedBar) );
    mem_copy( &(*bar)->config, config, sizeof(ledbar_config_t) );

    (*bar)->display_buffer = (color_t*)mem_alloc( sizeof(color_t)*config->led_count );
}

void ledbar_setConfig(ledbar_t *bar, const ledbar_config_t *config) {
    /* TODO */
    (void)bar;
    (void)config;
}

void ledbar_display( ledbar_t bar, const color_t *colors, int count ){
    int idx;
    for( idx=0; idx<count; ++idx ){
        bar->display_buffer[idx] = colors[idx];
    }
}

const ledbar_config_t *ledbar_getConfig(ledbar_t bar) {
    return &bar->config;
}

int ledbar_count(ledbar_t bar) {
    return bar->config.led_count;
}

float ledbar_offset(ledbar_t bar) {
    return bar->config.center_offset;
}

float ledbar_interval(ledbar_t bar) {
    return bar->config.interval;
}

color_t *ledbar_color( ledbar_t bar, int idx) {
    return bar->display_buffer+idx;
}

float ledbar_angle(ledbar_t bar) {
    return bar->config.angle;
}
