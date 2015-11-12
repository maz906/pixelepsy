#ifndef VIEWER_H
#define VIEWER_H

#include <memory>

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QWidget>
#include <memory>
#include <vector>

#include "sprite/buffer.h"
#include "sprite/sprite.h"
#include "gui/spriteview.h"

class Viewer : public SpriteView
{
    Q_OBJECT
private:

public:
    explicit Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent = 0);
    void playback();
    void mousePressEvent(QMouseEvent *) {};
    void mouseMoveEvent(QMouseEvent *) {};
    void mouseReleaseEvent(QMouseEvent *) {};
signals:
};

#endif // VIEWER_H
