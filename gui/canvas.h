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
    void onClicked(std::vector<QPoint> points);
    void onPressed(std::vector<QPoint> points);
public slots:
    //void spriteUpdated(Sprite sprite);
};

#endif // CANVAS_H
