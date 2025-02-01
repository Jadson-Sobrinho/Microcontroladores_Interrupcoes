#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include <math.h>
#include "lib/animacao_0.h"
#include "lib/animacao_1.h"
#include "lib/animacao_2.h"
#include "lib/animacao_4.h"
#include "lib/animacao_5.h"
#include "lib/animacao_6.h"
#include "lib/animacao_8.h"
#include "pio_matrix.pio.h"


#define NUMERO_DE_LEDS 25
#define OUT_PINO 7

//GPIO LEDS
#define GPIO_LED_RED 13
#define GPIO_LED_GREEN 11
#define GPIO_LED_BLUE 12


// Variáveis globais para controlar o estado do LED e o tempo
bool led_state = false;
int pisca_count = 0;
unsigned long last_time = 0;

// Função para alternar o estado do LED
void alternar_led() {
    led_state = !led_state;
    gpio_put(GPIO_LED_RED, led_state);
}

// Função para gerenciar o piscar do LED
void gerenciar_piscar_led(unsigned long current_time) {
    // 100ms para cada ciclo de acender/apagar o LED
    const unsigned long intervalo_piscar = 100;

    if (current_time - last_time >= intervalo_piscar) {
        alternar_led();
        last_time = current_time;
        if (led_state == false) {
            pisca_count++; // Conta somente os ciclos completos
        }

        // Reinicia o contador após 5 piscadas
        if (pisca_count >= 5) {
            pisca_count = 0;
            sleep_ms(1000); // Intervalo de 1 segundo após 5 piscadas
        }
    }
}

uint32_t matrix_rgb(double r, double g, double b) {
    unsigned char R, G, B;
    R = r * 255;
    G = g * 255;
    B = b * 255;
    return (G << 24) | (R << 16) | (B << 8);
}

void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    for (int16_t i = 0; i < NUMERO_DE_LEDS; i++) {
            valor_led = matrix_rgb(desenho[24 - i], desenho[24 - i], desenho[24 - i]);
            pio_sm_put_blocking(pio, sm, valor_led);
    }
}

void exibir_animacao(double* animacao[], int num_desenhos, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b, int delay_ms) {
    for (int i = 0; i < num_desenhos; i++) {
        desenho_pio(animacao[i], valor_led, pio, sm, r, g, b);
        sleep_ms(delay_ms);
    }
}


double* animacao_0[] = {desenho1, desenho2, desenho3, desenho4, desenho5, desenho6, desenho7, desenho8, desenho9};
int num_desenhos = sizeof(animacao_0) / sizeof(animacao_0[0]);



double* animacao_1[] = {frame_1_1, frame_1_2, frame_1_3, frame_1_4, frame_1_5, frame_1_6, frame_1_7};
int num_frames = sizeof(animacao_1) / sizeof(animacao_1[0]);


double* animacao_2[] = {frame0, frame1, frame2, frame3, frame4, frame5, frame6, frame7, frame8, frame9};
int num_desenhos2 = sizeof(animacao_2) / sizeof(animacao_2[0]);

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 3

*/


double* animacao_4[] = {desenho1_1, desenho2_2, desenho3_3, desenho4_4, desenho5_5, desenho6_6, desenho7_7, desenho8_8, desenho9_9, desenho10_10, desenho11_11, desenho12_12, desenho13_13, desenho14_14, desenho15_15};
int num_desenhos_4 = sizeof(animacao_4) / sizeof(animacao_4[0]);


double* animacao_5[] = {quadro0, quadro1, quadro2, quadro3, quadro4, quadro5, quadro6, quadro7, quadro8, quadro9, quadro10, quadro11, quadro12, quadro13, quadro14, quadro15, quadro16, quadro17, quadro18, quadro19, quadro20, quadro21};
int num_desenhos_5 = sizeof(animacao_5) / sizeof(animacao_5[0]);


double* animacao_6[] = {frame1_6, frame2_6, frame3_6, frame4_6, frame5_6, frame6_6, frame7_6, frame8_6, frame9_6};
int num_desenhos_6 = sizeof(animacao_6) / sizeof(animacao_6[0]);

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 7

*/


double* animacao_8[] = {frame1_8, frame2_8, frame3_8, frame4_8, frame5_8, frame6_8};
int num_desenhos_8 = sizeof(animacao_8) / sizeof(animacao_8[0]);



void acionar_animacao_0(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_0, num_desenhos, valor_led, pio, sm, r, g, b, 100);
}


void acionar_animacao_1(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b){
    exibir_animacao(animacao_1, num_frames, valor_led, pio, sm, r, g, b, 100);
}

/*
    TODO: Funcão para acionar a animação 2
*/

void acionar_animacao_2(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_2, num_desenhos2, valor_led, pio, sm, r, g, b, 100);
}

/*
    TODO: Funcão para acionar a animação 3

*/


void acionar_animacao_4(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_4, num_desenhos_4, valor_led, pio, sm, r, g, b, 100);
}

void acionar_animacao_5(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_5, num_desenhos_5, valor_led, pio, sm, r, g, b, 600);
}



void acionar_animacao_6(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_6, num_desenhos_6, valor_led, pio, sm, r, g, b, 100);
}


void acionar_animacao_8(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_8, num_desenhos_8, valor_led, pio, sm, r, g, b, 300);
}


// Estrutura para mapeamento de teclas e ações
typedef struct {
    char key;
    void (*action)(uint32_t, PIO, uint, double, double, double);
} KeyAction;

KeyAction key_actions[] = {
    {'0', acionar_animacao_0},
    {'1', acionar_animacao_1},
    {'2', acionar_animacao_2},
    {'4', acionar_animacao_4},
    {'5', acionar_animacao_5},
    {'6', acionar_animacao_6},
    {'8', acionar_animacao_8}
 
};

const int num_key_actions = sizeof(key_actions) / sizeof(key_actions[0]);

// Função para processar a tecla pressionada
void processar_tecla(char key, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    for (int i = 0; i < num_key_actions; i++) {
        if (key_actions[i].key == key) {
            key_actions[i].action(valor_led, pio, sm, r, g, b);
            return;
        }
    }

}

int main() {
    PIO pio = pio0;
    uint32_t valor_led = 0;
    double r = 0.0, b = 0.0, g = 0.0;

    set_sys_clock_khz(128000, false);
    stdio_init_all();


    //Inicialização dos LEDs
    gpio_init(GPIO_LED_RED);
    gpio_init(GPIO_LED_GREEN);
    gpio_init(GPIO_LED_BLUE);

    //Definindo os LEDs como saída
    gpio_set_dir(GPIO_LED_RED, GPIO_OUT);
    gpio_set_dir(GPIO_LED_GREEN, GPIO_OUT);
    gpio_set_dir(GPIO_LED_BLUE, GPIO_OUT);

    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, OUT_PINO);

    //Inicializa a matriz de leds desligados
    desenho_pio(desenho0, valor_led, pio, sm, r, g, b);

    

    while (true) {

        // Obtém o tempo atual em milissegundos
        unsigned long current_time = to_ms_since_boot(get_absolute_time());

        // Gerencia o piscar do LED
        gerenciar_piscar_led(current_time);

        char key = getchar_timeout_us(0); 


        if (key != 0) {

            printf("%c\n", key);
            processar_tecla(key, valor_led, pio, sm, r, g, b);

        }
        sleep_ms(10);

        
    }
}