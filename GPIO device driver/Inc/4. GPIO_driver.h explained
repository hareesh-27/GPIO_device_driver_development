**First let us see why there are multiple enums created**  
Each enum represents a **different configuration category** of GPIO.  

--------------------

**Lets und the structure now**

```c
typedef struct
{
	uint8_t pin;
	GPIO_MODE_T mode;
	GPIO_OTYPER_T otype;
	GPIO_SPEED_T speed;
	GPIO_PUPDR_T pupdr;
	uint8_t alternatefunc;   // used only if mode = ALT

} GPIO_PINCONFIG_T;
```

The structure is used to hold all the configuration details of GPIO pin in a single place

---

**Functions :**  
In the .h file, we declare functions to inform other files that these functions exist and can be used
