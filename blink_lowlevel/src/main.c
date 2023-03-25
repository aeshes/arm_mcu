#include <stm32f1xx.h>

void wait(long ms);
void init_gpio();

void main(void)
{
    init_gpio();

    while (1)
    {
        GPIOC->BSRR = GPIO_BSRR_BS8;
        wait(500);

        GPIOC->BSRR = GPIO_BSRR_BR8;
        wait(500);
    }
}

void wait(long ms)
{
    volatile long i = ms * 1000;
    while (i--);
}

void init_gpio()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH |= GPIO_CRH_MODE8;
    GPIOC->CRH &= ~GPIO_CRH_CNF8;
}