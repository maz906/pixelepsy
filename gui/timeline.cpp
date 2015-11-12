#include "timeline.h"

#include <QPushButton>
#include <QPixmap>

Timeline::Timeline(Buffer b)
{

    for(int i = 0; i < b.current()->getFrames().size(); i++) {
        QPushButton a;
        currentIndex = i;
        a.setIcon(QPixmap::fromImage(*(b.current()->getFrame(i).getFirst().get())));
        buttons.push_back(a);
        layout.addWidget(&buttons.at(i));
        connect(a, SIGNAL(clicked()), this, SLOT(changeCurrentFrame()));
    }
    this->setLayout(&layout);
    this->show();

}
void Timeline::changeCurrentFrame() {
    emit changeFrame(currentIndex);
}

