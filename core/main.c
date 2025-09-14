#include "stm32f103xb.h"

static void delay(volatile uint32_t count)
{
    while (count--) {
        __asm__("nop");
    }
}

int main(void)
{
    // Enable clock for GPIOA 
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // Configure PA5 as push-pull output, max speed 2 MHz
    GPIOA->CRL &= ~(GPIO_CRL_MODE5 | GPIO_CRL_CNF5); 
    GPIOA->CRL |= (0x2 << GPIO_CRL_MODE5_Pos);       
    GPIOA->CRL |= (0x0 << GPIO_CRL_CNF5_Pos);        

    while (1)
    {
        // Toggle PA5
        GPIOA->ODR ^= (1 << 5);

        delay(800000);
    }
}

