#ifndef SPRITEVIEW_H
#define SPRITEVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>

class SpriteView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SpriteView(QWidget* parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseMoveEvent(QGraphicsSceneMouseEvent*);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
    QPoint pixelLocation(QMouseEvent*);
};

#endif // SPRITEVIEW_H
