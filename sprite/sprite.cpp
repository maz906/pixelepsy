#include "sprite/sprite.h"

#include <QImage>

Sprite::Sprite(int width, int height)
{
    frames.push_back(Frame{width, height});
}

int Sprite::getWidth() {
    return this->width;
}

int Sprite::getHeight() {
    return this->height;
}

Frame Sprite::getFrame(int frame) {
    return this->frames.at(frame);
}

QImage Sprite::getImage(int frame, int layer) {
    return *(this->getFrame(frame).getLayer(layer).get());
}

void Sprite::addFrame() {
    frames.push_back(frames.back().clone());
}
