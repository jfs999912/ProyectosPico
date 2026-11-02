#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Pines candidatos para el LED monocromático en YD-RP2040
const uint pins[] = {24, 25, 26};
#define NUM_PINS 3

void init_pwm_pin(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(pin);
    pwm_set_clkdiv(slice, 4.0f);
    pwm_set_wrap(slice, 255);
    pwm_set_enabled(slice, true);
}

int main() {
    stdio_init_all();

    for (int i = 0; i < NUM_PINS; i++) {
        init_pwm_pin(pins[i]);
    }

    while (true) {
        // Rampa ascendente (fade in) en todos los pines candidatos
        for (int duty = 0; duty <= 255; duty += 5) {
            for (int i = 0; i < NUM_PINS; i++) {
                pwm_set_gpio_level(pins[i], duty);
            }
            sleep_ms(20);
        }

        // Rampa descendente (fade out)
        for (int duty = 255; duty >= 0; duty -= 5) {
            for (int i = 0; i < NUM_PINS; i++) {
                pwm_set_gpio_level(pins[i], duty);
            }
            sleep_ms(20);
        }
    }

    return 0;
}
