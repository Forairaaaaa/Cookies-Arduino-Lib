#ifndef _COOKIES_H_
#define _COOKIES_H_

#include "Arduino.h"
#include "Wire.h"
/* Sub lib */
#include "./RGB-SEN/RGB_SEN.h"
#include "./TinyMotor/TinyMotor.h"
#include "./TinyPMU/TinyPMU.h"

/* Cookies class */
class COOKIES {
    private:
    public:
    RGB_SEN RGB_Sensor;
};

#endif