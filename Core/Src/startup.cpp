#include "startup.h"
#include "main.h"

#include "OLED.h"

#include "key.h"

#include "common.h"

uint32_t millis()
{
	return HAL_GetTick();
}


void init()
{
	OLED_Init();
	initGame();
}

void startup()
{
	init();
	while(1)
	{
		uint32_t s = millis();
		updateGame();
		drawGame();

		OLED_Update();
		uint32_t d = millis() - s;
		if (d < 16)
			HAL_Delay(16 - d);
	}

}

























