#include "ball.h"
#include "game.h"
#include "side.h"
#include <cstdio>

Ball::Ball(int speed) : Entity(Game::SCREEN_WIDTH / 2 - Game::SCREEN_WIDTH / 70, Game::SCREEN_HEIGHT/ 2, Game::SCREEN_WIDTH / 70, Game::SCREEN_WIDTH / 60), SPEED(speed), speedX(speed), speedY(speed) {
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

    if(speedX < 0 && rect.x < left.x + left.w && rect.y + rect.h > left.y && rect.y < left.y + left.h) {
        //Intersections with left
        double angle = (((left.y + left.h / 2) - (rect.y + rect.h / 2)) / left.h / 2) * 75;
        speedX = SPEED * cos(angle);
        speedY = SPEED * sin(angle);
    } else if (speedX > 0 && rect.x + rect.w > right.x && rect.y < right.y + right.h && rect.y + rect.h > right.y) {
        //Intersections with right
        double angle = (((right.y + right.h / 2) - (rect.y + rect.h / 2)) / right.h / 2) * 75;
        speedX = SPEED * cos(angle);
        speedY = SPEED * sin(angle);
    } else if(speedY < 0 && rect.x < top.x + top.w && rect.x + rect.w > top.x && rect.y < top.y + top.h) {
        //Intersections with top
        double angle = (((top.x + top.w / 2) - (rect.x + rect.w / 2)) / top.w / 2) * 75;
        speedX = SPEED * sin(angle);
        speedY = SPEED * cos(angle);
    } else if (speedY > 0 && rect.x < bottom.x + bottom.w && rect.x + rect.w > bottom.x && rect.y + rect.h > bottom.y) {
        //Interesections with bottom
        double angle = (((bottom.x + bottom.w / 2) - (rect.x + rect.w / 2)) / bottom.w / 2) * 75;
        speedX = SPEED * sin(angle);
        speedY = SPEED * cos(angle);
    }

    //If the ball has not gone off the screen, proceed to move the ball
    rect.x += ceil(speedX);
    rect.y += ceil(speedY);
    printf("%f\n", speedY);
    return NONE;
}

void Ball::reset() {
    rect.x = Game::SCREEN_WIDTH / 2;
    rect.y = Game::SCREEN_HEIGHT / 2;
    speedX = SPEED;
    speedY = SPEED;
}
