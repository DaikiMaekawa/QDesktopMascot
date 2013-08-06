#pragma once
#include <QtGui>
#include "DesktopLauncher.h"
#include <QTimer>
#include <Leap.h>
#include <QVector>
#include <boost/shared_ptr.hpp>

namespace mascot{
    
    typedef boost::shared_ptr<DesktopLauncher> LauncherPtr;

    class DesktopMascot : public QGraphicsView
    {
        Q_OBJECT
    
    private:
        static const int MAX_WINDOW_SIZE_X = 1280;
        static const int MAX_WINDOW_SIZE_Y = 640;

        QGraphicsScene              m_scene;
        QPixmap                     m_flyPixmap;
        QPixmap                     m_standPixmap;
        QGraphicsPixmapItem         m_mascotItem;
        QVector<LauncherPtr>        m_launchers;
        Leap::Controller            m_controller;
        QTimer                      m_timer;
        QLabel                      *m_test;
        void initScene();
        void initLaunchers();
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