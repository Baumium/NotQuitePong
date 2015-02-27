#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>

//Base class for most visible objects
class Entity {
    protected:
        SDL_Rect rect;

    public:
        Entity(int x, int y, int width, int height);

        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        int getCenter() const;
        SDL_Rect getRect() const;

        void setX(int x);
        void setY(int y);

        virtual void update();
        void render(SDL_Renderer *renderer);
};

#endif
