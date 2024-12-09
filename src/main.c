#include "main.h"
#include "adc.h"
#include "exti.h"
#include "gc9106.h"
#include "snake.h"

/*
 Pin Connections
╔══════════╦═════════╦══════════╦══════════╗
║ CH32v203 ║ PinMode ║ Joystick ║  GC9106  ║
╠══════════╬═════════╬══════════╬══════════╣
║ 3v3      ║ -       ║ VCC      ║ VCC      ║
║ GND      ║ -       ║ GNC      ║ GND      ║
║ PA5      ║ AFIO    ║ -        ║ SCL/SCK  ║
║ PA7      ║ AFIO    ║ -        ║ MOSI/SDA ║
║ PA2      ║ OUT     ║ -        ║ RES      ║
║ PA1      ║ OUT     ║ -        ║ DC       ║
║ PA4      ║ OUT     ║ -        ║ CS       ║
║ -        ║ -       ║ -        ║ BLK      ║
║ PB0      ║ AFIO    ║ X        ║ -        ║
║ PB1      ║ AFIO    ║ Y        ║ -        ║
║ PA0      ║ EXTI    ║ switch   ║ -        ║
╚══════════╩═════════╩══════════╩══════════╝
*/

void System_Init()
{
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n", SystemCoreClock);

    ADC_Periph_Init();
    ADC_Pin_Init();
    DMA_Periph_Init();

    Start_ADC_DMA();
    Delay_Ms(100);

    // Start SPI
    SPI1_Init();
    // Initialize GC9106
    GC9106_Init();
    // Set screen rotation (e.g., landscape)
    GC9106_SetRotation(1);

    Delay_Ms(100);

    GPIO_Switch_Init();
    EXTI_Switch_Init();
}

int main(void)
{

    System_Init();
    screen_Init();

    init_game(); // Initialize the game
    //dir = DIR_RIGHT;

    // Example input handling (replace with actual input mechanism)
    while (!game_over)
    {
        // handle_input('d'); // Simulate a key press ('d' for moving right)
        // game_loop();


        game_loop();
    }
}
