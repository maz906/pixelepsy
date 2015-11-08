#include "gui/pixelepsy.h"
#include "ui_pixelepsy.h"

#include "sprite/buffer.h"
#include "sprite/sprite.h"

#include <QGraphicsPixmapItem>
#include <QMdiArea>
#include <QHBoxLayout>

Pixelepsy::Pixelepsy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pixelepsy)
    , test(new Buffer(128, 128))
    , mdiArea(new QMdiArea)
{
    QImage temp = test->current().get()->getFirst();
    temp.fill(QColor(255, 0, 255, 255));
    this->ui->setupUi(this); //essential, do not remove
    this->setCentralWidget(mdiArea); //QMdiaArea for subwindows

    //example of adding a widget and layouts.
    QWidget* tools = new QWidget;
    tools->setGeometry(QRect(100, 100, 100, 100));
    tools->setWindowTitle("OMG");
    mdiArea->addSubWindow(tools);
    mdiArea->setLayout(new QHBoxLayout(mdiArea));
    mdiArea->layout()->addWidget(tools);
    //mdiArea won't allow adding widgets. only subwindows.
    tools->show();
}

Pixelepsy::~Pixelepsy()
{
    delete test;
    delete ui;
}

