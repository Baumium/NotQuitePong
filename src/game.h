#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "paddle.h"
#include "ball.h"

class Game {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        const Uint8 *keystates;

        bool isExit;

        Paddle *leftPaddle;
        Paddle *rightPaddle;
        Ball *ball;

        bool isPlaying;
    public:
        static const int SCREEN_WIDTH;
        static const int SCREEN_HEIGHT;


        Game();
        void input();
        void update();
        void render();
        void execute();
        void cleanUp();
};

#endif