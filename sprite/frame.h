#ifndef FRAME_H
#define FRAME_H

#include <memory>
#include <vector>

#include <QImage>

class Frame
{
private:
    int width;
    int height;

    std::vector<std::shared_ptr<QImage>> layers;
public:
    Frame(int width, int height);
    std::shared_ptr<QImage> getLayer(int layer);

    std::vector<std::shared_ptr<QImage>>::const_iterator getLayersBegin();
    std::vector<std::shared_ptr<QImage>>::const_iterator getLayersEnd();
};

#endif // FRAME_H
