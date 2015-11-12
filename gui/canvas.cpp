#include "gui/canvas.h"
#include "sprite/buffer.h"
#include "sprite/sprite.h"

#include <memory>

Canvas::Canvas(std::shared_ptr<Buffer> buffer, QWidget *parent)
    : SpriteView(buffer, parent)
{
}


void Canvas::mouseMoveEvent(QMouseEvent* event)
{
    QPoint point = this->pixelLocation(event);
    if (checkPoint(point))
        this->points.push_back(point);
    //emit the single point (or the list so far) for previewer
}

void Canvas::mousePressEvent(QMouseEvent* event) {
    this->points.clear();
}

void Canvas::mouseReleaseEvent(QMouseEvent* event) {
    //emit a commit signal
}
