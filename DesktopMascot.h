#pragma once
#include <QtGui>

namespace mascot{

    class DesktopMascot : public QGraphicsView
    {
        QGraphicsScene m_scene;
        QGraphicsPixmapItem m_centerPixmap;
        void initScene();

    public:
        DesktopMascot(QWidget *parent = 0);
        
    };

}; //namespace mascot