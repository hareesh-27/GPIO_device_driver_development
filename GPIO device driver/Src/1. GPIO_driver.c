#include "GPIO_Driver.h"

/* Initialize GPIO Pin */
void GPIO_Init(GPIO_RegDef *port, GPIO_PINCONFIG_T *pinConfig)
{
    uint8_t pin = pinConfig->pin;

    /* 1. Configure MODER (2 bits per pin) */
    port->MODER &= ~(0x3 << (2 * pin));                     // clear
    port->MODER |= (pinConfig->mode << (2 * pin));          // set

    /* 2. Configure OTYPER (1 bit per pin) */
    port->OTYPER &= ~(1 << pin);
    port->OTYPER |= (pinConfig->otype << pin);

    /* 3. Configure OSPEEDR (2 bits per pin) */
    port->OSPEEDR &= ~(0x3 << (2 * pin));
    port->OSPEEDR |= (pinConfig->speed << (2 * pin));

    /* 4. Configure PUPDR (2 bits per pin) */
    port->PUPDR &= ~(0x3 << (2 * pin));
    port->PUPDR |= (pinConfig->pupdr << (2 * pin));

    /* 5. Configure Alternate Function (only if needed) */
    if(pinConfig->mode == GPIO_MODE_ALT)
    {
        if(pin < 8)
        {
            port->AFRL &= ~(0xF << (4 * pin));
            port->AFRL |= (pinConfig->alternatefunc << (4 * pin));
        }
        else
        {
            port->AFRH &= ~(0xF << (4 * (pin - 8)));
            port->AFRH |= (pinConfig->alternatefunc << (4 * (pin - 8)));
        }
    }
}

/* Set pin HIGH */
void GPIO_SetPin(GPIO_RegDef *port, uint8_t pin)
{
    port->ODR |= (1 << pin);
}

/* Toggle pin */
void GPIO_TogglePin(GPIO_RegDef *port, uint8_t pin)
{
    port->ODR ^= (1 << pin);
}

/* Read pin */
uint8_t GPIO_ReadPin(GPIO_RegDef *port, uint8_t pin)
{
    return (port->IDR >> pin) & 0x1;
}
