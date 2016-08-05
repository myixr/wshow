#ifndef _PLATFORM_STM32_
#define _PLATFORM_STM32_

#include <math.h>
#include "stm32f1xx_hal_dma.h"
#include "stm32f1xx_hal_i2c.h"
#include "i2c.h"

#define __no_operation() __NOP()

inline int i2c_write(unsigned char slave_addr, unsigned char reg_addr,
		unsigned char length, unsigned char const *data)
{
	HAL_StatusTypeDef ret_status;
	ret_status = HAL_I2C_Mem_Write( &hi2c2, slave_addr, reg_addr, 8, (unsigned char*)data, length, 0xFFFF );
	return ret_status==HAL_OK;
}

inline int i2c_read(unsigned char slave_addr, unsigned char reg_addr,
		unsigned char length, unsigned char *data)
{
	HAL_StatusTypeDef ret_status;
	ret_status = HAL_I2C_Mem_Read( &hi2c2, slave_addr, reg_addr, 8, data, length, 0xFFFF );
	return ret_status==HAL_OK;
}

inline void delay_ms(unsigned long num_ms)
{
	HAL_Delay( num_ms );
}

inline void get_ms(unsigned long *count)
{
	*count =  HAL_GetTick();
}

inline void reg_int_cb(void (*cb)(void), unsigned char port, unsigned char pin)
{
	/* TODO */
}

#include <math.h>
/*
inline long  labs(long x){ return (x>0? x : -x); }
inline float fabsf(float x){ return (x>0? x : -x); };
*/
inline int   min(int a, int b){ return (a>b? b : a); }

#define log_i(...)     do {} while (0)
#define log_e(...)     do {} while (0)

#endif
