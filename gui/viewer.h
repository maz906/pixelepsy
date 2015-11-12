#ifndef VIEWER_H
#define VIEWER_H

#include <memory>

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPoint>
#include <QScrollArea>
#include <QTextStream>
#include <QWidget>

#include "sprite/buffer.h"
#include "sprite/sprite.h"

#include "gui/spriteview.h"

// TODO: Frame playback
class Viewer : public QWidget
{
    Q_OBJECT
private:
    int frameIndex;
    int layerIndex;

    double scale;

    std::shared_ptr<Buffer> buffer;

    QVBoxLayout layout;

    QGraphicsScene scene;
    QGraphicsView view{&scene, this};

public:
    explicit Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent = 0);

    void updateView();
    void playback();

signals:

public slots:
    //void spriteUpdated(Sprite sprite);
};

#endif // VIEWER_H
