#include "pixelepsy.h"
#include "ui_pixelepsy.h"

#include "buffer.h"
#include "sprite.h"

#include <QGraphicsPixmapItem>

Pixelepsy::Pixelepsy(QWidget *parent)
    : QMainWindow(parent)
    , test(new Buffer(128, 128))
    , scene(new QGraphicsScene())
{
    QImage temp = test->current().get()->getFirst();
    temp.fill(QColor(255, 0, 255, 255));
    item = &QGraphicsPixmapItem(QPixmap::fromImage(temp));
    scene->addItem(item);
    view->show();
}

Pixelepsy::~Pixelepsy()
{
}

