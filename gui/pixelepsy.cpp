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
    QImage temp = test->get(0,0);
    temp.fill(QColor(255, 0, 255, 255));
    //essential, do not remove
    this->ui->setupUi(this);
    //QMdiaArea for subwindows
    this->setCentralWidget(mdiArea);

    //example of adding a widget and layouts.
    QWidget* tools = new QWidget;
    tools->setGeometry(QRect(100, 100, 100, 100));
    tools->setWindowTitle("OMG");
    mdiArea->addSubWindow(tools);
    //mdiArea->setLayout(new QHBoxLayout(mdiArea));
    //mdiArea->layout()->addWidget(tools);
    //mdiArea won't allow adding widgets. only subwindows.
    tools->show();
}

Pixelepsy::~Pixelepsy()
{
    delete test;
    delete ui;
}

/*
 * Menu Bar - Open Button
 */
void Pixelepsy::on_actionOpen_triggered()
{
    // Opens new file - Set to automatically go to root
    QString fileName = QFileDialog::getOpenFileName(this, tr("TEsting"), "/", tr("fucking files (*.fuck)"));

}

/*
 * Menu Bar - Save Button
 */
void Pixelepsy::on_actionSave_triggered()
{

}

/*
 * Menu Bar - Save As Button
 */
void Pixelepsy::on_actionSave_As_triggered()
{

}

/*
 * Menu Bar - New Button
 */
void Pixelepsy::on_actionNew_triggered()
{
    // Will store the state whether user pressed Ok button or cancel.
    bool userChoice;
    QString userInputDimension = QInputDialog::getText(this, tr("Dimension test"),
                                                       tr("Your dimension here"),
                                                       QLineEdit::Normal,
                                                       QDir::home().dirName(), &userChoice);

    if(userChoice){
        // Only if user doesn't press on cancel button.
        QString userInputDimension2 = QInputDialog::getText(this, tr("Dimension test"),
                                                            tr("Your dimension here"), QLineEdit::Normal,
                                                            QDir::home().dirName(), &userChoice);
    }

}
