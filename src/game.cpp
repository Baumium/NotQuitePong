#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <cstdio>
#include "game.h"
#include "ball.h"
#include "side.h"

//Screen resolution
const int Game::SCREEN_WIDTH =640;
const int Game::SCREEN_HEIGHT = 480;

Game::Game() {
    //Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //Init font

    //Create window and renderer
    window = SDL_CreateWindow("Not Quite Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    keystates = SDL_GetKeyboardState(NULL);

    isExit = false;

    //Instantiate game objects
    leftPaddle = new Paddle(6, LEFT, false);
    rightPaddle = new Paddle(6, RIGHT, true);
    ball = new Ball(6);

    isPlaying = false;
}

void Game::input() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                isExit = true;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        isExit = true;
                        break;
                    case SDLK_SPACE: //If space is pressed, start the game
                        isPlaying = true;
                        ball->reset();
                        break;
                }
                break;
        }
    }

    if(keystates[SDL_SCANCODE_W]) {
        leftPaddle->moveUp();
    }
    if(keystates[SDL_SCANCODE_S]) {
        leftPaddle->moveDown();
    }
    if(keystates[SDL_SCANCODE_UP]) {
        rightPaddle->moveUp();
    }
    if(keystates[SDL_SCANCODE_DOWN]) {
        rightPaddle->moveDown();
    }
}

void Game::update() {
    leftPaddle->update(ball->getY());
    rightPaddle->update(ball->getY());
    if(isPlaying) {
        ball->update(leftPaddle->getRect(), rightPaddle->getRect());
    }
}

void Game::render() {
    //Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect centerLine = {SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 60, SCREEN_HEIGHT};
    SDL_RenderFillRect(renderer, &centerLine);

    //Render game objects
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    leftPaddle->render(renderer);
    rightPaddle->render(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    ball->render(renderer);

    SDL_RenderPresent(renderer);
}


void Game::cleanUp() {
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_Quit();
}

void Game::execute() {
    while(!isExit) {
        input();
        update();
        render();
    }

    cleanUp();
}
