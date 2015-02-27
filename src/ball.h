#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include "entity.h"
#include "side.h"

class Ball : public Entity {
    private:
        int speedX;
        int speedY;

    public:
        Ball(int speed);
        Side update(SDL_Rect &left, SDL_Rect &right, SDL_Rect &top, SDL_Rect &bottom);
        void reset();
};

#endif
