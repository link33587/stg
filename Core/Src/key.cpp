#include "main.h"
#include "key.h"


uint8_t is_left_button_pressed()
{
	if(HAL_GPIO_ReadPin(left_key_GPIO_Port, left_key_Pin)==1) return 1;
	return 0;

}
uint8_t is_right_button_pressed()
{
	if(HAL_GPIO_ReadPin(right_key_GPIO_Port, right_key_Pin)==1) return 1;
	return 0;

}
uint8_t is_down_button_pressed()
{
	if(HAL_GPIO_ReadPin(down_key_GPIO_Port, down_key_Pin)==1) return 1;
	return 0;

}
uint8_t is_up_button_pressed()
{
	if(HAL_GPIO_ReadPin(up_key_GPIO_Port, up_key_Pin)==1) return 1;
	return 0;

}
uint8_t is_A_button_pressed()
{
	if(HAL_GPIO_ReadPin(f1_key_GPIO_Port, f1_key_Pin)==1) return 1;
	return 0;

}
uint8_t is_B_button_pressed()
{
	if(HAL_GPIO_ReadPin(f2_key_GPIO_Port, f2_key_Pin)==1) return 1;
	return 0;

}

uint8_t is_dir_button_pressed()
{
	if(HAL_GPIO_ReadPin(left_key_GPIO_Port, left_key_Pin)==1) return 1;
	if(HAL_GPIO_ReadPin(right_key_GPIO_Port, right_key_Pin)==1) return 1;
	if(HAL_GPIO_ReadPin(down_key_GPIO_Port, down_key_Pin)==1) return 1;
	if(HAL_GPIO_ReadPin(up_key_GPIO_Port, up_key_Pin)==1) return 1;
	return 0;

}


void KeyLoop(void)
{
	unsigned char cnt=0;

	if(HAL_GPIO_ReadPin(left_key_GPIO_Port, left_key_Pin)==1){
		cnt |= KEY_L;  
	} 
	if(HAL_GPIO_ReadPin(right_key_GPIO_Port, right_key_Pin)==1)
	{
		cnt |= KEY_R;  
	}		
	if(HAL_GPIO_ReadPin(up_key_GPIO_Port, up_key_Pin)==1)
	{ 
		cnt |= KEY_U;  
	}
	if(HAL_GPIO_ReadPin(down_key_GPIO_Port, down_key_Pin)==1)
	{
		cnt |= KEY_D;  
	}		
	if(HAL_GPIO_ReadPin(f1_key_GPIO_Port, f1_key_Pin)==1)
	{
		cnt |= KEY_A;  
	}		
	if(HAL_GPIO_ReadPin(f2_key_GPIO_Port, f2_key_Pin)==1)
	{
		cnt |= KEY_B;  
	}	
	

}


