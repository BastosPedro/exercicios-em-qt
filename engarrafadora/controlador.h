#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include<QTimer>
#include<QDebug>


class Controlador: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool actorA READ getActorA WRITE setActorA NOTIFY actorAChanged)
    Q_PROPERTY(bool actorB READ getActorB WRITE setActorB NOTIFY actorBChanged)
    Q_PROPERTY(bool actorC READ getActorC WRITE setActorC NOTIFY actorCChanged)
public:
    Controlador(QObject * parent = 0);
    ~Controlador();

    bool getActorA() const;
    void setActorA(bool value);

    bool getActorB() const;
    void setActorB(bool value);

    bool getActorC() const;
    void setActorC(bool value);

signals:
    void actorAChanged(bool actorA);
    void actorBChanged(bool actorB);
    void actorCChanged(bool actorC);

public slots:
    void plasticReady(bool ready);
    void setProgress();
    //void timewarp();
    void stopAll();

private:
    int quantity, progress;
    bool actorA, actorB, actorC;
    QTimer* m_timer;
};

#endif // CONTROLADOR_H
