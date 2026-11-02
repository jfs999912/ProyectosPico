#include "pico/stdlib.h"

int main() {
    stdio_init_all();

    const uint LED_PIN = 25;

    // 1. Inicializar el pad GPIO para conectarlo al periférico SIO
    gpio_init(LED_PIN);

    // 2. Establecer la dirección como salida (OBLIGATORIO)
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(3000);

        gpio_put(LED_PIN, 0);
        sleep_ms(2000);
    }

    return 0;
}

