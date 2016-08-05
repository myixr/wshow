#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "user.h"
#include "led.h"

#include "eMPL/inv_mpu.h"
#include "eMPL/inv_mpu_dmp_motion_driver.h"


extern UART_HandleTypeDef huart1;

void user_init1(){
}

void user_init2(){
	led_control( LED1, LED_ON );
	HAL_UART_Transmit( &huart1, (uint8_t*)"Main start\r\n", 12, 0xFFFF );

	mpu_init( NULL );
	dmp_load_motion_driver_firmware();
}

void user_loop(){

}
