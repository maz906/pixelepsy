#ifndef PIXELEPSY_H
#define PIXELEPSY_H

#include "sprite/buffer.h"
#include "sprite/sprite.h"

#include <memory>

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QMdiArea>
#include <QFileDialog>
#include <QShortcut>
#include <QKeySequence>
#include <QInputDialog>
#include <QMessageBox>
#include <QPair>
#include <QSaveFile>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>

namespace Ui {
class Pixelepsy;
}

class Pixelepsy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pixelepsy(QWidget *parent = 0);
    ~Pixelepsy();
    void createFileActions();
    void createAction(QMenu*, QAction*, const QString&, std::function<void()> func);
    void connectToolboxToMain();
    void newProject();
private:
    Ui::Pixelepsy *ui;
    QMdiArea* mdiArea;
    QFileDialog* fileDialog;
    QString filename;
    QShortcut* newFileShortcut;
    QInputDialog* newFileVerticalInput;
    QInputDialog* newFileHorizontalInput;
    QSaveFile save;
    bool fileSaved;
    bool cancelFlag;
    QMenu* File;
    QAction* actionNew;
    QAction* actionOpen;
    QAction* actionSave;
    QAction* actionSaveAs;
    QMenuBar* bar;
    QImage* image;

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionNew_triggered();
    void get_user_dimension();
    void add_viewer(int horiz, int vert);
};

#endif // PIXELEPSY_H
