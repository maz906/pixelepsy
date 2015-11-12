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
class Viewer : public SpriteView
{
    Q_OBJECT
private:

public:
    explicit Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent = 0);
    void playback();
signals:

public slots:
    //void spriteUpdated(Sprite sprite);
};

#endif // VIEWER_H
