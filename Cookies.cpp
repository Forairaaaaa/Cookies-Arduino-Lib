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
    I2C_Scan();


    /* PMU init */
    if (PMU.begin(&Wire))
        _log_string("PMU", "Init error");
    else {
        /* Enable motor 1 power */
        // PMU.setOutputEnable(AXP173::OP_LDO3, true);
        // PMU.setOutputVoltage(AXP173::OP_LDO3, 2700);
        // /* Enable motor 2 power */
        // PMU.setOutputEnable(AXP173::OP_LDO2, true);
        // PMU.setOutputVoltage(AXP173::OP_LDO2, 2700);
        // /* Enable RGB LED power */
        // PMU.setOutputEnable(AXP173::OP_LDO4, true);
        // PMU.setOutputVoltage(AXP173::OP_LDO4, 3500);
        _log_string("PMU", "Init successful!");
    }

    /* Motor init */
    _log_string("MOTOR", "Motor init");
    Motor.begin();
    Motor.coast(DRV8837::M1);
    Motor.coast(DRV8837::M2);

    /* RGB Sensor init */
    if (RGB_Sensor.begin(&Wire))
        _log_string("RGB_SEN", "Init error");
    else
        _log_string("RGB_SEN", "Init successful!");

    /* RGB led init */
    _log_string("RGB-LED", "Init");
    FastLED.addLeds<WS2812, COOKIES_PIN_RGB, GRB>(leds, 3);
    setRGB_LED(0, CRGB::Red, 5);
    setRGB_LED(1, CRGB::Green, 5);
    setRGB_LED(2, CRGB::Blue, 5);
}


void COOKIES::setRGB_LED(uint8_t led_id, CRGB::HTMLColorCode color, uint8_t brightness) {
    leds[led_id] = color;
    FastLED.setBrightness(brightness);
    FastLED.show();
}

/**
 * @brief Scan I2C devices
 * 
 * @return int device number
 */
int COOKIES::I2C_Scan()
{
    if(!Wire.begin(COOKIES_PIN_SDA,COOKIES_PIN_SCL)) {
        _log_string("I2C_SCAN", "Init failed");
        return -1;
    }

    uint8_t error, address;
    int nDevices;

    _log_string("I2C_SCAN", "Device scanning...");

    nDevices = 0;
    for (address = 1; address < 127; address++ ) {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0) {
            Serial.print("[I2C_SCAN]: Device found at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.print(address, HEX);
            Serial.println(" !");

            nDevices++;
        }
        else if (error == 4) {
            _log_string("I2C_SCAN", "Unknow error at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.println(address, HEX);
        }
    }

    Serial.print("[I2C_SCAN]:");
    Serial.printf(" %d devices was found\r\n", nDevices);
    return nDevices;
}