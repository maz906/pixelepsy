#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QMouseEvent>

#include <memory>

#include "gui/spriteview.h"

SpriteView::SpriteView(std::shared_ptr<Buffer> buffer, QWidget* parent)
    : QGraphicsView(parent)
    , frameIndex(0)
    , layerIndex(0)
    , scala(20)
    , buffer(buffer)
    , scene(new QGraphicsScene)
{
    this->setLayout(&layout);
    this->setContentsMargins(0, 0, 0, 0);
    this->setScene(&scene);
    updateView();
    this->show();
}

void SpriteView::mouseMoveEvent(QMouseEvent* event)
{
    QPoint point = this->pixelLocation(event);
    if (checkPoint(point))
        this->points.push_back(point);
}

void SpriteView::mousePressEvent(QMouseEvent* event) {
    this->points.clear();
}

void SpriteView::mouseReleaseEvent(QMouseEvent* event) {
}

QPoint SpriteView::pixelLocation(QMouseEvent* event) {
    return (this->mapToScene(event->pos())).toPoint();
}

bool SpriteView::checkPoint(QPoint point) {
    int x = point.x();
    int y = point.y();
    int width = this->buffer.get()->current().get()->getWidth();
    int height = this->buffer.get()->current().get()->getHeight();
    return ((x >= 0) && (y >= 0)) && ((x < width) && (y < height));
}

void SpriteView::selectFrame(int frame) {

}

void SpriteView::selectLayer(int layer) {

}

void SpriteView::updateView() {
    scene.clear();
    Frame frame = buffer->current()->getFrame(frameIndex);
    for(auto layer = frame.getLayersBegin(); layer != frame.getLayersEnd(); layer++) {
        scene.addPixmap(QPixmap::fromImage(**layer))
            ->show();
    }
    this->scale(qreal(scala), qreal(scala));
}
