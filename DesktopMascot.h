#pragma once
#include <QtGui>
#include "LeapController.h"
#include "DesktopLauncher.h"
#include <QTimer>

namespace mascot{

    class DesktopMascot : public QGraphicsView
    {
        Q_OBJECT
    
    private:
        static const int MAX_WINDOW_SIZE_X = 1280;
        static const int MAX_WINDOW_SIZE_Y = 640;
        QGraphicsScene       m_scene;
        QPixmap              m_flyPixmap;
        QPixmap              m_standPixmap;
        QGraphicsPixmapItem  m_mascotItem;
        DesktopLauncher      m_blockLauncher;
        Leap::Controller     m_controller;
        QTimer               m_timer;
        void initScene();
        void connectSignals();
        void setImage(QGraphicsPixmapItem &item);

    public:
        explicit DesktopMascot(QWidget *parent = 0);
        void setPos(QPointF pos);
        QPointF pos();

    public slots:
        void updateStatus();      
        
    };

}; //namespace mascot