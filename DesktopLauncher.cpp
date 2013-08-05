#include "DesktopLauncher.h"
#include <iostream>

namespace mascot{

    DesktopLauncher::DesktopLauncher(const QPixmap &pixmap) : 
        QGraphicsPixmapItem(pixmap)
    {

    }

    bool DesktopLauncher::isCrash(QPointF obj){

        if(pos().x() + OBJECT_SIZE_X > obj.x() && pos().x() - OBJECT_SIZE_X < obj.x()){
            if(pos().y() + OBJECT_SIZE_Y > obj.y() && pos().y() - OBJECT_SIZE_Y < obj.y()){
                std::cout << "isCrash: True" << std::endl;
                return true;
            }
        }
        
        
        std::cout << "isCrash: False" << std::endl;
        return false;
        
    }

}; //namespace mascot