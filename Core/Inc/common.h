#pragma once



/*  Defines  */


#define FPS             60
#define APP_TITLE       "ARDUBULLET"
#define APP_CODE        "OBN-Y13"
#define APP_VERSION     "0.11"
#define APP_RELEASED    "MARCH 2020"

#define GAME_RANK_MAX       10
#define GAME_RANK_DEFAULT   3

#define GAME_SEED_MAX       14348907UL  // = 27*27*27*27*27
#define GAME_SEED_TOKEN_MAX 5
#define GAME_SEED_TOKEN_VAL 27
#define GAME_SEED_TOKEN_ALP 26

enum MODE_T : uint8_t {
    MODE_LOGO = 0,
    MODE_TITLE,
    MODE_GAME,
};

/*  Typedefs  */

typedef struct {
    uint32_t    gameSeed:24;
    uint32_t    gameRank:4;
    uint32_t    isCodeManual:1;
    uint32_t    isBlinkLED:1;
    uint32_t    isDrawEdge:1;
    uint32_t    isCleared:1;
    uint32_t    playFrames;
    uint16_t    playCount;
} RECORD_T; // sizeof(RECORD_T) is 10 bytes

/*  Global Functions (Common)  */
int random(int left, int right);
int random(int right);

void    handleDPad(void);
void    drawTime(int16_t x, int16_t y, uint32_t frames);
void    drawButtonIcon(int16_t x, int16_t y, bool isB);


/*  Global Functions (Each Mode)  */

void    initLogo(void);
MODE_T  updateLogo(void);
void    drawLogo(void);

void    initTitle(void);
MODE_T  updateTitle(void);
void    drawTitle(void);

void    initGame(void);
MODE_T  updateGame(void);
void    drawGame(void);

/*  Global Variables  */


extern uint8_t  counter;
extern int8_t   padX, padY, padRepeatCount;
extern bool     isInvalid, isRecordDirty;

/*  For Debugging  */

#define dprint(...)
#define dprintln(...)
