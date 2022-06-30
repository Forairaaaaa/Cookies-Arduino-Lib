#ifndef _COOKIES_H_
#define _COOKIES_H_

/* Includes */
#include "Arduino.h"
#include "Wire.h"
#include "./FastLED/src/FastLED.h"
#include "./RGB-SEN/RGB_SEN.h"
#include "./TinyMotor/TinyMotor.h" 
#include "./TinyPMU/TinyPMU.h"

/* Config define */
#define COOKIES_VERSION "V1.0"

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

    /* RGBW sensor */
    RGB_SEN RGB_Sensor;

    /* Motor control */
    DRV8837 Motor;

    /* PMU */
    AXP173 PMU;

    /* RGB led control */
    CRGB leds[3];
    CFastLED RGB_LED;

};

#endif