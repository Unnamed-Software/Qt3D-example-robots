#ifndef PRIMITIVEAI_H
#define PRIMITIVEAI_H

#include <QThread>
#include "modelnode.h"
#include  <QListIterator>
#include <QMutex>
#include <QWaitCondition>
class PrimitiveAI : public QThread
{
    Q_OBJECT
public:
    explicit PrimitiveAI(QList<modelNode *> *list, QObject *parent = 0);
    void pause();
    void resume();
    bool paused;

protected:
    void run();
    
signals:
    void go(int id,int sig);
private:
    QMutex sync;
    QWaitCondition pauseCond;

    QList<modelNode*> *list;


    
public slots:

    
};

#endif // PRIMITIVEAI_H
