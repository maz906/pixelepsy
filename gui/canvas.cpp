#include "gui/canvas.h"
#include "sprite/buffer.h"
#include "sprite/sprite.h"

#include <memory>

Canvas::Canvas(std::shared_ptr<Buffer> buffer, QWidget *parent)
    : SpriteView(buffer, parent)
{
}

