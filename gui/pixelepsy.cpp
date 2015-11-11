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
    // If file isn't saved yet/
    if (!fileSaved){
        // do file saving process.
    }
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
    QPair<int, int> userDimension = get_user_dimension();

    QMessageBox invalidInputPrompt;
    QString tmp = QString::number(userDimension.first);
    tmp.append(" and ");
    tmp.append(QString::number(userDimension.second));
    invalidInputPrompt.setText(tmp);
    invalidInputPrompt.exec();

}


/*
 * Populate input dialog to get dimension from the user.
 */
QPair<int, int> Pixelepsy::get_user_dimension()
{
    // Will store the state whether user pressed Ok button or cancel.
    bool userChoice1;
    bool userChoice2;
    bool convertState;
    int horizontalDimension;
    int verticalDimension;
    QPair<int, int> returnValue;

    while (true) {
        // Ask user for the input.
        QString horizontalInput = QInputDialog::getText(this,
                                                           tr("Horizontal Dimension test"),
                                                           tr("Your dimension here"),
                                                           QLineEdit::Normal,
                                                           QDir::home().dirName(),
                                                           &userChoice1);
        // If user chooses to cancel, get out of the loop.
        if (!userChoice1){
            break;
        }

        horizontalDimension = horizontalInput.toInt(&convertState, 10);

        // If user input cannot be converted into an integer.
        if (horizontalDimension <= 0 || !convertState){

            //TODO Change message box text.
            QMessageBox invalidInputPrompt;
            invalidInputPrompt.setText("wrong input @ horizontal");
            invalidInputPrompt.exec();

            continue;
        } else {
            returnValue.first = horizontalDimension;

            // Obtain vertical dimension from user
            while (true) {
                QString verticalInput = QInputDialog::getText(this,
                                                               tr("Vertical Dimension test"),
                                                               tr("Your dimension here"),
                                                               QLineEdit::Normal,
                                                               QDir::home().dirName(),
                                                               &userChoice2);
                // If user chooses to cancel, get out of the loop.
                if(!userChoice2){
                    break;
                }

                verticalDimension = verticalInput.toInt(&convertState, 10);

                // If user input cannot be converted into an integer.
                if (verticalDimension <= 0 || !convertState){

                    //TODO: Change message box text.
                    QMessageBox invalidInputPrompt;
                    invalidInputPrompt.setText("wrong input @ vertical");
                    invalidInputPrompt.exec();

                    continue;
                } else {
                    returnValue.second = verticalDimension;
                    break;
                }
            }
        }
    break;
    }

    return returnValue;
}

