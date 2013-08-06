#include "DesktopMascot.h"
#include <iostream>
#include <fstream>

namespace mascot{
    
    static const char * const READ_FILE = "ProgramList.txt";

    DesktopMascot::DesktopMascot(QWidget *parent) : 
        QGraphicsView(parent),
        m_flyPixmap(QPixmap("fly.png").scaled(200, 200, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)),
        m_standPixmap(QPixmap("stand.png").scaled(200, 200, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)),
        m_mascotItem(m_standPixmap)
    {
        initScene();
        connectSignals();
        setStyleSheet("background:transparent; border: none;");
        setAttribute(Qt::WA_TranslucentBackground);
        setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
        resize(MAX_WINDOW_SIZE_X, MAX_WINDOW_SIZE_Y);
        
        m_test = new QLabel(this);
        m_test->setText("test");
        m_test->show();

        m_timer.start(100);
    }

    void DesktopMascot::connectSignals(){
        connect(&m_timer, SIGNAL(timeout()), this, SLOT(updateStatus()));
    }

    void DesktopMascot::initLaunchers(){
        std::ifstream ifs(mascot::READ_FILE);
        while(!ifs.eof()){
            std::string program, arg;

            ifs >> program >> arg;
            if(!program.empty()){
                LauncherPtr launcher(new DesktopLauncher(QPixmap("block.png").scaled(100, 100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
                launcher->setLaunchProgram(program.c_str(), QStringList(arg.c_str()));
                m_launchers << launcher;
            }
        }
    }

    void DesktopMascot::initScene(){
        initLaunchers();

        QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
        effect->setColor(QColor(0,0,0));
        effect->setOffset(5, 5);
        effect->setBlurRadius(20);
        m_mascotItem.setGraphicsEffect(effect);

        setScene(&m_scene);
        m_scene.addItem(&m_mascotItem);
        for(int i=0; i < m_launchers.size(); i++){
            m_scene.addItem(m_launchers[i].get());
            m_launchers[i]->setPos(QPointF(0, 150 * (i+1)));
        }
        
        m_scene.setSceneRect(0, 0, MAX_WINDOW_SIZE_X, MAX_WINDOW_SIZE_Y);
        setPos(QPointF(1000, 0));
    }

    void DesktopMascot::setPos(QPointF pos){
        const float limitx = std::max<float>(std::min<float>(pos.x(), MAX_WINDOW_SIZE_X - 200), 0);
        const float limity = std::max<float>(std::min<float>(pos.y(), MAX_WINDOW_SIZE_Y - 200), 0);

        m_mascotItem.setPos(QPointF(limitx, limity));
    }

    QPointF DesktopMascot::pos(){
        return m_mascotItem.pos();
    }

    void DesktopMascot::updateStatus(){
        for(int i=0; i < m_launchers.size(); i++){
            if(m_launchers[i]->isCrash(pos())){
                if(m_launchers[i]->isVisible()){
                    m_launchers[i]->setVisible(false);
                    m_launchers[i]->launchProgram();
                    setPos(QPointF(1000, 0));
                }
            }else{
                m_launchers[i]->setVisible(true);
            }
        }

        const Leap::Frame frame = m_controller.frame();
        std::cout   << "Frame id: "     << frame.id()
                    << ", timestamp: "  << frame.timestamp()
                    << ", hands: "      << frame.hands().count()
                    << ", fingers: "    << frame.fingers().count()
                    << ", tools: "      << frame.tools().count() << std::endl;

        if(!frame.hands().empty()) {
            
            // Get the first hand
            const Leap::Hand hand = frame.hands()[0];

            // Check if the hand has any fingers
            const Leap::FingerList fingers = hand.fingers();
            if (!fingers.empty()) {
                // Calculate the hand's average finger tip position
                Leap::Vector avgPos;
                for (int i = 0; i < fingers.count(); ++i){
                    avgPos += fingers[i].tipPosition();
                }
                
                avgPos /= (float)fingers.count();
                std::cout << "Hand has " << fingers.count()
                          << " fingers, average finger tip position" << avgPos << std::endl;
            
            if(fingers.count() > 1){
                    m_mascotItem.setPixmap(m_flyPixmap);

                    // Get the hand's sphere radius and palm position
                    std::cout << "Hand sphere radius: " << hand.sphereRadius()
                              << " mm, palm position: " << hand.palmPosition() << std::endl;

                    // Get the hand's normal vector and direction
                    const Leap::Vector normal = hand.palmNormal();
                    const Leap::Vector direction = hand.direction();

                    // Calculate the hand's pitch, roll, and yaw angles
                    std::cout << "Hand pitch: " << direction.pitch() * Leap::RAD_TO_DEG << " degrees, "
                              << "roll: "       << normal.roll()     * Leap::RAD_TO_DEG << " degrees, "
                              << "yaw: "        << direction.yaw()   * Leap::RAD_TO_DEG << " degrees"   << std::endl << std::endl;
                    
                    setPos(pos() + QPointF(normal.roll() * -50.f, direction.pitch() * -50.f));
                }
            }
        }else{
            m_mascotItem.setPixmap(m_standPixmap);
        }
    }

}; //namespace mascot
