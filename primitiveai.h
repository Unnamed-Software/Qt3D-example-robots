#ifndef PRIMITIVEAI_H
#define PRIMITIVEAI_H

#include <QThread>
#include "modelnode.h"
#include  <QListIterator>
class PrimitiveAI : public QThread
{
    Q_OBJECT
public:
    explicit PrimitiveAI(QList<modelNode *> *list, QObject *parent = 0);

protected:
    void run();
    
signals:
    void go(int);
private:
    QList<modelNode*> *list;

    
public slots:
    
};

#endif // PRIMITIVEAI_H
