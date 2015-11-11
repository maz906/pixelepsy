#include "colorpicker.h"

ColorPicker::ColorPicker(QWidget *parent) : QWidget(parent)
{
    connect(&fgButton, &QPushButton::clicked, this, &ColorPicker::changeForegroundColor);
    connect(&bgButton, &QPushButton::clicked, this, &ColorPicker::changeBackgroundColor);

    stylesheet = "background-color:";
    //Start with a white color for both buttons.
    color = "white;";

    fgButton.setStyleSheet("background-color:white;");
    bgButton.setStyleSheet("background-color:white;");

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
        updateFGColors();
    }
}

void ColorPicker::changeBackgroundColor() {
    QColorDialog* colorDialog = new QColorDialog;
    QColor temp;
    temp = colorDialog->getColor(bgColor, this);
    if(temp.isValid()) {
        bgColor = temp;
        updateBGColors();
    }
}
void ColorPicker::updateFGColors() {
    color = fgColor.name() + ";";
    fgButton.setStyleSheet(stylesheet + color);
    emit colorChanged(fgColor, bgColor);

}
void ColorPicker::updateBGColors() {
    color = bgColor.name() + ";";
    bgButton.setStyleSheet(stylesheet + color);
    emit colorChanged(fgColor, bgColor);

}
