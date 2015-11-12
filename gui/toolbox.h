#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>
#include <memory>
#include <vector>

#include "tools/tool.h"

#include "tools/pencil.h"

#include "sprite/buffer.h"

class Toolbox : public QWidget
{
        Q_OBJECT

    private:
        QVBoxLayout layout;

        // Pencil pencil;


    public:
        explicit Toolbox(QWidget *parent = 0);

    signals:

    public slots:
};

#endif // TOOLBOX_H
