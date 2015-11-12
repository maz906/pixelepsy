#ifndef SPRITEVIEW_H
#define SPRITEVIEW_H

#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>

#include <vector>

class SpriteView : public QGraphicsView
{
    Q_OBJECT
public:
    SpriteView(QWidget* parent = 0);
    SpriteView(QGraphicsScene* scene,  QWidget* parent = 0);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    QPoint pixelLocation(QMouseEvent*);

private:
    std::vector<QPoint> points;
};

#endif // SPRITEVIEW_H
