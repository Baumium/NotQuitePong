#ifndef SCORE_H
#define SCORE_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Score {
    private:
        TTF_Font *font;
        SDL_Texture *leftScore;
        SDL_Texture *rightScore;

    public:
        Score(std::string *path, int size);
        void update();
        void render();
};

#endif
