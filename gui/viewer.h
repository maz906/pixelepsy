#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include "sprite/buffer.h"

class Viewer : public QWidget
{
    Q_OBJECT
private:
    Buffer* buffer;
public:
    explicit Viewer(QWidget *parent = 0);

signals:

public slots:
};

#endif // VIEWER_H
