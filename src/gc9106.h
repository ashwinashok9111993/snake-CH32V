#ifndef GC9106_H
#define GC9106_H

#include "main.h"

// GPIO Pin Definitions
#define GC9106_RES_PIN GPIO_Pin_2 // Reset
#define GC9106_DC_PIN GPIO_Pin_1  // Data/Command
#define GC9106_CS_PIN GPIO_Pin_4  // Chip Select

#define GC9106_RES_PORT GPIOA
#define GC9106_DC_PORT GPIOA
#define GC9106_CS_PORT GPIOA

// Screen dimensions
#define GC9106_WIDTH 160
#define GC9106_HEIGHT 80

// Rotation values
#define ROTATION_0 0x48
#define ROTATION_90 0x28
#define ROTATION_180 0x88
#define ROTATION_270 0xE8

#define xoffset 1
#define yoffset 26

// RGB555 Color Definitions (5-bit Red, 5-bit Green, 5-bit Blue)
#define COLOR_BLACK 0x0000   // Black
#define COLOR_WHITE 0x7FFF   // White
#define COLOR_RED 0xF800     // Red
#define COLOR_GREEN 0x07E0   // Green
#define COLOR_BLUE 0x001F    // Blue
#define COLOR_YELLOW 0x7FFE  // Yellow
#define COLOR_CYAN 0x07FF    // Cyan
#define COLOR_MAGENTA 0xF81F // Magenta
#define COLOR_ORANGE 0xFC00  // Orange
#define COLOR_PURPLE 0x780F  // Purple
#define COLOR_BROWN 0xA145   // Brown
#define COLOR_PINK 0xF81F    // Pink
#define COLOR_GRAY 0x4B6D    // Gray
#define COLOR_LIME 0x07E0    // Lime Green
#define COLOR_INDIGO 0x4B1F  // Indigo

void GPIO_Reset(GPIO_TypeDef *port, uint16_t pin);
void GPIO_Set(GPIO_TypeDef *port, uint16_t pin);
void SPI1_Init(void);
void Lcd_WriteCommand(uint8_t cmd);
void Lcd_WriteData(uint8_t data);
void GC9106_Init(void);
void GC9106_SetRotation(uint8_t rotation);
void GC9106_FillScreen(uint16_t color);
void put_pixel(uint16_t x, uint16_t y, uint16_t color);
void put_line(int x1, int y1, int x2, int y2, uint16_t color);
void draw_char(uint16_t x, uint16_t y, char c, uint16_t color);
void draw_string(uint16_t x, uint16_t y, const char *str, uint16_t color);

#endif