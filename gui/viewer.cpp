#include "gui/viewer.h"

#include <QGraphicsPixmapItem>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QMouseEvent>
#include <QMouseEvent>
#include <QTextStream>
#include <iostream>

//#include <memory>
//
//Viewer temp(std::make_shared<Buffer>(width, height), this)
Viewer::Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent)
    : QWidget(parent)
    , frame(0)
    , layer(0)
    , buffer{buffer}
    , item(new QGraphicsPixmapItem(QPixmap::fromImage((this->buffer.get())->get(frame, layer))))
    , scene(new QGraphicsScene)
{
    scene.addItem(&item);
    view.setScene(&scene);
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

//TODO: how to pass down mousePressEvent to scene?
void Viewer::mousePressEvent(QMouseEvent* event) {
    setMouseTracking(true);
}

void Viewer::mouseReleaseEvent(QMouseEvent * event) {
    this->view.viewport()->setMouseTracking(false);
}

QPoint Viewer::pixelLocation(QMouseEvent * event) {
    QGraphicsItem* focus = this->view.scene()->items().at(0);
    QGraphicsView* view = this->scene.views().first();
    QPointF scenePt = focus->boundingRect().topLeft();
    QPoint viewPt = view->mapTo(this, scenePt.toPoint());
    return event->pos() - viewPt;
}

void Viewer::mouseMoveEvent(QMouseEvent * event) {
    QTextStream cout(stdout);
    QPoint temp = pixelLocation(event);
    cout << temp.x() << "," << temp.y() << '\n';
}
