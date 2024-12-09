#include "main.h"
#include "exti.h"

void GPIO_Switch_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU; // Input with pull-up
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}

// Initialize EXTI for PA12
void EXTI_Switch_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    // Connect PA12 to EXTI Line 12
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);

    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line = EXTI_Line0;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling; // Falling edge
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStruct);

    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn; // EXTI_Line0 interrupt
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x01;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x01;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
}

void EXTI0_IRQHandler(void)
{
    // Check if EXTI_Line0 triggered the interrupt
    if (EXTI_GetITStatus(EXTI_Line0) != RESET)
    {
        // Handle the interrupt (e.g., toggle an LED)
        JoystickPressed = true;
    }
    // Clear the interrupt flag
    EXTI_ClearITPendingBit(EXTI_Line0);
}
