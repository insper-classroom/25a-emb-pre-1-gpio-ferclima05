#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int B_VERMELHO = 28;
const int B_VERDE = 26;
const int L_VERMELHO = 4;
const int L_VERDE = 6;


int main() {
  stdio_init_all();

  gpio_init(B_VERMELHO);
  gpio_init(B_VERDE);
  gpio_init(L_VERMELHO);
  gpio_init(L_VERDE);

  gpio_set_dir(B_VERMELHO, GPIO_IN);
  gpio_set_dir(B_VERDE, GPIO_IN);
  gpio_set_dir(L_VERMELHO, GPIO_OUT);
  gpio_set_dir(L_VERDE, GPIO_OUT);

  gpio_pull_up(B_VERMELHO);
  gpio_pull_up(B_VERDE);

  while (true) {
    //printf("VERMELHO: %d\n", gpio_get(vermelho_state));
    //printf("VERDE: %d\n", gpio_get(verde_state));

    if(!gpio_get(B_VERMELHO)){
      if(gpio_get(L_VERMELHO)){
        gpio_put(L_VERMELHO, 0);
      } else {
        gpio_put(L_VERMELHO, 1);
      }
      while(!gpio_get(B_VERMELHO)){
      };

    } else if(!gpio_get(B_VERDE)){
      if(gpio_get(L_VERDE)){
        gpio_put(L_VERDE, 0);
      } else {
        gpio_put(L_VERDE, 1);
      }
      while(!gpio_get(B_VERDE)){
      };
    }
  }
}
