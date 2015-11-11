#include "gui/viewer.h"

#include <QGraphicsPixmapItem>
#include <QGridLayout>

//#include <memory>
//
//Viewer temp(std::make_shared<Buffer>(width, height), this)
Viewer::Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent)
    : QWidget(parent)
    , scene(new QGraphicsScene)
    , item(new QGraphicsPixmapItem)
{
    frame = layer = 0;
    this->buffer = buffer;
    view.setScene(new QGraphicsScene);
    view.scene()->addItem(new QGraphicsPixmapItem(QPixmap::fromImage((this->buffer.get())->get(frame, layer))));
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(&view, 1, 1, Qt::AlignHCenter | Qt::AlignVCenter);
    this->setLayout(layout);
    view.show();
}

Viewer::selectFrame(int frame) {
    this->frame = frame;
    updateView();
}

Viewer::selectLayer(int layer) {
    this->layer = layer;
    updateView();
}

Viewer::updateView() {
    this->view.scene()->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(this->buffer.get()->get(this->frame, this->layer))));
}



