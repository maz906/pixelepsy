#include "sprite/frame.h"
#include <QImage>
#include <memory>

Frame::Frame(int width, int height)
    : width(width)
    , height(height)
{
    layers.push_back(std::make_shared<QImage>(width, height, QImage::Format_ARGB32));
}

std::shared_ptr<QImage> Frame::getLayer(int layer) {
    return this->layers.at(layer);
}
