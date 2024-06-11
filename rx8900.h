#ifndef rx8900
#define rx8900

//-------------------------------------------------------
//- Header files include
//-------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "oeepb-1_define.h"

//---- RX8900 Config parameters -------------------------
typedef struct{
    
}Rx8900Config;

//---- RX8900 structure ---------------------------------
typedef struct rx8900 Rx8900;

struct rx9800
{
    
    void (*init)(void);
};

// Constructor
Rx8900 new_Rx8900(Rx8900Config);

#endif