#ifndef SPRITE_H
#define SPRITE_H

#include "frame.h"

#include <vector>

class Sprite
{
    int width;
    int height;

    std::vector<Frame> frames;
public:
    Sprite() = delete;

    Sprite(int width, int height);
};

#endif // SPRITE_H
