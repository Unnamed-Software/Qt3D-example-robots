#include "primitiveai.h"
#include "math.h"
#include "time.h"
#include "robotmodel.h"
PrimitiveAI::PrimitiveAI(QList<modelNode*> *list,QObject *parent) :
    QThread(parent)
{

    this->list = list;

}

void PrimitiveAI::pause()
{
    sync.lock();
    paused = true;
    sync.unlock();
}

void PrimitiveAI::resume()
{
    sync.lock();
    paused = false;
    sync.unlock();
    pauseCond.wakeAll();
}

void PrimitiveAI::run()
{
    srand(time(0));
    paused = false;
    while(1)
    {
        sync.lock();
        if(paused)
           pauseCond.wait(&sync);
        sync.unlock();
        for(int i=0;i<list->length();i++)
        {

            robotModel *rob = (robotModel*)(*list)[i];
            if(!rob->isCurrent())
            emit go(rob->getID(),(rand()%4)+1);

        }

        msleep(200);
    }
}
