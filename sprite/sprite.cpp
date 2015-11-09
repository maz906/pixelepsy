#include "sprite/sprite.h"

Sprite::Sprite(int width, int height)
{
    frames.push_back(Frame{width, height});
}

Frame Sprite::getFrame(int frame) {
    return this->frames.at(frame);
}
