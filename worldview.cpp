#include "worldview.h"
#include <qplane3d.h>
#include <QList>
#include <QFont>

modelNode* worldView::current = NULL;

worldView::worldView(QWidget *parent) :
    QGLView(parent)
{
     ai = new PrimitiveAI(&objects_list);
     connect(this,SIGNAL(destroyed()),ai,SLOT(deleteLater()));
     pick_id=0;
}

void worldView::add_model(modelNode *model)
{
    objects_list.append(model);
}

void worldView::run_primitiveAI()
{
    ai->resume();
}

void worldView::stop_primitiveAI()
{
    ai->pause();
}

void worldView::paintGL(QGLPainter *painter)
{


    world->draw(painter);
    painter->setClearColor(Qt::gray);

    painter->modelViewMatrix().scale(0.2);
    painter->modelViewMatrix().rotate(90,1,0,0);

    for(int i=0; i<objects_list.length();i++)
    {
        objects_list[i]->draw(painter);
        //qDebug()<<objects_list.length();
    }






}

void worldView::initializeGL(QGLPainter *painter)
{
    Q_UNUSED(painter)
    world = QGLAbstractScene::loadScene(":/Images/Plane.3ds")->mainNode();
    camera()->setEye(camera()->eye() + QVector3D(0.0f, 5.0f, 1.0f));
    setOption(QGLView::ObjectPicking,true);

    ai->start();

}

void worldView::keyPressEvent(QKeyEvent *e)
{
    robotModel *current = (robotModel*)this->current;
    if(current != NULL)
    switch(e->key())
    {
        case Qt::Key_Up:
                       current->walk(current->getID(),1);
                       break;
        case Qt::Key_Down:
                       current->walk(current->getID(),2);
                       break;

        case Qt::Key_Right:
                        current->walk(current->getID(),3);
                        break;

        case Qt::Key_Left:
                        current->walk(current->getID(),4);
                        break;

        case Qt::Key_Space:
                        if(ai->paused)
                          run_primitiveAI();
                        else
                           stop_primitiveAI();
                        break;
    }

}

void worldView::mouseDoubleClickEvent(QMouseEvent *e)
{
    //Found code snippet in examples Qt3D
    //TODO: DECODE CODE BELOW
    QVector3D pick = mapPoint(e->pos());
    QRay3D eyeline(camera()->eye(), (camera()->center() - camera()->eye()).normalized());
    QVector3D nearPlaneOrigin = eyeline.point(camera()->nearPlane());


    QRay3D up(nearPlaneOrigin, camera()->upVector());
    QVector3D sideDir = QVector3D::crossProduct(camera()->upVector(), -eyeline.direction());
    QRay3D side(up.point(pick.y()), sideDir.normalized());
    QVector3D v = side.point(pick.x());


    QRay3D ray(camera()->eye(), v - camera()->eye());
    QPlane3D floorPlane(QVector3D(), QVector3D(0, 1, 0));
    QVector3D pointOnFloor = ray.point(floorPlane.intersection(ray));

    robotModel *new_robot = new robotModel;

    //Calibrating
    new_robot->setZ(-8);
    new_robot->setX(pointOnFloor.x()*5);
    new_robot->setY(pointOnFloor.z()*5);

    connect(new_robot,SIGNAL(updated()),this,SLOT(update()));
    connect(ai,SIGNAL(go(int,int)),new_robot,SLOT(walk(int,int)));

    for(int i=0;i<new_robot->picklist.length();i++)
    {
        pick_id++;
        new_robot->picklist[i]->setId(pick_id);
        registerObject(pick_id,new_robot->picklist[i]);

        connect(new_robot->picklist[i],SIGNAL(clicked()),new_robot,SLOT(setCurrent()));
    }

    add_model(new_robot);





}
