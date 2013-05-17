#include "primitiveai.h"
#include "math.h"
#include "time.h"
#include "robotmodel.h"
PrimitiveAI::PrimitiveAI(QList<modelNode*> *list,QObject *parent) :
    QThread(parent)
{

    this->list = list;

}

void PrimitiveAI::run()
{
    srand(time(0));
    while(1)
    {
        for(int i=0;i<list->length();i++)
        {

            //robotModel *rob = (robotModel*)(*list)[i];
            emit go(rand()%4);

        }

        msleep(300);
    }
}
