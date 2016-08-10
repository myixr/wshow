#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "stm32f1xx_hal.h"
#include "user.h"
#include "led.h"
#include "usart.h"
#include "mpu6050.h"

#include "eMPL/inv_mpu.h"
#include "eMPL/inv_mpu_dmp_motion_driver.h"



extern UART_HandleTypeDef huart1;

void user_init1(){
}

void user_init2(){
	led_control( LED1, LED_ON );
	printf( "user init2 start\r\n" );

	mpu6050_init();
}

void user_loop(){
	long gyro[3],accel[3],quat[4];
	float w,x,y,z;
	unsigned long timestamp;
	short sensors;
	char more;
	dmp_read_fifo(gyro, accel, quat, &timestamp, &sensors, &more);
	//printf( "sensors=%d\r\n", sensors );
	if( sensors & INV_WXYZ_QUAT ){
		//printf( "%d,%d,%d,%d\r\n", quat[0],quat[1],quat[2],quat[3] );
		//http://www.cnblogs.com/wqj1212/archive/2010/11/21/1883033.html
		w = quat[0]/1073741824.0f;
		x = quat[1]/1073741824.0f;
		y = quat[2]/1073741824.0f;
		z = quat[3]/1073741824.0f;

		float a = atan2( 2*(w*x+yz),1-2*(x*x+y*y) );
		float b = asin( 2*(w*y-z*x) );
		float c = atan2( 2*(w*z+x*y),1-2*(y*y+z*z) );
	}
}
