#include "main.h"
#include "stm32f30x_gpio.h"
#include "stm32f30x.h"
#include "stm32f30x_rcc.h"
#define zpozdion 5
#define zpozdioff 5

	uint32_t i = 0;
	uint32_t j = 0;
		
void zpozdeni(uint32_t zpozdi)
	{
		for(j = 0; j<zpozdion; j++)
		{
			for(i = 0; i<0xffff; i++); 
    }	
	}

int main(void)
{
	GPIO_InitTypeDef         GPIO_InitStructure;
	uint8_t button;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
    while (1)
    {
			/*button = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
			
			if(button==1)		
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			
			else
			GPIO_SetBits(GPIOA, GPIO_Pin_5);*/
			
			GPIO_SetBits(GPIOA, GPIO_Pin_5);
			zpozdeni(4);		
			
			/*0x ...... hexa; 0b ....... binar*/
			
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			zpozdeni(4);
	
		}
}

