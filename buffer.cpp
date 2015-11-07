#include "buffer.h"

#include <memory>

Buffer::Buffer(int width, int height)
{
    history.push_back(std::make_shared<Sprite>(width, height));
}

std::shared_ptr<Sprite> Buffer::current() {
    return history.back();
}
