#define SDL_MAIN_HANDLED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define SNAKE_SIZE 20

typedef struct {
    int x;
    int y;
} Point;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct {
    Point pos;
    SDL_Color color;
} Segment;

typedef struct {
    Segment segments[100];
    int length;
    bool alive;
} Snake;

TTF_Font* font = NULL;

void init_snake(Snake* snake, int x, int y) {
    // Initialize the first segment of the snake's body
    snake->segments[0].pos = (Point){x, y};
    snake->segments[0].color = (SDL_Color){255, 255, 255, 255};

    // Initialize the rest of the snake's body segments
    for (int i = 1; i < snake->length; i++) {
        snake->segments[i].pos = (Point){x, y + (SNAKE_SIZE * i)};
        snake->segments[i].color = (SDL_Color){0, 255, 0, 255};
    }

    snake->alive = true;
}

void update_snake(Snake* snake, Direction direction) {
    Point new_head = {snake->segments[0].pos.x, snake->segments[0].pos.y};

    switch (direction) {
        case UP:
            new_head.y -= SNAKE_SIZE;
            break;
        case DOWN:
            new_head.y += SNAKE_SIZE;
            break;
        case LEFT:
            new_head.x -= SNAKE_SIZE;
            break;
        case RIGHT:
            new_head.x += SNAKE_SIZE;
            break;
    }

    // Update the position of the snake's head
    snake->segments[0].pos = new_head;

    // Update the positions of the rest of the snake's body segments
    for (int i = 1; i < snake->length; i++) {
        Point temp = snake->segments[i].pos;
        snake->segments[i].pos = snake->segments[i - 1].pos;
        snake->segments[i - 1].pos = temp;
    }

    // Check if the snake's head collides with its body
    for (int i = 1; i < snake->length; i++) {
        if (snake->segments[0].pos.x == snake->segments[i].pos.x &&
            snake->segments[0].pos.y == snake->segments[i].pos.y) {
            snake->alive = false;
            return;
        }
    }
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Snake",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH,
                                          WINDOW_HEIGHT,
                                          0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Snake snake = {
        .length = 5
    };

    init_snake(&snake, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    bool quit = false;

    Direction direction = RIGHT;

    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        if (direction != DOWN) {
                            direction = UP;
                        }
                        break;
                    case SDLK_DOWN:
                        if (direction != UP &&
                            direction != DOWN) {
                            direction = DOWN;
                        }
                        break;
                    case SDLK_LEFT:
                        if (direction != RIGHT &&
                            direction != LEFT) {
                            direction = LEFT;
                        }
                        break;
                    case SDLK_RIGHT:
                        if (direction != LEFT &&
                            direction != RIGHT) {
                            direction = RIGHT;
                        }
                        break;
                    default:
                        break;
                }
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Update the snake's position
        update_snake(&snake, direction);

        // Draw the snake
        for (int i = 0; i < snake.length; i++) {
            SDL_Rect rect = {
                .x = snake.segments[i].pos.x,
                .y = snake.segments[i].pos.y,
                .w = SNAKE_SIZE,
                .h = SNAKE_SIZE
            };

            SDL_SetRenderDrawColor(renderer,
                                   snake.segments[i].color.r,
                                   snake.segments[i].color.g,
                                   snake.segments[i].color.b,
                                   snake.segments[i].color.a);
            SDL_RenderFillRect(renderer, &rect);
        }

        // Show the score
        char score_text[50];
        sprintf(score_text, "Score: %d", snake.length - 5);
        font = TTF_OpenFont("assets/font.ttf", 28);
        SDL_Surface* score_surface = TTF_RenderText_Solid(font, score_text, (SDL_Color){255, 255, 255, 255});
        SDL_Texture* score_texture = SDL_CreateTextureFromSurface(renderer, score_surface);

        SDL_Rect score_rect = {
            .x = 10,
            .y = 10,
            .w = score_surface->w,
            .h = score_surface->h
        };

        SDL_RenderCopy(renderer, score_texture, NULL, &score_rect);

        SDL_FreeSurface(score_surface);
        SDL_DestroyTexture(score_texture);

        // Update the screen
        SDL_RenderPresent(renderer);

        // Wait for a short amount of time before continuing
        SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

