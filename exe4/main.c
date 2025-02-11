#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN = 28;
const int VERMELHO = 5;
const int ROXO = 8;
const int AZUL = 11;
const int AMARELO = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN);
  gpio_init(VERMELHO);  
  gpio_init(ROXO);  
  gpio_init(AZUL);  
  gpio_init(AMARELO);
  
  gpio_set_dir(BTN, GPIO_IN);
  gpio_set_dir(VERMELHO, GPIO_OUT);
  gpio_set_dir(ROXO, GPIO_OUT);
  gpio_set_dir(AZUL, GPIO_OUT);
  gpio_set_dir(AMARELO, GPIO_OUT);

  gpio_pull_up(BTN);

  while (true) {
    // Use delay de 300 ms entre os estados!
    if(!gpio_get(BTN)){
      gpio_put(VERMELHO, 1);
      sleep_ms(300);
      gpio_put(VERMELHO, 0);
      gpio_put(ROXO, 1);
      sleep_ms(300);
      gpio_put(ROXO, 0);
      gpio_put(AZUL, 1);
      sleep_ms(300);
      gpio_put(AZUL, 0);
      gpio_put(AMARELO, 1);
      sleep_ms(300);
      gpio_put(AMARELO, 0);
    }
  }
}
