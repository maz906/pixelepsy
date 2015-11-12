#include "gui/viewer.h"

#include <iostream>
#include <memory>

#include <QGraphicsPixmapItem>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QMouseEvent>
#include <QTextStream>

Viewer::Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent)
    : SpriteView(buffer, parent)
{
}
