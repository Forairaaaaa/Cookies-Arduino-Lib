#include "Cookies.h"

/* Cookies Logo */
const char CookiesLogo[] {
"\r\n ______  ______  ______  __  __  __  ______  ______\r\n"    
"/\\  ___\\/\\  __ \\/\\  __ \\/\\ \\/ / /\\ \\/\\  ___\\/\\  ___\\\r\n"   
"\\ \\ \\___\\ \\ \\/\\ \\ \\ \\/\\ \\ \\  _\"-\\ \\ \\ \\  __\\\\ \\___  \\\r\n"  
" \\ \\_____\\ \\_____\\ \\_____\\ \\_\\ \\_\\ \\_\\ \\_____\\/\\_____\\\r\n" 
"  \\/_____/\\/_____/\\/_____/\\/_/\\/_/\\/_/\\/_____/\\/_____/\r\n"
};

/* Public functions */
void COOKIES::begin() {
    /* Serial init */
    Serial.begin(115200);
    _log_logo();
    _log_string("Cookies", COOKIES_VERSION);
    _log_string("Cookies", "Initializing...");


    /* I2C init */
    Wire.begin(COOKIES_PIN_SDA, COOKIES_PIN_SCL);


    /* PMU init */
    if (PMU.begin(&Wire))
        _log_string("PMU", "Init error");
    else
        _log_string("PMU", "Init successful!");
    

    /* RGB led init */
    _log_string("RGB-LED", "Init");
    FastLED.addLeds<WS2812, COOKIES_PIN_RGB, GRB>(leds, 3);
    setRGB_LED(0, CRGB::YellowGreen, 10);
}


void COOKIES::setRGB_LED(uint8_t led_id, CRGB::HTMLColorCode color, uint8_t brightness) {
    leds[led_id] = color;
    FastLED.setBrightness(brightness);
    FastLED.show();
}