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

void SpriteView::updateView() {
    scene.clear();
    Frame frame = buffer->current()->getFrame(frameIndex);
    for(auto layer = frame.getLayersBegin(); layer != frame.getLayersEnd(); layer++) {
        scene.addPixmap(QPixmap::fromImage(**layer))
            ->show();
    }
    this->scale(qreal(scala), qreal(scala));
}

void SpriteView::spriteModified() {
    updateView();
}

void SpriteView::closeEvent(QCloseEvent* event) {
    (void)event;
    if (!(this->buffer.use_count() - 1))
    {
        //save dialog
    }
}

 void SpriteView::mousePressEvent(QMouseEvent *) {};
 void SpriteView::mouseMoveEvent(QMouseEvent *) {};
 void SpriteView::mouseReleaseEvent(QMouseEvent *) {};
