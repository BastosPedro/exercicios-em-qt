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
    setActorA(false);
    setActorB(false);
    setActorC(true);
    m_timer->setInterval(500);
    qDebug() << "(5seg) fechando A, abrindo B, fechando C";
}

void controlador::setProgress()
{
    //qDebug() << "aumentou +1";
    progress += 1;
    if((int) progress == 1) emit this->plasticReady(true);
    if((int) progress == 2){
        m_timer->setInterval(4000);
        setActorB(true);
        qDebug() << "(0.5seg)fechando B";
    }
    if(progress == 3) emit this->stopAll();
}


void controlador::stopAll(){
    qDebug() << "(4seg)abrindo C, soltando garrafa";
    m_timer->stop();
    //actorA = false;
    //actorB = true;
    actorC = false;

}


controlador::controlador()
{
    actorA = actorB = true;
    actorC = false;
    progress = 0;
    m_timer = new QTimer();
    qDebug() << "(0seg)abrindo A, B fechado, e C aberto";
    QObject::connect(m_timer, &QTimer::timeout, this, &controlador::setProgress);
    m_timer->setInterval(5000);
    m_timer->start();

}

