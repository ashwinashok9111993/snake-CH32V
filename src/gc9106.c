#include "gc9106.h"

// 5x8 font definition (ASCII characters 32-127)
uint8_t font5x8[128][5] = {
    // Basic ASCII characters (space to ~)
    // Each character is represented by 5 bytes, one for each column
    {0x00, 0x00, 0x00, 0x00, 0x00}, // (0)
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},

    {0x00, 0x00, 0x00, 0x00, 0x00}, // (10)
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},

    {0x00, 0x00, 0x00, 0x00, 0x00}, // (20)
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},

    {0x00, 0x00, 0x00, 0x00, 0x00}, // (30)
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00}, // space
    {0x00, 0x00, 0xFD, 0x00, 0x00}, // !
    {0x00, 0xE0, 0x00, 0xE0, 0x00}, // "
    {0x24, 0xFF, 0x24, 0xFF, 0x24}, // #
    {0x12, 0x2A, 0x7F, 0x2A, 0x24}, // $
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x76, 0x89, 0x95, 0x62, 0x05}, // &
    {0x00, 0xA0, 0xC0, 0x00, 0x00}, // '

    {0x00, 0x3C, 0x42, 0x81, 0x00}, // ( (40)
    {0x00, 0x81, 0x42, 0x3C, 0x00}, // )
    {0x14, 0x08, 0x3E, 0x08, 0x14}, // *
    {0x08, 0x08, 0x3E, 0x08, 0x08}, // +
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x08, 0x08, 0x08, 0x08, 0x08}, // -
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x7E, 0x89, 0x91, 0xA1, 0x7E}, // 0
    {0x00, 0x41, 0xFF, 0x01, 0x00}, // 1

    {0x43, 0x85, 0x89, 0x91, 0x61}, // 2 (50)
    {0x42, 0x81, 0x91, 0x91, 0x6E}, // 3
    {0x18, 0x28, 0x48, 0xFF, 0x08}, // 4
    {0xF2, 0x91, 0x91, 0x91, 0x8E}, // 5
    {0x1E, 0x29, 0x49, 0x89, 0x86}, // 6
    {0x80, 0x8F, 0x90, 0xA0, 0xC0}, // 7
    {0x6E, 0x91, 0x91, 0x91, 0x6E}, // 8
    {0x70, 0x89, 0x89, 0x8A, 0x7C}, // 9
    {0x00, 0x36, 0x36, 0x00, 0x00}, // :
    {0x00, 0x35, 0x36, 0x00, 0x00}, // ;

    {0x00, 0x00, 0x00, 0x00, 0x00}, // (60)
    {0x14, 0x14, 0x14, 0x14, 0x14}, // =
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x60, 0x80, 0x8D, 0x90, 0x60}, // ?
    {0x66, 0x89, 0x8F, 0x81, 0x7E}, // @
    {0x7F, 0x88, 0x88, 0x88, 0x7F}, // A
    {0xFF, 0x91, 0x91, 0x91, 0x6E}, // B
    {0x7E, 0x81, 0x81, 0x81, 0x42}, // C
    {0xFF, 0x81, 0x81, 0x42, 0x3C}, // D
    {0xFF, 0x91, 0x91, 0x91, 0x81}, // E

    {0xFF, 0x90, 0x90, 0x90, 0x80}, // F (70)
    {0x7E, 0x81, 0x89, 0x89, 0x4E}, // G
    {0xFF, 0x10, 0x10, 0x10, 0xFF}, // H
    {0x81, 0x81, 0xFF, 0x81, 0x81}, // I
    {0x06, 0x01, 0x01, 0x01, 0xFE}, // J
    {0xFF, 0x18, 0x24, 0x42, 0x81}, // K
    {0xFF, 0x01, 0x01, 0x01, 0x01}, // L
    {0xFF, 0x40, 0x30, 0x40, 0xFF}, // M
    {0xFF, 0x40, 0x30, 0x08, 0xFF}, // N
    {0x7E, 0x81, 0x81, 0x81, 0x7E}, // O

    {0xFF, 0x88, 0x88, 0x88, 0x70}, // P (80)
    {0x7E, 0x81, 0x85, 0x82, 0x7D}, // Q
    {0xFF, 0x88, 0x8C, 0x8A, 0x71}, // R
    {0x61, 0x91, 0x91, 0x91, 0x8E}, // S
    {0x80, 0x80, 0xFF, 0x80, 0x80}, // T
    {0xFE, 0x01, 0x01, 0x01, 0xFE}, // U
    {0xF0, 0x0C, 0x03, 0x0C, 0xF0}, // V
    {0xFF, 0x02, 0x0C, 0x02, 0xFF}, // W
    {0xC3, 0x24, 0x18, 0x24, 0xC3}, // X
    {0xE0, 0x10, 0x0F, 0x10, 0xE0}, // Y

    {0x83, 0x85, 0x99, 0xA1, 0xC1}, // Z (90)
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x06, 0x29, 0x29, 0x29, 0x1F}, // a
    {0xFF, 0x09, 0x11, 0x11, 0x0E}, // b
    {0x1E, 0x21, 0x21, 0x21, 0x12}, // c

    {0x0E, 0x11, 0x11, 0x09, 0xFF}, // d (100)
    {0x0E, 0x15, 0x15, 0x15, 0x0C}, // e
    {0x08, 0x7F, 0x88, 0x80, 0x40}, // f
    {0x30, 0x49, 0x49, 0x49, 0x7E}, // g
    {0xFF, 0x08, 0x10, 0x10, 0x0F}, // h
    {0x00, 0x00, 0x5F, 0x00, 0x00}, // i
    {0x02, 0x01, 0x21, 0xBE, 0x00}, // j
    {0xFF, 0x04, 0x0A, 0x11, 0x00}, // k
    {0x00, 0x81, 0xFF, 0x01, 0x00}, // l
    {0x3F, 0x20, 0x18, 0x20, 0x1F}, // m

    {0x3F, 0x10, 0x20, 0x20, 0x1F}, // n (110)
    {0x0E, 0x11, 0x11, 0x11, 0x0E}, // o
    {0x3F, 0x24, 0x24, 0x24, 0x18}, // p
    {0x10, 0x28, 0x28, 0x18, 0x3F}, // q
    {0x1F, 0x08, 0x10, 0x10, 0x08}, // r
    {0x09, 0x15, 0x15, 0x15, 0x02}, // s
    {0x20, 0xFE, 0x21, 0x01, 0x02}, // t
    {0x1E, 0x01, 0x01, 0x02, 0x1F}, // u
    {0x1C, 0x02, 0x01, 0x02, 0x1C}, // v
    {0x1E, 0x01, 0x0E, 0x01, 0x1E}, // w

    {0x11, 0x0A, 0x04, 0x0A, 0x11}, // x (120)
    {0x00, 0x39, 0x05, 0x05, 0x3E}, // y
    {0x11, 0x13, 0x15, 0x19, 0x11}, // z
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00}};
    
// GPIO Control Functions
void GPIO_Reset(GPIO_TypeDef *port, uint16_t pin)
{
    GPIO_ResetBits(port, pin);
}

void GPIO_Set(GPIO_TypeDef *port, uint16_t pin)
{
    GPIO_SetBits(port, pin);
}

// SPI and GPIO Initialization
void SPI1_Init(void)
{
    SPI_InitTypeDef SPI_InitStruct;
    GPIO_InitTypeDef GPIO_InitStruct;

    // Enable clocks for SPI1 and GPIOA
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 | RCC_APB2Periph_GPIOA, ENABLE);

    // Configure GPIO for SPI1
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7; // SCK, MOSI
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    // Configure GPIO for RES, DC, CS
    GPIO_InitStruct.GPIO_Pin = GC9106_RES_PIN | GC9106_DC_PIN | GC9106_CS_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GC9106_RES_PORT, &GPIO_InitStruct);

    // SPI1 configuration
    SPI_InitStruct.SPI_Direction = SPI_Direction_1Line_Tx;
    SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
    SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
    SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStruct.SPI_CRCPolynomial = 7;
    SPI_Init(SPI1, &SPI_InitStruct);

    // Enable SPI1
    SPI_Cmd(SPI1, ENABLE);
}

// SPI Write Functions
void Lcd_WriteCommand(uint8_t cmd)
{
    GPIO_Reset(GC9106_CS_PORT, GC9106_CS_PIN); // Select display
    GPIO_Reset(GC9106_DC_PORT, GC9106_DC_PIN); // Command mode
    SPI_I2S_SendData(SPI1, cmd);
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY))
        ;                                    // Wait for transfer complete
    GPIO_Set(GC9106_CS_PORT, GC9106_CS_PIN); // Deselect display
}

void Lcd_WriteData(uint8_t data)
{
    GPIO_Reset(GC9106_CS_PORT, GC9106_CS_PIN); // Select display
    GPIO_Set(GC9106_DC_PORT, GC9106_DC_PIN);   // Data mode
    SPI_I2S_SendData(SPI1, data);
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY))
        ;                                    // Wait for transfer complete
    GPIO_Set(GC9106_CS_PORT, GC9106_CS_PIN); // Deselect display
}

// GC9106 Initialization
void GC9106_Init(void)
{
    // Reset the display
    GPIO_Reset(GC9106_RES_PORT, GC9106_RES_PIN);
    Delay_Ms(100);
    GPIO_Set(GC9106_RES_PORT, GC9106_RES_PIN);
    Delay_Ms(100);

    // Initialization sequence
    Lcd_WriteCommand(0xFE);
    Lcd_WriteCommand(0xFE);
    Lcd_WriteCommand(0xFE);
    Lcd_WriteCommand(0xEF);

    Lcd_WriteCommand(0xb3);
    Lcd_WriteData(0x36);
    Lcd_WriteData(0xd8);

    // Lcd_WriteCommand(0x36); // Memory Data Access Control
    // Lcd_WriteData(ROTATION_0); // Default orientation (Portrait)

    Lcd_WriteCommand(0x3A); // Interface Pixel Format
    Lcd_WriteData(0x05);

    Lcd_WriteCommand(0x11); // Sleep Out
    Delay_Ms(120);

    Lcd_WriteCommand(0x29); // Display ON
    Lcd_WriteCommand(0x21); // Display ON
}

// Set Screen Rotation and Adjust Address Ranges
void GC9106_SetRotation(uint8_t rotation)
{
    uint8_t madctl = 0;

    switch (rotation)
    {
    case 0:            // Portrait (Default)
        madctl = 0x48; // Row/Column exchange, RGB mode
        break;
    case 1:            // Landscape (90°)
        madctl = 0x28; // Row/Column exchange, Y-mirror, RGB mode
        break;
    case 2:            // Portrait Inverted (180°)
        madctl = 0x88; // X-mirror, Y-mirror, RGB mode
        break;
    case 3:            // Landscape Inverted (270°)
        madctl = 0xE8; // X-mirror, Row/Column exchange, RGB mode
        break;
    default:
        madctl = 0x48; // Default to portrait
        break;
    }

    // Set Memory Data Access Control (Rotation)
    Lcd_WriteCommand(0x36);
    Lcd_WriteData(madctl);

    // Adjust column and row address ranges based on rotation
    if (rotation == 0 || rotation == 2)
    {
        // Portrait or Portrait Inverted
        Lcd_WriteCommand(0x2A); // Column address set
        Lcd_WriteData(0x00);    // Start column high byte
        Lcd_WriteData(0x18);    // Start column low byte
        Lcd_WriteData(0x00);    // End column high byte
        Lcd_WriteData(0x4F);    // End column low byte (79)

        Lcd_WriteCommand(0x2B); // Row address set
        Lcd_WriteData(0x00);    // Start row high byte
        Lcd_WriteData(0x00);    // Start row low byte
        Lcd_WriteData(0x00);    // End row high byte
        Lcd_WriteData(0x9F);    // End row low byte (159)
    }
    else
    {
        // Landscape or Landscape Inverted
        Lcd_WriteCommand(0x2A); // Column address set
        Lcd_WriteData(0x00);    // Start column high byte
        Lcd_WriteData(0x60);    // Start column low byte
        Lcd_WriteData(0x00);    // End column high byte
        Lcd_WriteData(0x67);    // End column low byte (159)

        Lcd_WriteCommand(0x2B); // Row address set
        Lcd_WriteData(0x00);    // Start row high byte
        Lcd_WriteData(0x00);    // Start row low byte
        Lcd_WriteData(0x00);    // End row high byte
        Lcd_WriteData(0x9f);    // End row low byte (79)
    }

    // Write Memory Start
    // Lcd_WriteCommand(0x2C);
}

// Fill Screen Function
void GC9106_FillScreen(uint16_t color)
{
    uint8_t high_byte = color >> 8;  // High byte of color
    uint8_t low_byte = color & 0xFF; // Low byte of color

    // Set column address
    Lcd_WriteCommand(0x2A);
    Lcd_WriteData(0x00);                   // Start column high byte
    Lcd_WriteData(xoffset);                // Start column low byte
    Lcd_WriteData(0x00);                   // End column high byte
    Lcd_WriteData(xoffset + GC9106_WIDTH); // End column low byte (79)

    // Set row address
    Lcd_WriteCommand(0x2B);
    Lcd_WriteData(0x00);                    // Start row high byte
    Lcd_WriteData(yoffset);                 // Start row low byte
    Lcd_WriteData(0x00);                    // End row high byte
    Lcd_WriteData(yoffset + GC9106_HEIGHT); // End row low byte (159)

    // Write memory
    Lcd_WriteCommand(0x2C);

    // Fill screen with color
    for (uint32_t i = 0; i < (GC9106_WIDTH * (GC9106_HEIGHT + 1)); i++)
    {
        Lcd_WriteData(high_byte);
        Lcd_WriteData(low_byte);
    }
}

void put_pixel(uint16_t x, uint16_t y, uint16_t color)
{
    if (x >= GC9106_WIDTH || y >= GC9106_HEIGHT)
        return; // Ensure pixel is within bounds

    // Set column and row address
    Lcd_WriteCommand(0x2A);                  // Column address set
    Lcd_WriteData(x >> 8);                   // High byte of x
    Lcd_WriteData((x + xoffset) & 0xFF);     // Low byte of x
    Lcd_WriteData((x + 1) >> 8);             // High byte of x + 1
    Lcd_WriteData((x + xoffset + 1) & 0xFF); // Low byte of x + 1

    Lcd_WriteCommand(0x2B);                  // Row address set
    Lcd_WriteData(y >> 8);                   // High byte of y
    Lcd_WriteData(yoffset + (y & 0xFF));     // Low byte of y
    Lcd_WriteData((y + 1) >> 8);             // High byte of y + 1
    Lcd_WriteData((yoffset + y + 1) & 0xFF); // Low byte of y + 1

    Lcd_WriteCommand(0x2C);      // Write to RAM
    Lcd_WriteData(color >> 8);   // High byte of color
    Lcd_WriteData(color & 0xFF); // Low byte of color
}

void put_line(int x1, int y1, int x2, int y2, uint16_t color)
{
    // Ensure the start and end points are within bounds
    if (x1 < 0 || x1 >= GC9106_WIDTH || y1 < 0 || y1 >= GC9106_HEIGHT ||
        x2 < 0 || x2 >= GC9106_WIDTH || y2 < 0 || y2 >= GC9106_HEIGHT)
    {
        return;
    }

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        // Plot the current pixel
        put_pixel(x1, y1, color);

        // If we've reached the end point, stop
        if (x1 == x2 && y1 == y2)
            break;

        int e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

// Function to render a single character
void draw_char(uint16_t x, uint16_t y, char c, uint16_t color)
{
    if (c < 32 || c > 127)
        return; // Skip unsupported characters

    uint8_t *char_bitmap = font5x8[c]; // Get character data

    for (uint8_t col = 0; col < 5; col++)
    { // Each column of the character
        uint8_t column_data = char_bitmap[col];

        for (uint8_t row = 0; row < 8; row++)
        { // Each bit of the column
            if (column_data & (1 << row))
            {                                       // Check if the pixel is on
                put_pixel(x + col, y + row, color); // Draw pixel
            }
            else
            {
                // put_pixel(x + col, y + row, color); // Draw pixel
            }
        }
    }
}

// Function to draw a string
void draw_string(uint16_t x, uint16_t y, const char *str, uint16_t color)
{
    uint16_t cursor_x = x;
    uint16_t cursor_y = y;

    while (*str)
    {
        if (*str == '\n')
        { // Handle newlines
            cursor_y += 8;
            cursor_x = x;
        }
        else
        {
            draw_char(cursor_x, cursor_y, *str, color);
            cursor_x += 6; // Move cursor to the right (5 pixels + 1 for spacing)
        }
        str++;
    }
}