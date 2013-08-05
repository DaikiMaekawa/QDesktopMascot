#pragma once
#include <QtGui>

namespace mascot{

    class FieldObject : public QGraphicsPixmapItem{
        static const int OBJECT_SIZE_X = 100;
        static const int OBJECT_SIZE_Y = 100;

    public:
        FieldObject(const QPixmap &pixmap);
        bool isCrash(QPointF obs);

    };

}; //namespace mascot