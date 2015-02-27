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
    speed(speed), isAI(isAI) {
}

void Paddle::update(int ballY) {
    if(isAI) {
        rect.y = ballY - rect.h / 2;
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

