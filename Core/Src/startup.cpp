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

/*
基于STM32的飞机大战小游戏
效果演示视频链接：https://www.bilibili.com/video/BV1HoxfeFECU/

游戏效果可以 关注 微信公众号、B站、抖音和快手等平台（账号名称：JL单片机），有录制的视频的效果。
也分享了其他好玩有趣的代码，都可以去微信公众号下载。感兴趣的可以看下。


材料：
STM32F103C8T6最小系统板
SSD1306 OLED128*64显示屏
6个按键

IO接线说明：
向下按键：PA4
向右按键：PA5
向上按键：PB11
向左按键：PB10
A按键：PA6
B按键：PA7

OLED SCK：PA11
OLED SDA：PA12
*/
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

























