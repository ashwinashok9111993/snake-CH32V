#ifndef SNAKE_H
#define SNAKE_H

#define GAME_AREA_X_MIN 1
#define GAME_AREA_X_MAX 120
#define GAME_AREA_Y_MIN 1
#define GAME_AREA_Y_MAX 78
#define GRID_SIZE 3

#define SCREEN_WIDTH 118
#define SCREEN_HEIGHT 76

#define MAX_SNAKE_LENGTH ((GAME_AREA_X_MAX / GRID_SIZE) * (GAME_AREA_Y_MAX / GRID_SIZE))

// Snake directions
typedef enum
{
    DIR_DOWN,
    DIR_UP,
    DIR_LEFT,
    DIR_RIGHT
} Direction;

// Snake segment structure
typedef struct
{
    int x;
    int y;
} Point;

extern Point snake[MAX_SNAKE_LENGTH]; // Snake body (array of points)
extern int snake_length;              // Initial length of the snake
extern Direction dir;                 // Initial direction
extern Point food;
extern bool game_over;

void screen_Init(void);
void kill_screen(void);
void init_game(void);
void game_loop(void);
void handle_input(void);

#endif
