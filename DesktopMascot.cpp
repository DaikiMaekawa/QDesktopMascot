#include "DesktopMascot.h"
#include <iostream>

namespace mascot{

    DesktopMascot::DesktopMascot(QWidget *parent) :
        QGraphicsView(parent),
        m_centerPixmap(QPixmap("center.png").scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation))
    {
        setScene(&m_scene);
        initScene();
        
        setStyleSheet("background:transparent; border: none;");
        setAttribute(Qt::WA_TranslucentBackground);
        setWindowFlags(Qt::FramelessWindowHint);
        resize(1280, 640);
        
    }

    void DesktopMascot::initScene(){
        
        QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
        effect->setColor(QColor(0,0,0));
        effect->setOffset(5, 5);
        effect->setBlurRadius(20);
        m_centerPixmap.setGraphicsEffect(effect);
        m_scene.addItem(&m_centerPixmap);
        m_scene.setSceneRect(0, 0, 1280, 640);
        m_centerPixmap.setPos(0, 0);
    }

}; //namespace mascot
