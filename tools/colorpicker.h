#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QColor>
#include <QColorDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPalette>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class ColorPicker : public QWidget
{
    Q_OBJECT

    QPushButton fgButton;
    QPushButton bgButton;

    QVBoxLayout layout;

    QColor fgColor;
    QColor bgColor;
public:
    explicit ColorPicker(QWidget *parent = 0);

    QColor getForegroundColor();
    QColor getBackgroundColor();

    void updateFGColor(QColor color);
    void updateBGColor(QColor color);

signals:
    void colorChanged(QColor fgColor, QColor bgColor);

public slots:
    void changeForegroundColor();
    void changeBackgroundColor();
};

#endif // COLORPICKER_H
