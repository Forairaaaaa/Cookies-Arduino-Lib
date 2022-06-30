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
    Wire.begin(21, 20);

    /* PMU init */
    if (PMU.begin(&Wire))
        _log_string("PMU", "Init error");
    else
        _log_string("PMU", "Init successful!");
    
    /* RGB led init */


    
}