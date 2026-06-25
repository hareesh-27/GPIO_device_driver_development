#include "stm.h"
#include "gpio.h"

int main(void)
{
    GPIO_PINCONFIG_T config;

    // 1. INIT
    config.pin = 5;
    config.mode = GPIO_MODE_OUT;
    config.otype = GPIO_OP_TYPE_PP;
    config.speed = GPIO_SPEED_HIGH;
    config.pupdr = GPIO_NO_PUPD;
    config.alternatefunc = 0;

    GPIO_Init(GPIOA, &config);

    // 2. SET PIN
    GPIO_SetPin(GPIOA, 5);

    // 3. TOGGLE PIN
    GPIO_TogglePin(GPIOA, 5);

    // 4. READ PIN
    uint8_t val = GPIO_ReadPin(GPIOA, 5);

    while(1);
}
