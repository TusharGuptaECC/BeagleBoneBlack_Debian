#ifndef _GPIO_H_
#define _GPIO_H_

#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::ofstream;

#define GPIO_PATH "/sys/class/gpio/"

#define OUTPUT "out"
#define INPUT "in"
#define HIGH 1
#define LOW 0
#define INPUT_PULLUP "falling"
#define INPUT_PULLDOWN "rising"
#define INPUT_BOTH_PU_PD "both"
#define INPUT_NONE "none"

namespace ECC_gpio
{
        class GPIO;
}

class ECC_gpio::GPIO
{
        string path = string(GPIO_PATH);
        int pin_number;

        public:
                GPIO(int pin_number);
                virtual void gpioPinInit(int pin_number, string pin_direction, string pin_mode = "none");
                virtual void gpioWritePin(int pin_number, int pin_status);
                virtual int gpioReadPin(int pin_number);
                ~GPIO();
};


#endif