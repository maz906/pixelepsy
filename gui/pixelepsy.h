#ifndef PIXELEPSY_H
#define PIXELEPSY_H

#include "sprite/buffer.h"
#include "sprite/sprite.h"

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QMdiArea>

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
    QMdiArea* mdiArea;
};

#endif // PIXELEPSY_H
