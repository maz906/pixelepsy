#ifndef BUFFER_H
#define BUFFER_H

#include "sprite/sprite.h"

#include <deque>
#include <functional>
#include <memory>
#include <vector>

#include <QObject>
#include <QPoint>

class Buffer : QObject
{
    Q_OBJECT



private:
    typedef std::function<Sprite(Sprite, std::vector<QPoint>)> Operation;

    std::deque<std::shared_ptr<Sprite>> history;
    std::deque<std::shared_ptr<Sprite>> future;

    std::shared_ptr<Operation> operation;
public:
    Buffer() = delete;

    Buffer(int width, int height);

    std::shared_ptr<Sprite> current();
};

#endif // BUFFER_H
