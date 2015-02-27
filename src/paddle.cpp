#include "game.h"
#include "paddle.h"
#include <cstdio>
#include "side.h"

//Assign paddle size based on screen size
Paddle::Paddle(int speed, Side side, bool isAI) :
    Entity(side == LEFT ? 0 : side == RIGHT ? Game::SCREEN_WIDTH - Game::SCREEN_WIDTH / 50 : Game::SCREEN_HEIGHT / 2 + Game::SCREEN_WIDTH / 50,
            side == LEFT || side == RIGHT ? Game::SCREEN_HEIGHT / 2 - (Game::SCREEN_HEIGHT / 4) / 2 : side == TOP ? 0 : Game::SCREEN_HEIGHT - Game::SCREEN_WIDTH / 50,
            side == LEFT || side == RIGHT ? Game::SCREEN_WIDTH / 50 : Game::SCREEN_HEIGHT / 4,
            side == LEFT || side == RIGHT ? Game::SCREEN_HEIGHT / 4 : Game::SCREEN_WIDTH / 50),
    speed(speed), isAI(isAI), side(side) {
}

void Paddle::update(SDL_Rect ball) {
    if(isAI) {
        if(side == LEFT || side == RIGHT) {
            double movement = (rect.y + rect.h / 2.0 - ball.y + ball.h / 2.0) / speed;
            if((movement > 0 && rect.y > 0)
                    || (movement < 0 && rect.y + rect.h < Game::SCREEN_HEIGHT)) {
                rect.y -= movement;
            }
        } else if(side == TOP || side == BOTTOM) {
            double movement = (rect.x + rect.w / 2.0 - ball.x + ball.w / 2.0 / speed);
            if((movement > 0 && rect.x > 0)
                    || (movement < 0 && rect.x + rect.w < Game::SCREEN_WIDTH)) {
                rect.x -= movement;
            }
        }
    }
}

void Paddle::setSpeed(int speed) {
    this->speed = speed;
}

void Paddle::moveUp() {
    //If we are not touching the top of the screen
    if(rect.y > 0) {
        rect.y -= speed;
    }
}

void Paddle::moveDown() {
    if(rect.y + rect.h < Game::SCREEN_HEIGHT) {
        rect.y += speed;
    }
}

void Paddle::moveLeft() {
    if(rect.x > 0) {
        rect.x -= speed;
    }
}
void Paddle::moveRight() {
    if(rect.x + rect.w < Game::SCREEN_WIDTH) {
        rect.x += speed;
    }
}

SDL_Rect& Paddle::getRect() {
    return this->rect;
}

