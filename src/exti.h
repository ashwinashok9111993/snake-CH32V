#ifndef EXTI_H
#define EXTI_H

void GPIO_Switch_Init(void);
void EXTI_Switch_Init(void);
void EXTI0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

#endif