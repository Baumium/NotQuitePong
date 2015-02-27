#include "ball.h"
#include "game.h"
#include "side.h"
#include <cstdio>

Ball::Ball(int speed) : Entity(Game::SCREEN_WIDTH / 2 - Game::SCREEN_WIDTH / 70, Game::SCREEN_HEIGHT/ 2, Game::SCREEN_WIDTH / 70, Game::SCREEN_WIDTH / 60), speedX(speed), speedY(speed) {

}

Side Ball::update(SDL_Rect &left, SDL_Rect &right, SDL_Rect &top, SDL_Rect &bottom) {
    //Left, Right, and Paddle collisions
    if(rect.x < 0) {
        return LEFT;
    } else if (rect.x + rect.w > Game::SCREEN_WIDTH) {
        return RIGHT;
    } else if (rect.y < 0) {
        return TOP;
    } else if (rect.y + rect.h > Game::SCREEN_HEIGHT) {
        return BOTTOM;
    }

    if((speedX < 0 && rect.x < left.x + left.w && rect.y + rect.h > left.y && rect.y < left.y + left.h)
            || (speedX > 0 && rect.x + rect.w > right.x && rect.y < right.y + right.h && rect.y + rect.h > right.y)) {
        speedX *= -1;
    }
    if((speedY < 0 && rect.x < top.x + top.w && rect.x + rect.w > top.x && rect.y < top.y + top.h)
            || (speedY > 0 && rect.x < bottom.x + bottom.w && rect.x + rect.w > bottom.x && rect.y + rect.h > bottom.y)) {
        speedY *= -1;
    }

    //If the ball has not gone off the screen, proceed to move the ball
    rect.x += speedX;
    rect.y += speedY;
    return NONE;
}

void Ball::reset() {
    rect.x = Game::SCREEN_WIDTH / 2;
    rect.y = Game::SCREEN_HEIGHT / 2;
    speedX *= -1;
    speedY *= -1;
}
