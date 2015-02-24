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
