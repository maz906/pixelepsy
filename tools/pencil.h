#ifndef PENCIL_H
#define PENCIL_H

#include "sprite/sprite.h"
#include "tools/tool.h"

#include <QWidget>

class Pencil : public QWidget
{
        Q_OBJECT
    public:
        explicit Pencil(QWidget *parent = 0);

        Sprite operation(Sprite sprite,
                         int frame,
                         int layer,
                         std::vector<QPoint> points,
                         QColor foreground,
                         QColor background);

    signals:
        void toolChangedSignal(Tool::Operation oper);
        void toolSelectedSignal();

    public slots:
        void colorChanged(QColor foreground, QColor background);
};

#endif // PENCIL_H
