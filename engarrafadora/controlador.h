#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include<QTimer>
#include<QDebug>


class controlador: public QObject
{
    bool actorA, actorB, actorC;
    double progress;
    QTimer* m_timer;

public:
    controlador();

    bool getActorA() const;
    void setActorA(bool value);

    bool getActorB() const;
    void setActorB(bool value);

    bool getActorC() const;
    void setActorC(bool value);

    void setProgress();

public slots:
    void plasticReady(bool ready);
    void timewarp();
    void stopAll();
};

#endif // CONTROLADOR_H
