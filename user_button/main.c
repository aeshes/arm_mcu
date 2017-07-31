#define STM32F10X_MD_VL

#include "include/stm32f10x_conf.h"

void Delay(uint32_t nTime);
void InitLED(void);
void InitButton(void);


int main(void)
{
	InitLED();
	InitButton();

	//Configure SysTick timer
	if (SysTick_Config(SystemCoreClock / 1000))
		while (1);

	while (1);
}


static __IO uint32_t TimingDelay;

void Delay(uint32_t nTime)
{
	TimingDelay = nTime;
	while (TimingDelay != 0);
}

void SysTick_Handler(void)
{
	if (TimingDelay != 0x00)
		--TimingDelay;

	uint8_t in = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
	GPIO_WriteBit(GPIOC, GPIO_Pin_0, in);
}

void InitButton(void)
{
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	gpio.GPIO_Pin = GPIO_Pin_0;
	gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &gpio);
}

void InitLED(void)
{
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	gpio.GPIO_Pin = GPIO_Pin_0;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio);
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
	while (1);
}
#endif
