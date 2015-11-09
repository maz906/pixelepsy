#ifndef SPRITE_H
#define SPRITE_H

#include "sprite/frame.h"

#include <vector>

class Sprite
{
    int width;
    int height;

    std::vector<Frame> frames;
public:
    Sprite() = delete;
    Sprite(int width, int height);
    Frame getFrame(int frame);
};

#endif // SPRITE_H
