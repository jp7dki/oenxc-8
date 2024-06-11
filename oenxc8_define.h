#ifndef OEEPB_1_DEFINE
#define OEEPB_1_DEFINE

#include "hardware/i2c.h"

// pin define
#define DEBUG_TX_PIN 0
#define DEBUG_RX_PIN 1
#define PWR_ON_PIN 17
#define SWA_PIN 18
#define SWB_PIN 19
#define SWC_PIN 16
#define LED1_PIN 24
#define LED2_PIN 25
#define LED3_PIN 26
#define LDO_ON 27
#define VBUS_DET 28

// GPS
#define GPS_TX_PIN 20
#define GPS_RX_PIN 21
#define GPS_RTS_PIN 23
#define PPS_PIN 29
#define UART_GPS uart1
#define BAUD_RATE_GPS 9600

// macro define
#define UART_DEBUG uart0
#define UART_DEBUG_BAUDRATE 115200
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY UART_PARITY_NONE

// BME280
#define SENS_SCK_PIN 2
#define SENS_SDI_PIN 3
#define SENS_SDO_PIN 4
#define SENS_CSB_PIN 5

#define READ_BIT 0x80

// R8900
#define RTC_SDA_PIN 6
#define RTC_SCL_PIN 7
#define RTC_I2C i2c0
#define RTC_BAUDRATE 400*1000            // I2C Baud rate (Hz)
#define RTC_ADDR 0b01100100


#endif