# Documentação do Código

## Visão Geral
Este programa foi desenvolvido para o Raspberry Pi Pico e tem como objetivo controlar uma matriz de LEDs e exibir diferentes animações. O programa gerencia a exibição das animações com base na interação do usuário através de botões físicos para incrementar e decrementar as animações e um temporizador de pisca-pisca.

## Dependências
O código depende das seguintes bibliotecas:
- **pico/stdlib.h**: Fornece funções padrão para o Raspberry Pi Pico.
- **hardware/pio.h**: Controla o hardware PIO (Programável I/O) do RP2040.
- **hardware/clocks.h**: Gerencia a configuração dos clocks do sistema.
- **hardware/adc.h**: Permite o uso do conversor analógico-digital (ADC).
- **pico/bootrom.h**: Contém funções para acesso ao bootloader do Pico.
- **math.h**: Fornece funções matemáticas.
- **pio_matrix.pio.h**: Arquivo contendo o programa PIO para controle da matriz de LEDs.
- **Arquivos de animação**: Contêm os frames de animação usados no código.

## Definições e Variáveis Globais
- **NUMERO_DE_LEDS**: Define a quantidade de LEDs na matriz (25).
- **OUT_PINO**: Define o pino de saída do PIO.
- **GPIO_LED_RED, GPIO_LED_GREEN, GPIO_LED_BLUE**: Pinos GPIO para controle de LEDs individuais.
- **DEBOUNCE_TIME_MS**: Tempo de debounce para evitar leituras errôneas dos botões.
- **button_0, button_1**: Pinos dos botões de controle da animação.
- **animacao_atual**: Controla qual animação está sendo exibida.
- **num_animacoes**: Define o número total de animações.

## Funções Principais

### `repeating_timer_callback(struct repeating_timer *t)`
- Alterna o estado do LED vermelho periodicamente.

### `matrix_rgb(double r, double g, double b)`
- Converte valores RGB para um formato compatível com a matriz de LEDs.

### `desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm)`
- Atualiza os LEDs da matriz com base em um desenho recebido como parâmetro.

### `exibir_animacao(double* animacao[], int num_desenhos, uint32_t valor_led, PIO pio, uint sm)`
- Exibe uma animação na matriz de LEDs caso ela esteja ativada.

### `gpio_irq_handler(uint gpio, uint32_t events)`
- Gerencia as interrupções dos botões e altera o estado das animações exibidas.

### `executar_animacao(int animacao_idx, uint32_t valor_led, PIO pio, uint sm)`
- Executa a animação correspondente ao índice fornecido.

## Fluxo Principal (`main`)
1. Inicializa os pinos GPIO e a matriz de LEDs.
2. Configura os botões de interrupção.
3. Inicializa o temporizador para piscar o LED.
4. Entra em um loop infinito para verificar e exibir animações sempre que estiverem ativas.

## Considerações Finais
Este código permite alternar entre 10 animações diferentes por meio da interação do usuário. A utilização do PIO garante uma atualização eficiente da matriz de LEDs.

