#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "paddle.h"
#include "ball.h"
#include <string>

class Game {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        const Uint8 *keystates;

        bool isExit;

        SDL_Rect *centerLine;
        Paddle *leftPaddle;
        Paddle *rightPaddle;
        Paddle *bottomPaddle;
        Paddle *topPaddle;
        Ball *ball;
        TTF_Font *font;

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
        SDL_Texture* renderText(std::string *text);
};

#endif
