#include "sprite/sprite.h"

#include <QImage>

Sprite::Sprite(int width, int height)
{
    frames.push_back(Frame{width, height});
}

Frame Sprite::getFrame(int frame) {
    return this->frames.at(frame);
}

QImage Sprite::getImage(int frame, int layer) {
    return *(this->getFrame(frame).getLayer(layer).get());
}
std::vector<Frame> Sprite::getFrames() {
    return frames;
}
