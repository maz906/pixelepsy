#include "pencil.h"

#include <functional>

#include <QColor>

#include "tools/tool.h"

Pencil::Pencil(QWidget *parent) : QWidget(parent)
{

}

Sprite Pencil::operation(Sprite sprite,
                         int frame,
                         int layer,
                         std::vector<QPoint> points,
                         QColor foreground,
                         QColor background)
{
    for(auto point : points) {
        sprite.getFrame(frame)
              .getLayer(layer)
              ->setPixel(point.x(), point.y(), foreground.rgb());
    }

    return sprite;
}

void Pencil::colorChanged(QColor foreground, QColor background)
{
    auto oper = std::bind(&Pencil::operation, this,
                          std::placeholders::_1,
                          std::placeholders::_2,
                          std::placeholders::_3,
                          std::placeholders::_4,
                          foreground,
                          background);

    emit toolChangedSignal(oper);
}
