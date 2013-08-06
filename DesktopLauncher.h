#pragma once
#include <QtGui>
#include <QProcess>

namespace mascot{

    class DesktopLauncher : public QGraphicsPixmapItem{
        //Q_OBJECT

    //private slots:
        /*
        void finished(int exitCode, QProcess::ExitStatus exitStatus);
        void error(QProcess::ProcessError error);
        void readyReadStandardOutput();
        void readyReadStandardError();
        */
    private:
        QProcess        m_proc;
        QString         m_program;
        QStringList     m_arg;

    public:
        static const int OBJECT_SIZE_X = 100;
        static const int OBJECT_SIZE_Y = 100;
        explicit DesktopLauncher(const QPixmap &pixmap);
        bool isCrash(QPointF obs);
        void setLaunchProgram(const QString &program, const QStringList &arg);
        void launchProgram();

    };

}; //namespace mascot