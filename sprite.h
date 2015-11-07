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

    // XXX Test don't use
    QImage getFirst() {
        return *frames.at(0).getFirst();
    }
};

#endif // SPRITE_H
