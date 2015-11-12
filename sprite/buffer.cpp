#include "sprite/buffer.h"

#include <memory>
#include <sstream>

#include <QImage>
#include <QPoint>

#define SPACE " "
#define NEWLINE '\n'

Buffer::Buffer(int width, int height)
{
    history.push_back(std::make_shared<Sprite>(width, height));
}

QImage Buffer::get(int frame, int layer) {
    return *(this->current().get())->getFrame(frame).getLayer(layer);
}

std::shared_ptr<Sprite> Buffer::current() {
    return history.back();
}

void Buffer::applyOperation(int frame, int layer, std::vector<QPoint> &points) {
    // Apply the operation
    history.push_back(std::make_shared<Sprite>(operation(*(history.back().get()), frame, layer, points)));
}

QString Buffer::toString() {
    std::stringstream stream;
    stream << this->current()->getHeight() << SPACE
           << this->current()->getWidth() << SPACE
           << NEWLINE;


    stream << this->current()->getFrames().size() << NEWLINE;

    for (Frame frame : this->current()->getFrames()) {
        for (auto layer = frame.getLayersBegin(); layer != frame.getLayersEnd(); layer++)
        {
            QImage image = *((*layer).get());
            for (int i = 0; i < image.height(); i++) {
                for (int j = 0; j < image.width(); j++) {
                    QColor color = image.pixel(j, i);
                    stream << color.red() << SPACE
                           << color.green() << SPACE
                           << color.blue() << SPACE
                           << color.alpha() << SPACE;
                }
                stream << NEWLINE;
            }
        }
    }


    return QString::fromStdString(stream.str());





}
