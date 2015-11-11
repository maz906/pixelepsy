#include "colorpicker.h"

ColorPicker::ColorPicker(QWidget *parent) : QWidget(parent)
{
    connect(&fgButton, &QPushButton::clicked, this, &ColorPicker::changeForegroundColor);

    pal.setColor(QPalette::Background,Qt::red);
    fgButton.setAutoFillBackground(true);
    fgButton.setPalette(pal);
    fgButton.setFlat(true);
    fgButton.setStyleSheet("background-color:red;");


    layout.addWidget(&fgButton);
    layout.addWidget(&bgButton);

    this->setLayout(&layout);
    this->show();
}
ColorPicker::~ColorPicker() {

}

void ColorPicker::changeForegroundColor() {
    QColorDialog* colorDialog = new QColorDialog;
    QColor temp;
    temp = colorDialog->getColor(fgColor, this);
    if(temp.isValid()) {
        fgColor = temp;
        updateColors();
    }
}
void ColorPicker::updateColors() {
    pal.setColor(QPalette::Background,fgColor);
    fgButton.setPalette(pal);
    fgButton.update();
}
