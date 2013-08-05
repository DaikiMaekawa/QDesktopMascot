#include <iostream>
#include <QtGui>
#include "DesktopMascot.h"

int main(int argc, char *argv[]){
    
    QApplication a(argc, argv);
    mascot::DesktopMascot w;

    w.show();
    
    return a.exec();
}
