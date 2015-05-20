#include "controlador.h"


Controlador::Controlador(QObject * parent): QObject(parent)
{
    quantity = 0;
    actorA = actorC = false;
    actorB = true;
    progress = 0;
}

Controlador::~Controlador()
{

}

bool Controlador::getActorA() const
{
    return actorA;
}

void Controlador::setActorA(bool value)
{
    if(actorA != value) {
        actorA = value;
        qDebug() << Q_FUNC_INFO << "ActorA == " << value;
        emit this->actorAChanged(value);
    }
}

bool Controlador::getActorB() const
{
    return actorB;
}

void Controlador::setActorB(bool value)
{
    if(actorB != value) {
        actorB = value;
        qDebug() << Q_FUNC_INFO << "ActorB == " << value;
        emit this->actorBChanged(value);
    }
}

bool Controlador::getActorC() const
{
    return actorC;
}

void Controlador::setActorC(bool value)
{
    if(actorC != value) {
        actorC = value;
        qDebug() << Q_FUNC_INFO << "ActorC == " << value;
        emit this->actorCChanged(value);
    }
}

void Controlador::plasticReady(bool ready)
{
    if(ready){
        m_timer = new QTimer();
        setActorA(true);
        QObject::connect(m_timer, &QTimer::timeout, this, &Controlador::setProgress);
        m_timer->setInterval(5000);
        m_timer->start();
    }
}

void Controlador::setProgress()
{
    if(progress == 0)qDebug() << "~ (0seg)abrindo A, B fechado, e C aberto ~";
    progress++;
    if(progress == 1){
        setActorA(false);
        setActorB(false);
        setActorC(true);
        m_timer->setInterval(500);
        qDebug() << "~ (+5seg) fechando A, abrindo B, fechando C ~";
    }
    if(progress == 2){
        m_timer->setInterval(4000);
        setActorB(true);
        qDebug() << "~ (+0.5seg)fechando B ~";
    }
    if(progress == 3) emit this->stopAll();
}


void Controlador::stopAll(){
    quantity++;
    setActorC(false);
    qDebug() << "~ (+4seg)abrindo C, soltando garrafa ~";
    qDebug() << "num. de garrafas:" << quantity;
    m_timer->setInterval(5000);
    progress = 0;
    actorC = false;

}



