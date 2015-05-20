#include "controlador.h"


bool controlador::getActorA() const
{
    return actorA;
}

void controlador::setActorA(bool value)
{
    actorA = value;
}

bool controlador::getActorB() const
{
    return actorB;
}

void controlador::setActorB(bool value)
{
    actorB = value;
}

bool controlador::getActorC() const
{
    return actorC;
}

void controlador::setActorC(bool value)
{
    actorC = value;
}

void controlador::plasticReady(bool ready)
{
    //m_timer->stop();
    setActorA(true);
    setActorC(true);
    qDebug() << "abrindo A e fechando C";
}

void controlador::setProgress()
{
    qDebug() << "aumentou +1";
    progress += 1;
    if((int) progress == 5) emit this->plasticReady(true);
    if((int) progress == 9){
        m_timer->setInterval(100);
        setActorB(false);
        qDebug() << "abrindo B";
    }
    if(progress == 14) emit this->stopAll();
}


void controlador::stopAll(){
    qDebug() << "amem acabou";
    m_timer->stop();
    actorA = false;
    actorB = true;
    actorC = false;

}


controlador::controlador()
{
    actorA = actorC = false;
    actorB = true;
    progress = 0;
    m_timer = new QTimer();
    QObject::connect(m_timer, &QTimer::timeout, this, &controlador::setProgress);
    m_timer->setInterval(1000);
    m_timer->start();

}

