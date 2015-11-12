#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <memory>
#include <vector>

#include "sprite/sprite.h"
#include "sprite/buffer.h"
#include "gui/spriteview.h"

class Canvas : public SpriteView
{
    Q_OBJECT
private:
public:
    explicit Canvas(std::shared_ptr<Buffer> buffer, QWidget *parent = 0);
signals:
};

#endif // CANVAS_H
