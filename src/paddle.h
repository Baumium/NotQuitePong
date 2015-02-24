#ifndef PADDLE_H
#define PADDLE_H

#include <SDL2/SDL.h>
#include "entity.h"
#include "side.h"

class Paddle : public Entity {
    private:
        int speed;
        bool isAI;

    public:
        Paddle(int speed, Side side, bool isAI);
        void update(int ballX);
        void setSpeed(int speed);
        void moveDown();
        void moveUp();
        SDL_Rect& getRect();
};

#endif
