#ifndef STM32F411XE_H
#define STM32F411XE_H

#include <stdint.h>

/* Base address */
#define AHB1PERIPH_BASEADDR 0x40020000U

/* GPIO base addresses */
#define GPIOA_BASEADDR (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOH_BASEADDR (AHB1PERIPH_BASEADDR + 0x1C00)

/* GPIO register structure */
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
} GPIO_RegDef;

/* GPIO port definitions */
#define GPIOA ((GPIO_RegDef*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef*)GPIOE_BASEADDR)
#define GPIOH ((GPIO_RegDef*)GPIOH_BASEADDR)

#endif
