#include "gui/pixelepsy.h"
#include "ui_pixelepsy.h"

#include "sprite/buffer.h"
#include "sprite/sprite.h"
#include "gui/viewer.h"

#include <functional>
#include <memory>

#include <QGraphicsPixmapItem>
#include <QMdiArea>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QColor>
#include <QDebug>
#include <QTextStream>


Pixelepsy::Pixelepsy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pixelepsy)
    , mdiArea(new QMdiArea)
    , bar(new QMenuBar)
{
    this->setMenuBar(bar);
    this->createFileActions();
    //essential, do not remove
    //this->ui->setupUi(this);
    //QMdiaArea for subwindows
    this->setCentralWidget(mdiArea);

    //example of adding a widget and layouts.
    //QWidget* tools = new QWidget;
    //tools->setGeometry(QRect(100, 100, 100, 100));
    //tools->setWindowTitle("OMG");
    //mdiArea->addSubWindow(tools);
    //mdiArea->setLayout(new QHBoxLayout(mdiArea));
    //mdiArea->layout()->addWidget(tools);
    //mdiArea won't allow adding widgets. only subwindows.
    //tools->show();
    fileSaved = true;
    cancelFlag = false;
    ColorPicker* c = new ColorPicker;
    mdiArea->addSubWindow(c);

//    fileSaved = false;
//    ColorPicker* c = new ColorPicker;
//    mdiArea->addSubWindow(c);

}

Pixelepsy::~Pixelepsy()
{
    delete ui;
}

/*
 * Helper method which will send prompt when a new project would
 * occur before save operation
 */
void Pixelepsy::newProject(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Save changes to the document before closing?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if (reply == QMessageBox::Yes)
    {
        on_actionSave_triggered();
    }
    else if (reply == QMessageBox::No)
    {
        //TODO: Reset the sprite class and window
    } else {
        cancelFlag = true;
    }
}


void Pixelepsy::connectToolboxToMain(){

}

void Pixelepsy::createFileActions() {
    this->File = new QMenu(tr("&File"));
    this->menuBar()->addMenu(this->File);
    createAction(this->File, this->actionNew, "New", std::bind(&Pixelepsy::on_actionNew_triggered, this));
    createAction(this->File, this->actionOpen, "Open", std::bind(&Pixelepsy::on_actionOpen_triggered, this));
    createAction(this->File, this->actionSave, "Save", std::bind(&Pixelepsy::on_actionSave_triggered, this));
    createAction(this->File, this->actionSaveAs, "Save As", std::bind(&Pixelepsy::on_actionSave_As_triggered, this));
}

void Pixelepsy::createAction(QMenu* menu, QAction* action, const QString& text, std::function<void()> func) {
    action = new QAction(text, menu);
    menu->addAction(action);
    connect(action, &QAction::triggered, this, func);
}

/*
 * Menu Bar - Open Button
 */
void Pixelepsy::on_actionOpen_triggered()
{
    if (!fileSaved)
        newProject();
    if(cancelFlag || fileSaved){
        QFile file(QFileDialog::getOpenFileName(this, "Select a file to open...", "../", tr("Sprite Projects (*.ssp)")));

        //as long as file can be opened, proceed
        if (file.exists())
        {
            //create parameters to load from buffer
            int width, height, frames;

            file.open(QIODevice::ReadOnly);
            QTextStream fileStream(&file);
            fileStream >> width >> height;
            fileStream >> frames;
            int red, green, blue, alpha;
            Buffer* buffer = new Buffer(width, height);
            for (int frame = 0; frame < frames; frame++) {
                if (frame)
                    buffer->current()->addFrame();
                for (int x = 0; x < width; x++) {
                    for (int y = 0; y < height; y++) {
                        fileStream >> red >> green >> blue >> alpha;
                        QRgb value = qRgba(red, green, blue, alpha);
                        buffer->get(frame, 0).setPixel(x, y, value);
                    }
                }
            }
            Viewer* view = new Viewer(std::shared_ptr<Buffer>(buffer));
            this->mdiArea->addSubWindow(view);
            view->show();
            view->updateView();
        }
    }
}

/*
 * Menu Bar - Save Button
 */
void Pixelepsy::on_actionSave_triggered()
{
    // If file isn't saved yet/
    if (!fileSaved){
        // do file saving process.
        filename = fileDialog->getSaveFileName(this, tr("Save Sprite"), "untitled.ssp", tr("Sprites (*.ssp)"));
        QFile file(filename);
        if(file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream filestream(&file);
            Buffer b(2, 3);
            filestream << b.toString() << endl;
            //set flag for saved file
            // fileSaved = true;
        }
    }
}

/*
 * Menu Bar - Save As Button
 */
void Pixelepsy::on_actionSave_As_triggered()
{
        // do file saving process.
        filename = fileDialog->getSaveFileName(this, tr("Save Sprite"), "untitled.ssp", tr("Sprites (*.ssp)"));
        QFile file(filename);
        if(file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream filestream(&file);
            filestream << "test text" << endl;
            //set flag for saved file
            // fileSaved = true;
        }

}

/*
 * Menu Bar - New Button
 */
void Pixelepsy::on_actionNew_triggered()
{
    get_user_dimension();
}

/*
 * Populate input dialog to get dimension from the user.
 */
void Pixelepsy::get_user_dimension()
{
    // Will store the state whether user pressed Ok button or cancel.
    bool userChoice1;
    bool userChoice2;
    bool convertState;
    int width;
    int height;

    while (true) {
        // Ask user for the input.
        QString horizontalInput = QInputDialog::getText(this,
                                                           tr("New File"),
                                                           tr("Please enter your width dimension."),
                                                           QLineEdit::Normal,
                                                           "",
                                                           &userChoice1);
        // If user chooses to cancel, get out of the loop.
        if (!userChoice1){
            break;
        }

        width = horizontalInput.toInt(&convertState, 10);

        // If user input cannot be converted into an integer.
        if (width <= 0 || !convertState){

            //TODO Change message box text.
            QMessageBox invalidInputPrompt;
            invalidInputPrompt.setText("You entered an incorrect input. Please try again.");
            invalidInputPrompt.exec();

            continue;
        } else {

            // Obtain vertical dimension from user
            while (true) {
                QString verticalInput = QInputDialog::getText(this,
                                                               tr("New File"),
                                                               tr("Please enter your height dimension."),
                                                               QLineEdit::Normal,
                                                               "",
                                                               &userChoice2);
                // If user chooses to cancel, get out of the loop.
                if(!userChoice2){
                    break;
                }

                height = verticalInput.toInt(&convertState, 10);

                // If user input cannot be converted into an integer.
                if (height <= 0 || !convertState){

                    //TODO: Change message box text.
                    QMessageBox invalidInputPrompt;
                    invalidInputPrompt.setText("You entered an incorrect input. Please try again.");
                    invalidInputPrompt.exec();

                    continue;
                } else {
                    break;
                }
            }
        }
    break;
    }
    //TODO: add a scale so that the canvases aren't so small
    if(userChoice1 && userChoice2){
        add_viewer(width, height);
    }
}

void Pixelepsy::add_viewer(int width, int height){
    Viewer* newView = new Viewer(std::make_shared<Buffer>(width, height));
    this->mdiArea->addSubWindow(newView);
    newView->show();
}
