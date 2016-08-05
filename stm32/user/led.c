#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "led.h"

void led_control( LED_INDEX idx, LED_CONTROL ctrl ){
	static uint16_t pins[] = { GPIO_PIN_13 };
	assert_param( idx==LED1 );
	assert_param( ctrl==LED_ON || ctrl==LED_OFF || ctrl== LED_TURN );

	uint16_t pin = pins[idx];
	if( ctrl == LED_ON ){
		HAL_GPIO_WritePin( GPIOC, pin, GPIO_PIN_RESET );
	}
	else if( ctrl == LED_OFF ){
		HAL_GPIO_WritePin( GPIOC, pin, GPIO_PIN_SET );
	}
	else if( ctrl == LED_TURN ){
		GPIO_PinState state = HAL_GPIO_ReadPin( GPIOC, pin );
		if( state == GPIO_PIN_SET ) state = GPIO_PIN_RESET;
		else state = GPIO_PIN_SET;
		HAL_GPIO_WritePin( GPIOC, pin, state );
	}
}
