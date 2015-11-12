#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QPushButton>
#include <QImage>
#include <QPainter>
#include "sprite/sprite.h"
#include "sprite/buffer.h"
#include <QHBoxLayout>

class Timeline : public QWidget
{
    Q_OBJECT
private:
    std::vector<QPushButton> buttons;
    QHBoxLayout layout;
    int currentIndex;

public:
    explicit Timeline(QWidget *parent = 0);
    Timeline(Buffer b);

signals:
    void changeFrame(int index);

public slots:
    void changeCurrentFrame();
};

#endif // TIMELINE_H
