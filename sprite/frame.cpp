#include "sprite/frame.h"

#include <memory>

#include <QImage>

Frame::Frame(int width, int height)
    : width(width)
    , height(height)
{
    layers.push_back(std::make_shared<QImage>(width, height, QImage::Format_ARGB32));
    layers.back()->fill(Qt::cyan);
}

std::shared_ptr<QImage> Frame::getLayer(int layer) {
    return this->layers.at(layer);
}

std::vector<std::shared_ptr<QImage>>::const_iterator Frame::getLayersBegin() {
    return this->layers.cbegin();
}

std::vector<std::shared_ptr<QImage>>::const_iterator  Frame::getLayersEnd() {
    return this->layers.cend();
}
