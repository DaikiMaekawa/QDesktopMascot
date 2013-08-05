#pragma once
#include <QtGui>

namespace mascot{

    class DesktopLauncher : public QGraphicsPixmapItem{
        static const int OBJECT_SIZE_X = 100;
        static const int OBJECT_SIZE_Y = 100;
        
    public:
        DesktopLauncher(const QPixmap &pixmap);
        bool isCrash(QPointF obs);

    };

}; //namespace mascot