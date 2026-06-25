**First is #ifndef and #endif**  
If multiple files include the same header (directly or indirectly), the header may get included multiple times during preprocessing, causing redefinition errors.

<img width="1615" height="343" alt="image" src="https://github.com/user-attachments/assets/88f840f8-0f28-48f8-9bdc-098d91be56e6" />

---

**Now the second part of the file**

```c
#define GPIOA_BASEADDR (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR (AHB1PERIPH_BASEADDR + 0x0400)
```

These macros define the **actual memory addresses of GPIO peripherals**

🔥 **Why we need these**  
Because:  
👉 GPIO hardware lives at fixed memory addresses  

👉 To access registers, we MUST know:  
where GPIOA is  
where GPIOB is  
etc  

These macros define the base addresses of GPIO peripherals, which are required to access their registers

---

**Now the structure**

```c
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
```

**First :**  
We use typedef with struct to create a new type name so that we can use the structure without writing the struct keyword every time, making the code cleaner and more readable.

**Now lets understand the need for this structure**  
The structure helps us access GPIO registers easily and correctly with the help of a pointer. More importantly this structure gives the layout of GPIO registers

---

**Finally**

```c
#define GPIOA ((GPIO_RegDef*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef*)GPIOC_BASEADDR)
```

We convert the address into a pointer to a structure so that we can access registers using names like MODER instead of raw addresses.

Layout :

```c
typedef struct
{
uint32_t MODER; // offset 0
uint32_t OTYPER; // offset 4
uint32_t OSPEEDR; // offset 8
uint32_t PUPDR; // offset 12
} GPIO_RegDef;
```

MODER → +0  
OTYPER → +4  
OSPEEDR → +8  
PUPDR → +12  

Now pointer

```c
#define GPIOA ((GPIO_RegDef*)0x40020000)
```

Now pointer

```c
#define GPIOA ((GPIO_RegDef*)0x40020000)
```

🔥 Now see the mapping  

🔹 GPIOA->MODER  
0x40020000 + 0 = 0x40020000  

👉 Accesses:  

MODER register  

🔹 GPIOA->OTYPER  
0x40020000 + 4 = 0x40020004
