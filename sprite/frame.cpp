#include "sprite/frame.h"

Frame::Frame(int width, int height)
    : width(width)
    , height(height)
{
    layers.push_back(std::make_shared<QImage>(width, height, QImage::Format_ARGB32));
}

