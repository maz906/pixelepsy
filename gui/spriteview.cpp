#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

#include "gui/spriteview.h"

SpriteView::SpriteView(QWidget* parent)
    : QGraphicsView(parent)
{
}

SpriteView::SpriteView(QGraphicsScene *scene, QWidget *parent)
    : QGraphicsView(scene, parent)
{

}

void SpriteView::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    points.push_back(this->pixelLocation(event));
}

void SpriteView::mousePressEvent(QGraphicsSceneMouseEvent * event) {
    this->setMouseTracking(true);
    points.clear();
}

void SpriteView::mouseReleaseEvent(QGraphicsSceneMouseEvent * event) {
    this->setMouseTracking(false);
}

QPoint SpriteView::pixelLocation(QGraphicsSceneMouseEvent * event) {
    QGraphicsItem* item = this->scene()->items().at(0);
    QPointF scenePt = item->boundingRect().topLeft();
    QPoint viewPt = this->mapTo(this, scenePt.toPoint());
    return event->pos().toPoint() - viewPt;
}
