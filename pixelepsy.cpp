#include "pixelepsy.h"
#include "ui_pixelepsy.h"

Pixelepsy::Pixelepsy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pixelepsy)
{
    ui->setupUi(this);
}

Pixelepsy::~Pixelepsy()
{
    delete ui;
}
