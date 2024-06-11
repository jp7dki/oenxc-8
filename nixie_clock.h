#ifndef NIXIE_CLOCK
#define NIXIE_CLOCK

//-------------------------------------------------------
//- Header files include
//-------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "nixie_clock_define.h"
#include "pico/util/datetime.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"
#include "hardware/flash.h"


#define BLANK_TIME 800

// PINK filter constant definition
#define MAX_Z 16

// FLASH
#define FLASH_TARGET_OFFSET (512 * 1024)

//---- Switch mode definition ------------
typedef enum{
    normal,
    fade,
    crossfade,
    cloud,
    dotmove
}SwitchMode; 

//---- Nixie Tube Dynamic-Drive Config parameters ----------
typedef struct
{
    uint8_t writed;
    uint8_t cursor;
    uint16_t switch_counter;
    bool flg_time_update;
    bool flg_change;
    uint8_t slice_num0;
    uint8_t disp_duty[6];
    uint8_t brightness;  

    uint8_t num[6];
    uint8_t next_num[6];
    uint8_t disp_change[6];
    uint8_t brightness_auto;
    uint8_t auto_onoff;
    datetime_t auto_off_time;
    datetime_t auto_on_time;
    datetime_t time_difference;

    uint8_t gps_correction;

    uint8_t led_setting;

    uint16_t fluctuation_level;

    SwitchMode switch_mode;

    bool random_start;
    uint16_t random_count;

} NixieConfig;

//---- Nixie Tube Non-volatile parameters ----------
typedef struct
{
    uint8_t writed;
    uint8_t brightness;  
    uint8_t brightness_auto;
    uint8_t auto_onoff;
    datetime_t auto_off_time;
    datetime_t auto_on_time;
    datetime_t time_difference;

    uint8_t gps_correction;

    uint8_t led_setting;

    uint16_t fluctuation_level;

    SwitchMode switch_mode;
} NixieConfigNvol;


typedef union Nvol_data{
    uint8_t flash_byte[FLASH_PAGE_SIZE];
    NixieConfigNvol nixie_config;
}NvolData;

static NvolData flash_data;

//---- Nixie Tube Dynamic-Drive structure -------------
typedef struct nixietube NixieTube;

struct nixietube
{
    NixieConfig conf;

    //---- initialization -----------
    void (*init)(NixieConfig *conf);
    void (*flash_init)(NixieConfig *conf);

    void (*brightness_inc)(NixieConfig *conf);
    void (*brightness_update)(NixieConfig *conf);
    void (*switch_mode_inc)(NixieConfig *conf);

    // dynamic drive task
    void (*dynamic_display_task)(NixieConfig *conf);
    void (*dynamic_animation_task)(NixieConfig *conf, uint8_t level);
    void (*dynamic_clock_task)(NixieConfig *conf);
    void (*dynamic_setting_task)(NixieConfig *conf, uint8_t setting_num);
    void (*dynamic_random_task)(NixieConfig *conf);
    void (*dynamic_demo_task)(NixieConfig *conf);
    void (*dynamic_timeadjust_task)(NixieConfig *conf);

    // tick second
    void (*clock_tick)(NixieConfig *conf, datetime_t time);
    //
    void (*switch_update)(NixieConfig *conf, datetime_t time);

    // startup animation
    void (*startup_animation)(NixieConfig *conf);

    // off/on_animation
    void (*dispoff_animation)(NixieConfig *conf);
    void (*dispon_animation)(NixieConfig *conf);
    void (*time_animation)(NixieConfig *conf, datetime_t time);

    void (*time_add)(NixieConfig *conf, datetime_t *time);

    // time_difference correction
    datetime_t (*get_time_difference_correction)(NixieConfig *conf, datetime_t time);

    // fluctuation level add
    void (*fluctuation_level_add)(NixieConfig *conf);

    // time adjust add
    void (*timeadjust_inc)(NixieConfig *conf);
    datetime_t (*get_adjust_time)(NixieConfig *conf);

    // parameter backup
    void (*parameter_backup)(NixieConfig *conf);

    // high voltage source power control
    void (*highvol_pwr_ctrl)(NixieConfig *conf, bool swon);
};

//---- constructor -------------
NixieTube new_NixieTube(NixieConfig Config);

#endif

