#ifndef PIXELEPSY_H
#define PIXELEPSY_H

#include <QMainWindow>

namespace Ui {
class Pixelepsy;
}

class Pixelepsy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pixelepsy(QWidget *parent = 0);
    ~Pixelepsy();

private:
    Ui::Pixelepsy *ui;
};

#endif // PIXELEPSY_H
