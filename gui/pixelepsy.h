#ifndef PIXELEPSY_H
#define PIXELEPSY_H

#include "sprite/buffer.h"
#include "sprite/sprite.h"

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QMdiArea>
#include <QFileDialog>

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
    QAction* actionNew;
    QFileDialog* fileDialog;

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionNew_triggered();
};

#endif // PIXELEPSY_H
