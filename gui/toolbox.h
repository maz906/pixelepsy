#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>
#include <memory>
#include <vector>

#include <tools/tool.h>

class Toolbox : public QWidget
{
    Q_OBJECT
    typedef std::vector<std::shared_ptr<Tool>> Toolkit;
private:
    Toolkit tools;
public:
    explicit Toolbox(QWidget *parent = 0);
    explicit Toolbox(Toolkit tools, QWidget *parent = 0, int cols = 1);



signals:

public slots:
};

#endif // TOOLBOX_H
