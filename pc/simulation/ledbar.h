#ifndef _H_LED_BAR_
#define _H_LED_BAR_

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

typedef struct Color{
    uint8_t r;
    uint8_t g;
    uint8_t b;
}color_t;

typedef struct LedBarConfig{
    int   led_count;
    float angle;
    float center_offset;
    float interval;
}ledbar_config_t;

typedef struct LedBar *ledbar_t;

void ledbar_init( ledbar_t *bar, const ledbar_config_t *config );
void ledbar_display( ledbar_t bar, const color_t *colors, int count );
const ledbar_config_t *ledbar_getConfig( ledbar_t bar );

int  ledbar_count( ledbar_t bar );
float ledbar_offset( ledbar_t bar );
float ledbar_interval( ledbar_t bar );
float ledbar_angle( ledbar_t bar );
color_t *ledbar_color( ledbar_t bar, int idx );

#ifdef __cplusplus
}
#endif

#endif
