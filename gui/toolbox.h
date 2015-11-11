#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>
#include <memory>
#include <vector>

#include "tools/tool.h"
#include "sprite/buffer.h"

class ToolButton : public QPushButton
{
    Q_OBJECT
private:
    Tool *tool;
};

class Toolbox : public QWidget
{
    Q_OBJECT
    typedef std::vector<std::shared_ptr<ToolButton>> Toolkit;
private:
    Toolkit tools;
    std::vector<Buffer> buffers;
public:
    explicit Toolbox(QWidget *parent = 0);
    explicit Toolbox(Toolkit tools, QWidget *parent = 0, int cols = 1);

signals:
    void toolChanged(Tool&, Tool::Operation);

public slots:
    //should take in a Tool
    // void toolSelected(Tool::Operation);
};

#endif // TOOLBOX_H
