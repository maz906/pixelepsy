#ifndef PIXELEPSY_H
#define PIXELEPSY_H

#include "buffer.h"
#include "Sprite.h"

#include <QMainWindow>
#include <QGraphicsPixmapItem>

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
    Buffer* test;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QGraphicsPixmapItem* item;
    Ui::Pixelepsy *ui;
};

#endif // PIXELEPSY_H
