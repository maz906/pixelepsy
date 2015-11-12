#ifndef TOOL_H
#define TOOL_H

#include <QPushButton>
#include <QLayoutItem>
#include <QPoint>

#include <vector>
#include <functional>

#include "tools/colorpicker.h"
#include "sprite/sprite.h"

class Tool : public QLayoutItem
{

public:
    typedef std::function<Sprite(Sprite, int frame, int layer, std::vector<QPoint>)> Operation;

    virtual ~Tool() {};

    //this should be specialized to an Operation when colorChanged
    //is called
    virtual Sprite operation(const Sprite, std::vector<QPoint>, int frame, int layer, QColor, QColor) = 0;

public slots:
    //specializes operation to an Operation and fires a toolchangedSignal.
    //specialization happens by setting the two QColor arguments in operation
    //to foreground and background
    virtual void colorChanged(QColor foreground, QColor background) = 0;

signals:
    virtual void toolChangedSignal(Operation oper) = 0;

    virtual void toolSelectedSignal() = 0;

};

#endif // TOOL_H
