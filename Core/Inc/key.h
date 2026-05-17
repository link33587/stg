#ifndef KEY_H
#define KEY_H
#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
#define KEY_REPEAT_CNT			10
#define _BV(bit) (1 << (bit))
	
//---------------------------------------------------------------------------

enum {
	KEY_U = _BV(7),
	KEY_R = _BV(6),
	KEY_L = _BV(5),
	KEY_D = _BV(4),
	KEY_A = _BV(3),
	KEY_B = _BV(2),

	DPAD  = (KEY_U | KEY_D | KEY_L | KEY_R),
};


uint8_t is_left_button_pressed();
uint8_t is_right_button_pressed();
uint8_t is_down_button_pressed();
uint8_t is_up_button_pressed();
uint8_t is_A_button_pressed();
uint8_t is_B_button_pressed();

uint8_t is_dir_button_pressed();

#ifdef __cplusplus
}
#endif
#endif
