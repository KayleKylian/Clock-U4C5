#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

// Define os pinos dos LEDs e do botão
#define LED_BLUE 11
#define LED_RED 12
#define LED_GREEN 13
#define BUTTON 5

// Variável para rastrear o estado do led
volatile int led_state = 0;
volatile bool led_on = false;

// Função de callback para mudar o estado dos LEDs
int64_t change_state_callback(alarm_id_t id, void *user_data) {
    // Verifica se o botão foi pressionado
    switch (led_state)
    {
    case 1:
        gpio_put(LED_BLUE, 0);
        printf("LED BLUE OFF\n");
        led_state = 2; // Preparando para o case 2
        return 3000 * 1000; // 3 segundos
    case 2:
        gpio_put(LED_RED, 0);
        printf("LED RED OFF\n");
        led_state = 3; // Preparando para o case 3
        return 3000 * 1000; // 3 segundos
    case 3:
        gpio_put(LED_GREEN, 0);
        printf("LED GREEN OFF\n");
        led_state = 0; // Encerra essa execução
        led_on = false;
        return 0;
    }
    return 0;
}

// Função de callback para o botão
void button_callback(uint gpio, uint32_t events) {
    if (!led_on) { 
        // Botão pressionado
        led_on = true;
        led_state = 1;

        // Liga os LEDs
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        gpio_put(LED_GREEN, 1);
        
        // Configura o alarme para desligar os LEDs
        add_alarm_in_ms(3000, change_state_callback, NULL, false);
    }
}

int main()
{
    stdio_init_all();

    // Configura os pinos dos LEDs
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);

    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Configura o botão
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    // Configura o callback do botão
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (true) {
        // Loop principal liberado para outras funcionalidades
        sleep_ms(1000);
    }
}
