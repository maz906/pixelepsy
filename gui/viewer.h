#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <QGraphicsView>
#include <QScrollArea>
#include <QGraphicsPixmapItem>
#include <memory>
#include "sprite/buffer.h"
#include "sprite/sprite.h"

class Viewer : public QWidget
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
    explicit Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent = 0);
    void selectFrame(int frame);
    void selectLayer(int layer);
    void updateView();
    void playback();
    void mousePressEvent(QMouseEvent *);
signals:
public slots:
    //void spriteUpdated(Sprite sprite);
};

#endif // VIEWER_H
