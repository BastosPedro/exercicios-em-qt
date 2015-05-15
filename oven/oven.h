#ifndef OVEN_H
#define OVEN_H
#include<QTimer>
//#include<QObject>
#include<QDebug>

//template<class E>
class oven : public QObject
{
    public:
        bool Ready;
        double Progress;
        QTimer * m_timer;

        oven();

        ~oven();

        double getProgress() const;

        void setProgress();

        bool getReady() const;


public slots:
        void stopOven();

        void setReady(bool value);

};

#endif // OVEN_H
