#include "gui/viewer.h"
#include "sprite/sprite.h"
#include "sprite/buffer.h"

#include <memory>


Viewer::Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent)
    : SpriteView(buffer, parent)
{
}

