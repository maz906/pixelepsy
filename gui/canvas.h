#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <memory>
#include <vector>

#include "sprite/sprite.h";
#include "sprite/buffer.h";

class Canvas : public QWidget
{
    Q_OBJECT
private:
    std::shared_ptr<Buffer> buffer;
    QGraphicsView view;
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    QScrollArea scroller;
    int frame;
    int layer;
public:
    explicit Canvas(QWidget *parent = 0);
    void selectFrame(int frame);
    void selectLayer(int layer);
    void updateView();
signals:
    void onClicked(std::vector<QPoint> points);
    void onPressed(std::vector<QPoint> points);
public slots:
    //void spriteUpdated(Sprite sprite);
};

#endif // CANVAS_H
