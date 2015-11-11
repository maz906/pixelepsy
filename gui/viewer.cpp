#include "gui/viewer.h"

#include <QGraphicsPixmapItem>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QMouseEvent>
#include <QTextStream>

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

void Viewer::selectFrame(int frame) {
    this->frame = frame;
    updateView();
}

void Viewer::selectLayer(int layer) {
    this->layer = layer;
    updateView();
}

void Viewer::updateView() {
    this->view.scene()->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(this->buffer.get()->get(this->frame, this->layer))));
}

void Viewer::mousePressEvent(QMouseEvent* event) {
    QTextStream cout(stdout);
    cout << event->pos().x();
    cout << this->view.pos().x();
    cout << this->scene.
}

QPoint Viewer::findPixmapLocation() {
    this->view.pos();\
    QGraphicsItem* focusItem = this->view.scene()->focusItem();
    QGraphicsView* focusView = this->view.scene()->views().first();
    QPointF point = focusItem->mapToScene(focusItem->boundingRect().bottomRight());
    //return focusView->viewport()->mapToGlobal(focusView->mapFromScene(focusItem->mapToScene(focusItem->boundingRect().bottomRight())));
    return QPoint();
}
