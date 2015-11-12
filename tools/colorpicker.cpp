#include "colorpicker.h"

ColorPicker::ColorPicker(QWidget *parent) : QWidget(parent)
{
    connect(&fgButton, &QPushButton::clicked, this, &ColorPicker::changeForegroundColor);
    connect(&bgButton, &QPushButton::clicked, this, &ColorPicker::changeBackgroundColor);

    fgButton.setStyleSheet("background-color:white;");
    bgButton.setStyleSheet("background-color:white;");

    layout.addWidget(&fgButton);
    layout.addWidget(&bgButton);

    this->setLayout(&layout);
    this->show();
}

void ColorPicker::changeForegroundColor() {
    QColorDialog* colorDialog = new QColorDialog;
    QColor selected = colorDialog->getColor(fgColor, this);
    if(selected.isValid()) {
        updateFGColor(selected);
    }
}

void ColorPicker::changeBackgroundColor() {
    QColorDialog colorDialog;
    QColor selected = colorDialog.getColor(bgColor, this);
    if(selected.isValid()) {
        updateBGColor(selected);
    }
}
void ColorPicker::updateFGColor(QColor color) {
    fgColor = color;
    fgButton.setStyleSheet("background-color:" + color.name() + ";");

    emit colorChanged(fgColor, bgColor);
}
void ColorPicker::updateBGColor(QColor color) {
    bgColor = color;
    bgButton.setStyleSheet("background-color:" + color.name() + ";");

    emit colorChanged(fgColor, bgColor);
}
