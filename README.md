# RP2040 Moving Average

This C library is an efficient implementation of the moving average filter.
It is a fork of Mohammad Hussein Tavakoli Bina's
[EfficientMovingAverage](https://github.com/mhtb32/EfficientMovingAverage).

## Usage Example
```c
#include <stdio.h>
#include "pico/stdlib.h"
#include "moving_average.h"

#define POTENTIOMETER_PIN   26 // Pin 26 is ADC0
uint16_t raw_reading;
uint16_t filtered_reading;

FilterTypeDef input_filtered;

int main() {
    stdio_init_all();
    adc_init();
    adc_gpio_init(POTENTIOMETER_PIN);
    adc_select_input(0);
    
    Moving_Average_Init(&input_filtered);
    
    while (1) {
        raw_reading = adc_read(); // 0 to 0xfff (4095)
        filtered_reading = Moving_Average_Compute(raw_reading, &input_filtered);
        sleep_ms(10);
    }
}
```
