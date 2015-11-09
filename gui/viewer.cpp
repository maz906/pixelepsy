#include "gui/viewer.h"

#include <QGraphicsPixmapItem>
#include <QGridLayout>

Viewer::Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent)
    : QWidget(parent)
{
    frame = layer = 0;
    this->buffer = buffer;
    view.setScene(new QGraphicsScene);
    view.scene()->addItem(new QGraphicsPixmapItem(QPixmap::fromImage((this->buffer.get())->get(frame, layer))));
    this->setLayout(new QGridLayout);
    view.show();

}


