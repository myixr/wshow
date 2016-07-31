#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "user.h"
#include "led.h"

extern UART_HandleTypeDef huart1;

void user_init1(){

}

void user_init2(){

	led_control( LED1, LED_OFF );
	led_control( LED2, LED_OFF );
	led_control( LED3, LED_OFF );
	led_control( LED4, LED_OFF );
	led_control( LED1, LED_ON );
	HAL_Delay( 200 );
	led_control( LED1, LED_OFF );
	HAL_Delay( 200 );
	led_control( LED1, LED_ON );
	HAL_Delay( 200 );
	led_control( LED1, LED_OFF );
	HAL_Delay( 200 );
	led_control( LED1, LED_ON );
	HAL_Delay( 200 );
	led_control( LED1, LED_OFF );

	HAL_UART_Transmit( &huart1, (uint8_t*)"Main start\r\n", 12, 0xFFFF );
}

void user_loop(){

}
