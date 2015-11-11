#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <QGraphicsView>
#include <QPoint>
#include <QScrollArea>
#include <QGraphicsPixmapItem>
#include <QTextStream>
#include <memory>
#include "sprite/buffer.h"
#include "sprite/sprite.h"

#include "gui/spriteview.h"

class Viewer : public QWidget
{
    Q_OBJECT
private:
    int frame;
    int layer;
    std::shared_ptr<Buffer> buffer;
    QGraphicsPixmapItem item;
    QGraphicsScene scene;
    SpriteView view;

public:
    explicit Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent = 0);
    void selectFrame(int frame);
    void selectLayer(int layer);
    void updateView();
    void playback();
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    //finds the location on the pixmap of the pixel clicked
    QPoint pixelLocation(QMouseEvent*);
signals:
public slots:
    //void spriteUpdated(Sprite sprite);
};

#endif // VIEWER_H
