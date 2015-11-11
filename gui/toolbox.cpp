#include "gui/toolbox.h"

#include <QGridLayout>
Toolbox::Toolbox(QWidget *parent) : QWidget(parent)
{
    //tools will be presented in a grid
    this->setLayout(new QGridLayout(this));
}

Toolbox::Toolbox(Toolkit tools, QWidget *parent, int cols) : QWidget(parent)
{
    this->tools = tools;
    this->setLayout(new QGridLayout(this));

    //place the tools into the grid
    int col, row = 0;
    QGridLayout* layout = (QGridLayout*) this->layout();
    for (auto toolContainer = tools.begin(); toolContainer != tools.end(); toolContainer++)
    {
        if (col < cols)
            col++;
        else if (col == cols)
        {
            col = 0;
            row++;
        }

        layout->addWidget((*toolContainer).get(), row, col);
    }
    // connect(&tools,SIGNAL(toolChanged(ToolButton &tool, )), this,SLOT(Tool::Operation));

}


