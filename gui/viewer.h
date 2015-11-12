#ifndef VIEWER_H
#define VIEWER_H

#include <memory>

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPoint>
#include <QScrollArea>
#include <QTextStream>
#include <QWidget>

#include <vector>

#include "sprite/buffer.h"
#include "sprite/sprite.h"

#include "gui/spriteview.h"

// TODO: Frame playback
class Viewer : public QGraphicsView
{
    Q_OBJECT
private:
    int frameIndex;
    int layerIndex;

    double scala;

    std::shared_ptr<Buffer> buffer;
    std::vector<QPoint> points;
    QVBoxLayout layout;

    QGraphicsScene scene;
    //SpriteView view{&scene, this};

public:
    explicit Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent = 0);
    void selectFrame(int frame);
    void selectLayer(int layer);
    void updateView();
    void playback();
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    QPoint pixelLocation(QMouseEvent* event);
    bool checkPoint(QPoint);
signals:

public slots:
    //void spriteUpdated(Sprite sprite);
};

#endif // VIEWER_H
