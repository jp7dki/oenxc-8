#include "rx8900.h"

//--------------------------------------
// private function
//--------------------------------------
void rx8900_read_datetime(void){
    
}

//--------------------------------------
// public function
//--------------------------------------
static void rx8900_init(void)
{
    
    // i2c initialization
    i2c_init(I2C_RTC, I2C_RTC_BAUDRATE);
    
    gpio_set_function(RTC_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(RTC_SCL_PIN, GPIO_FUNC_I2C);
    gpio_set_pulls(RTC_SDA_PIN, false, false);
    gpio_set_pulls(RTC_SCL_PIN, false, false);

    
}


Rx8900 new_Rx8900(Rx8900Config Config)
{
    return ((Rx8900){
        .conf = Config,
        init = rx8900_init
    });
}