#ifndef PIXELEPSY_H
#define PIXELEPSY_H

#include "buffer.h"
#include "sprite.h"

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>

namespace Ui {
class Pixelepsy;
}

class Pixelepsy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pixelepsy(QWidget *parent = 0);
    ~Pixelepsy();

private:
    Ui::Pixelepsy *ui;
    Buffer* test;
};

#endif // PIXELEPSY_H
