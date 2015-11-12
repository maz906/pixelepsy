#include "gui/viewer.h"

#include <iostream>
#include <memory>

#include <QGraphicsPixmapItem>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QMouseEvent>
#include <QMouseEvent>
#include <QTextStream>

Viewer::Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent)
    : QWidget(parent)

    , frameIndex(0)
    , layerIndex(0)
    , scale(1)

    , buffer(buffer)
{
    layout.addWidget(&view);

    this->setLayout(&layout);
    this->setContentsMargins(0, 0, 0, 0);

    updateView();

    view.show();
}


void Viewer::updateView() {
    scene.clear();

    // Display all the layers
    Frame frame = buffer->current()->getFrame(frameIndex);
    for(auto layer = frame.getLayersBegin(); layer != frame.getLayersEnd(); layer++) {
        scene.addPixmap(QPixmap::fromImage(**layer))
            ->show();
    }

    view.scale(scale, scale);
}
