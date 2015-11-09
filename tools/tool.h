#ifndef TOOL_H
#define TOOL_H

#include <QPushButton>
#include <QPoint>

#include <vector>
#include <functional>

#include "tools/colorpicker.h"
#include "sprite/sprite.h"

class Tool : public ColorPicker
{

public:
    typedef std::function<Sprite(Sprite, std::vector<QPoint>)> Operation;

    Tool();
    virtual QImage operation(QImage, std::vector<QPoint>);

public slots:
    virtual void foregroundColorChanged(QColor color);
    virtual void backgroundColorChanged(QColor color);

private:
    QColor foreground;
    QColor background;

signals:
    virtual void toolChangedSignal(Operation oper);

};

#endif // TOOL_H
