#include "sprite/buffer.h"

#include <memory>

#include <QImage>
#include <QPoint>

Buffer::Buffer(int width, int height)
{
    history.push_back(std::make_shared<Sprite>(width, height));
}

QImage Buffer::get(int frame, int layer) {
    return *(this->current().get())->getFrame(frame).getLayer(layer);
}

std::shared_ptr<Sprite> Buffer::current() {
    return history.back();
}

void Buffer::applyOperation(std::vector<QPoint> &points) {
    history.push_back(operation(*(history.back().get()), points));
}
