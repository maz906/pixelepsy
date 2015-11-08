#include "pixelepsy.h"
#include "ui_pixelepsy.h"

#include "buffer.h"
#include "sprite.h"

#include <QGraphicsPixmapItem>
#include <iostream>

Pixelepsy::Pixelepsy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pixelepsy)
    , test(new Buffer(128, 128))
{
    QImage temp = test->current().get()->getFirst();
    temp.fill(QColor(255, 0, 255, 255));
    this->ui->setupUi(this);
    //this->ui->stackedLayout->addWidget(); //addWidgets dynamically
    /*this->ui->graphicsView->setScene(new QGraphicsScene);
    this->ui->graphicsView->scene()->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(temp)));
    this->ui->graphicsView->show();*/

}

Pixelepsy::~Pixelepsy()
{
    delete test;
    delete ui;
}

