#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <memory>
#include <vector>

#include "sprite/sprite.h"
#include "sprite/buffer.h"

class Canvas : public QGraphicsView
{
    Q_OBJECT
private:
    std::shared_ptr<Buffer> buffer;
    std::vector<QPoint> points;
    QVBoxLayout layout;
    QGraphicsScene scene;
    int frameIndex;
    int layerIndex;
    double scala;
public:
    explicit Canvas(std::shared_ptr<Buffer> buffer, QWidget *parent = 0);
    void selectFrame(int frame);
    void selectLayer(int layer);
    void updateView();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint pixelLocation(QMouseEvent* event);
    bool checkPoint(QPoint);
signals:
    void onClicked(std::vector<QPoint> points);
    void onPressed(std::vector<QPoint> points);
public slots:
    //void spriteUpdated(Sprite sprite);
};

#endif // CANVAS_H
