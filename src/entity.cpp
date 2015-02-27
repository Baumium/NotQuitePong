#include <SDL2/SDL.h>
#include "entity.h"

Entity::Entity(int x, int y, int width, int height) : rect({x, y, width, height}) {

}

void Entity::render(SDL_Renderer *renderer) {
    SDL_RenderFillRect(renderer, &rect);
}

void Entity::update() {
    //Should be overrided
}

int Entity::getY() const {
    return rect.y;
}

int Entity::getCenter() const {
    return rect.y + rect.h / 2;
}

SDL_Rect Entity::getRect() const {
    return rect;
}
