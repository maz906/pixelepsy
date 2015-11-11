#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QPushButton>
#include <QImage>
#include <QPainter>
#include "sprite/frame.h"

class Timeline : public QWidget
{
    Q_OBJECT
    std::vector<QPushButton> buttons;
    std::map<QImage, QPushButton>;

public:
    explicit Timeline(QWidget *parent = 0);

signals:
    void changeFrame()

public slots:
};

#endif // TIMELINE_H
