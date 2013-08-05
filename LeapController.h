#pragma once
#include "Leap.h"

namespace Leap{

    class LeapListener : public Listener {
    public:
        virtual void onInit(const Controller&);
        virtual void onConnect(const Controller&);
        virtual void onDisconnect(const Controller&);
        virtual void onExit(const Controller&);
        virtual void onFrame(const Controller&);
    };

    class LeapController{
        Controller m_controller;
        LeapListener m_listener;
    public:
        LeapController();
        ~LeapController();
    };


}; //namespace Leap