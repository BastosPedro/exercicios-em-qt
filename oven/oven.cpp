#include "oven.h"


double oven::getProgress() const
{
    return Progress;
}

void oven::setProgress()
{
    qDebug() << "Progress agora é: " << Progress;
    Progress += 0.1;
    if((int) Progress == 1) emit this->setReady(true);
}

bool oven::getReady() const
{
    return Ready;
}

void oven::setReady(bool value)
{
    Ready = value;
    if(value == true)emit this->stopOven();
}

void oven::stopOven(){
    QObject::connect(m_timer, &QTimer::timeout, this, &oven::setProgress);
    m_timer->stop();
    qDebug() << "acabou";

}

oven::oven()
{
    Ready = false;
    Progress = 0;
    m_timer = new QTimer();
    QObject::connect(m_timer, &QTimer::timeout, this, &oven::setProgress);
    m_timer->setInterval(1000);
    m_timer->start();
}

oven::~oven()
{

}
