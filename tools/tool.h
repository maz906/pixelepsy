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
    typedef std::function<Sprite(const Sprite, std::vector<QPoint>)> Operation;

    Tool();
    //this should be specialized to an Operation when colorChanged
    //is called
    virtual Sprite operation(const Sprite, std::vector<QPoint>, QColor, QColor);

public slots:
    //specializes operation to an Operation and fires a toolchangedSignal.
    //specialization happens by setting the two QColor arguments in operation
    //to foreground and background
    virtual void colorChanged(QColor foreground, QColor background);

signals:
    virtual void toolChangedSignal(Operation oper);

};

#endif // TOOL_H
