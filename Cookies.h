#ifndef _COOKIES_H_
#define _COOKIES_H_

/* Includes */
#include "Arduino.h"
#include "Wire.h"
#include "SPI.h"
#include "./FastLED/src/FastLED.h"
#include "./RGB-SEN/RGB_SEN.h"
#include "./TinyMotor/TinyMotor.h" 
#include "./TinyPMU/TinyPMU.h"


/* Cookies config */
#define COOKIES_VERSION  "V1.0"
#define COOKIES_PIN_SDA  21
#define COOKIES_PIN_SCL  20
#define COOKIES_PIN_RGB  10
#define COOKIES_EDP_MOSI 5
#define COOKIES_EDP_CLK  4
#define COOKIES_EDP_DC   5
#define COOKIES_EDP_RST  8
#define COOKIES_EDP_BUSY 9

/* Functions define */
#define _log_logo() Serial.println(CookiesLogo)
#define _log_string(log_tag, buff) Serial.printf("[%s]: %s\r\n", log_tag, buff)

/* Extern val */
extern const char CookiesLogo[];

/* Cookies class */
class COOKIES {
    private:
    
    public:
    /* Basic functions */
    void begin();
    int I2C_Scan();

    /* RGBW sensor */
    RGB_SEN RGB_Sensor;

    /* Motor control */
    DRV8837 Motor;

    /* PMU */
    AXP173 PMU;

    /* EPD */
    // GxIO_Class io(SPI, /*CS=*/ -1, /*DC=*/ 7, /*RST=*/ 8);
    // GxEPD_Class display(io, /*RST=*/ 6, /*BUSY=*/ 9);

    /* RGB led control */
    CRGB leds[3];
    CFastLED RGB_LED;
    void setRGB_LED(uint8_t led_id, CRGB::HTMLColorCode color, uint8_t brightness);
};

#endif