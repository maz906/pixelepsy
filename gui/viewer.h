#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <QGraphicsView>
#include <QScrollArea>

#include <memory>
#include "sprite/buffer.h"

class Viewer : public QWidget
{
    Q_OBJECT
private:
    std::shared_ptr<Buffer> buffer;
    QGraphicsView view;
    QScrollArea scoller;
    int frame;
    int layer;

public:
    explicit Viewer(std::shared_ptr<Buffer> buffer, QWidget *parent = 0);
signals:

public slots:
};

#endif // VIEWER_H
