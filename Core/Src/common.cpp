#include <stdlib.h>
#include "main.h"
#include "common.h"
#include "key.h"
#include "OLED.h"
/*  Defines  */

#define EEPROM_ADDR_BASE    1008
#define EEPROM_SIGNATURE    0x134E424FUL // "OBN\x13"

#define PAD_REPEAT_DELAY    (FPS / 4)
#define PAD_REPEAT_INTERVAL (FPS / 12)

#define IMG_BUTTONS_W       7
#define IMG_BUTTONS_H       7

enum RECORD_STATE_T {
    RECORD_NOT_READ = 0,
    RECORD_INITIAL,
    RECORD_STORED,
};

/*  Global Variables  */

uint8_t     counter;
int8_t      padX, padY, padRepeatCount;
bool        isInvalid, isRecordDirty;

/*  Local Variables  */

static const uint8_t imgButtons[][7] = { // 7x7 x2
    { 0x3E, 0x47, 0x6B, 0x6D, 0x6D, 0x41, 0x3E },
    { 0x3E, 0x41, 0x55, 0x55, 0x51, 0x65, 0x3E }
};

/*---------------------------------------------------------------------------*/
/*                             Common Functions                              */
/*---------------------------------------------------------------------------*/



int random(int left, int right)
{
	int k=rand()%(right - left) + left;
	return k;
}

int random(int right)
{
	int k=rand()%right;
	return k;
}


void handleDPad(void)
{
    padX = padY = 0;
    if (is_dir_button_pressed() == 1) {
        if (++padRepeatCount >= (PAD_REPEAT_DELAY + PAD_REPEAT_INTERVAL)) {
            padRepeatCount = PAD_REPEAT_DELAY;
        }
        if (padRepeatCount == 1 || padRepeatCount == PAD_REPEAT_DELAY) {
            if (is_left_button_pressed())  padX--;
            if (is_right_button_pressed()) padX++;
            if (is_down_button_pressed())    padY--;
            if (is_up_button_pressed())  padY++;
        }
    } else {
        padRepeatCount = 0;
    }
}

void drawTime(int16_t x, int16_t y, uint32_t frames)
{
    uint16_t h = frames / (FPS * 3600UL);
    uint8_t m = frames / (FPS * 60) % 60;
    uint8_t s = frames / FPS % 60;
		OLED_ShowNum(x, y, s, 2, OLED_6X8);
		OLED_ShowChar(x+12, y, '.', OLED_6X8);
		OLED_ShowNum(x+18, y, frames / (FPS / 10) % 10, 1, OLED_6X8);
}


void drawButtonIcon(int16_t x, int16_t y, bool isB)
{
	 OLED_ShowImage(x, y, IMG_BUTTONS_W, IMG_BUTTONS_H, imgButtons[isB]);
}




