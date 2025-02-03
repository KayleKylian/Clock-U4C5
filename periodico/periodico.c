#include "pico/stdlib.h"
#include "hardware/timer.h"
#include <stdio.h>

// Definição das GPIOs dos LEDs
#define LED_RED 11
#define LED_YELLOW  12
#define LED_GREEN    13

// Variável global para rastrear o estado do semáforo
int estado_atual = 0;

// Callback do temporizador periódico (altera o semáforo)
bool semaforo_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs
    gpio_put(LED_RED, 0);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);

    // Alterna o estado do semáforo
    switch (estado_atual) {
        case 0:
            gpio_put(LED_RED, 1);
            printf("Semáforo: Vermelho\n");
            break;
        case 1:
            gpio_put(LED_YELLOW, 1);
            printf("Semáforo: Amarelo\n");
            break;
        case 2:
            gpio_put(LED_GREEN, 1);
            printf("Semáforo: Verde\n");
            break;
    }

    // Atualiza o estado para o próximo ciclo
    estado_atual = (estado_atual + 1) % 3;
    return true; // Retorna true para continuar repetindo o timer
}

int main() {
    stdio_init_all();

    // Configura as GPIOs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Inicializa o temporizador periódico (3s)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, semaforo_callback, NULL, &timer);

    // Loop principal com mensagens a cada segundo
    while (true) {
        printf("Sistema rodando...\n");
        sleep_ms(1000);
    }
}
