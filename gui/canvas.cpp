#include "gui/canvas.h"
#include "sprite/buffer.h"
#include "sprite/sprite.h"
#include "sprite/frame.h"

#include <vector>
#include <memory>

#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>


Canvas::Canvas(std::shared_ptr<Buffer> buffer, QWidget *parent)
    : SpriteView(buffer, parent)
{
}
