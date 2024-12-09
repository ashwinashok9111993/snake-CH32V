#include "main.h"
#include "gc9106.h"
#include "snake.h"
#include "stdlib.h"

// Game state
Point snake[MAX_SNAKE_LENGTH]; // Snake body (array of points)
int snake_length = 3;          // Initial length of the snake
Direction dir = DIR_RIGHT;     // Initial direction
Point food;                    // Food position
bool game_over = false;

// Apple bitmap (4x4 pixels)
uint16_t apple_bitmap[4][4] = {
    {COLOR_GREEN, 0x07E0, COLOR_GREEN, COLOR_GREEN}, // Row 1: Leaf on top
    {COLOR_GREEN, 0xF800, 0xF800, COLOR_GREEN},      // Row 2: Apple body (top part)
    {0xF800, 0xF800, 0xF800, 0xF800},                // Row 3: Apple body (bottom part)
    {COLOR_GREEN, 0xF800, 0xF800, COLOR_GREEN}       // Row 4: Background
};

// Function to draw the 4x4 apple bitmap at a given position
void draw_apple(int x, int y)
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            put_pixel(x + col, y + row, apple_bitmap[row][col]);
        }
    }
}
void draw_snake_segment(uint16_t x, uint16_t y, uint16_t color)
{
    uint8_t high_byte = color >> 8;  // High byte of color
    uint8_t low_byte = color & 0xFF; // Low byte of color

    // Set column address
    Lcd_WriteCommand(0x2A);
    Lcd_WriteData(0x00);            // Start column high byte
    Lcd_WriteData(xoffset + x);     // Start column low byte
    Lcd_WriteData(0x00);            // End column high byte
    Lcd_WriteData(xoffset + x + 4); // End column low byte (79)

    // Set row address
    Lcd_WriteCommand(0x2B);
    Lcd_WriteData(0x00);            // Start row high byte
    Lcd_WriteData(yoffset + y);     // Start row low byte
    Lcd_WriteData(0x00);            // End row high byte
    Lcd_WriteData(yoffset + y + 4); // End row low byte (159)

    // Write memory
    Lcd_WriteCommand(0x2C);

    // Fill screen with color
    for (uint32_t i = 0; i <= 2 * 4 * 4; i++)
    {
        Lcd_WriteData(high_byte);
        Lcd_WriteData(low_byte);
    }
}

void draw_game_area(void)
{
    put_line(1, 1, 1, 79 - 1, COLOR_BLACK);
    put_line(1, 79 - 1, 120 - 1, 79 - 1, COLOR_BLACK);
    put_line(120 - 1, 1, 120 - 1, 79 - 1, COLOR_BLACK);
    put_line(1, 1, 120 - 1, 1, COLOR_BLACK);
}

void screen_Init(void)
{
    put_pixel(0, 0, 0xF800);
    // put_line(0,0,160-1,36-1,0xFFFF);
    GC9106_FillScreen(COLOR_LIME); // Red color in RGB565

    draw_game_area();

    char title_text[] = "SNAKE";
    draw_string(121, 70, title_text, COLOR_BLACK);
    char score_text[] = "SCORE:";
    draw_string(121, 55, score_text, COLOR_BLACK);
    
}

// Draw a rectangle to represent a grid cell
void draw_cell(int x, int y, uint16_t color)
{
    for (int dx = 0; dx < GRID_SIZE; dx++)
    {
        for (int dy = 0; dy < GRID_SIZE; dy++)
        {
            put_pixel(x + dx, y + dy, color);
        }
    }
}

// Spawn food at a random position
void spawn_food(void)
{
    //rand() non zero work-around
    food.x = (rand() % (SCREEN_WIDTH / GRID_SIZE)) * GRID_SIZE ;
    while(food.x == 0)
    {
        food.x = (rand() % (SCREEN_WIDTH / GRID_SIZE)) * GRID_SIZE;
    }
    food.y = (rand() % (SCREEN_HEIGHT / GRID_SIZE)) * GRID_SIZE;
   
}

// Initialize the game
void init_game(void)
{
    // Initialize snake at the center of the screen
    snake[0].x = SCREEN_WIDTH / 2;
    snake[0].y = SCREEN_HEIGHT / 2;
    snake[1].x = snake[0].x - GRID_SIZE;
    snake[1].y = snake[0].y;
    snake[2].x = snake[1].x - GRID_SIZE;
    snake[2].y = snake[1].y;

    // Spawn the first food
    spawn_food();
}

// Update the snake's position
void update_snake()
{
    // Move the body
    for (int i = snake_length - 1; i > 0; i--)
    {
        snake[i] = snake[i - 1];
    }

    // Move the head
    switch (dir)
    {
    case DIR_UP:
        snake[0].y -= GRID_SIZE;
        break;
    case DIR_DOWN:
        snake[0].y += GRID_SIZE;
        break;
    case DIR_LEFT:
        snake[0].x -= GRID_SIZE;
        break;
    case DIR_RIGHT:
        snake[0].x += GRID_SIZE;
        break;
    }

     //printf("food_x: %d food_y: %d \n", food.x, food.y);
     //printf("snake_x: %d snake_y: %d \n", snake[0].x, snake[0].y);

    // Check for collisions with the walls
    if (snake[0].x < 0 || snake[0].x >= SCREEN_WIDTH ||
        snake[0].y < 0 || snake[0].y >= SCREEN_HEIGHT)
    {
        game_over = true;
    }

    // Check for collisions with itself
    for (int i = 1; i < snake_length; i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            game_over = true;
        }
    }

    // Check if the snake eats the food
    if (abs(snake[0].x - food.x) <= 2 && abs(snake[0].y - food.y) <= 2)
    {
        snake_length++;
        if (snake_length > MAX_SNAKE_LENGTH)
        {
            snake_length = MAX_SNAKE_LENGTH;
        }
        spawn_food();

        char score_text[5] = "00000";
        //Erase previous score
        int prev = snake_length - 1;
        itoa(prev,score_text,10);
        draw_string(121, 45, score_text, COLOR_GREEN);

        itoa(snake_length,score_text,10);
        draw_string(121, 45, score_text, COLOR_BLACK);
    }
}

// Render the game
void render_game()
{
    // Clear the screen (black background)
    for (int x = 2; x <= SCREEN_WIDTH; x++)
    {
        for (int y = 2; y <= SCREEN_HEIGHT; y++)
        {
            put_pixel(x, y, 0x0000); // Black color
        }
    }

    // Draw the snake
    for (int i = 0; i < snake_length; i++)
    {
        draw_cell(snake[i].x, snake[i].y, 0x07E0); // Green color
    }

    // Draw the food
    draw_cell(food.x, food.y, 0xF800); // Red color
}

// Game loop
void game_loop()
{
    while (!game_over)
    {

        JoystickData.x = DMA_Buffer[0];
        JoystickData.y = DMA_Buffer[1];
        handle_input(); // Simulate a key press ('d' for moving right)
        // printf("DIR %d \n", dir);

        update_snake(); // Update the game state
        render_game();  // Render the game
        Delay_Ms(100);  // Control game speed
    }

    // Game over screen
    render_game();
    kill_screen();
}

void kill_screen(void)
{
    for (int x = 2; x <= SCREEN_WIDTH; x++)
    {
        for (int y = 2; y <= SCREEN_HEIGHT; y++)
        {
            put_pixel(x, y, 0xF800); // Fill screen with red
        }
    }
}

// Control input (stub for handling user input)
void handle_input(void)
{

    if (JoystickData.y > 4000 && JoystickData.x < 3000)
    {
        dir = DIR_DOWN;
    }
    if (JoystickData.y < 1000 && JoystickData.x < 3000)
    {
        dir = DIR_UP;
    }
    if (JoystickData.x < 1000 && JoystickData.y < 3000)
    {
        dir = DIR_LEFT;
    }
    if (JoystickData.x > 4000 && JoystickData.y < 3000)
    {
        dir = DIR_RIGHT;
    }

    //JoystickData.x = DMA_Buffer[0];
    //JoystickData.y = DMA_Buffer[1];
    //printf("ADC_x: %d ADC_y: %d %d\n", JoystickData.x, JoystickData.y, dir);
}
