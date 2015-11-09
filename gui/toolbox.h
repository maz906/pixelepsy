#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>
#include <memory>
#include <vector>

#include "tools/tool.h"
#include "sprite/buffer.h"

class Toolbox : public QWidget
{
    Q_OBJECT
    typedef std::vector<std::shared_ptr<Tool>> Toolkit;
private:
    Toolkit tools;
    std::vector<Buffer> buffers;
public:
    explicit Toolbox(QWidget *parent = 0);
    explicit Toolbox(Toolkit tools, QWidget *parent = 0, int cols = 1);

signals:
    //should take in a Tool
    void pickToolSignal(Tool::Operation tool);

public slots:
    void toolChangedSlot(Tool& tool, Tool::Operation oper);
};

#endif // TOOLBOX_H
