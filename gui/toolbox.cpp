#include "gui/toolbox.h"

#include <QGridLayout>
Toolbox::Toolbox(QWidget *parent) : QWidget(parent)
{
    this->setLayout(new QGridLayout(this)); //tools will be presented in a grid
}

Toolbox::Toolbox(Toolkit tools, QWidget *parent, int cols) : QWidget(parent){
    this->tools = tools;
    this->setLayout(new QGridLayout(this));

    //place the tools into the grid
    int col = 0; int row = 0;
    QGridLayout* layout = (QGridLayout*) this->layout();
    for (auto it = tools.begin(); it != tools.end(); it++)
    {
        if (col < cols)
            col++;
        else if (col == cols)
        {
            col = 0;
            row++;
        }
        //(*it).get() is a Tool, should be ToolButton
        layout->addItem((*it).get(), row, col);
    }
}

