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
    TTF_Init();
    font = TTF_OpenFont("assets/font.ttf", 20);

    //Create window and renderer
    window = SDL_CreateWindow("Not Quite Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    keystates = SDL_GetKeyboardState(NULL);

    isExit = false;

    //Instantiate game objects
    leftPaddle = new Paddle(7, LEFT, true);
    rightPaddle = new Paddle(7, RIGHT, true);
    bottomPaddle = new Paddle(7, BOTTOM, true);
    topPaddle = new Paddle(7, TOP, true);
    ball = new Ball(10);

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
                    case SDLK_ESCAPE: //Escape = mark program for closure
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
    } else if(keystates[SDL_SCANCODE_S]) {
        leftPaddle->moveDown();
    }
    if(keystates[SDL_SCANCODE_UP]) {
        rightPaddle->moveUp();
    } else if(keystates[SDL_SCANCODE_DOWN]) {
        rightPaddle->moveDown();
    }
    if(keystates[SDL_SCANCODE_Z]) {
        topPaddle->moveLeft();
    } else if(keystates[SDL_SCANCODE_X]) {
        topPaddle->moveRight();
    }
    if(keystates[SDL_SCANCODE_RIGHTBRACKET]) {
        bottomPaddle->moveRight();
    } else if(keystates[SDL_SCANCODE_LEFTBRACKET]) {
        bottomPaddle->moveLeft();
    }
}

void Game::update() {
    leftPaddle->update(ball->getRect());
    rightPaddle->update(ball->getRect());
    bottomPaddle->update(ball->getRect());
    topPaddle->update(ball->getRect());
    if(isPlaying) {
        ball->update(leftPaddle->getRect(), rightPaddle->getRect(), topPaddle->getRect(), bottomPaddle->getRect());
    }
}

void Game::render() {
    //Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    //std::string message = "food";
    //SDL_RenderCopy(renderer, renderText(&message), nullptr, new (SDL_Rect){50, 50, 100, 100});

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    //Render game objects
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    leftPaddle->render(renderer);
    rightPaddle->render(renderer);
    bottomPaddle->render(renderer);
    topPaddle->render(renderer);
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
    TTF_CloseFont(font);
    TTF_Quit();
}

void Game::execute() {
    while(!isExit) {
        input();
        update();
        render();
    }

    cleanUp();
}

SDL_Texture* Game::renderText(std::string *text) {
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text->c_str(), (SDL_Color){255, 255, 255});
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    return message;
}
