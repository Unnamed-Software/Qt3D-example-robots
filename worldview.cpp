#include "worldview.h"

worldView::worldView(QWidget *parent) :
    QGLView(parent)
{
}

void worldView::add_model(modelNode *model)
{
    objects_list.append(model);
}

void worldView::paintGL(QGLPainter *painter)
{


    world->draw(painter);
    painter->setClearColor(Qt::gray);

    painter->modelViewMatrix().scale(0.2);
    painter->modelViewMatrix().rotate(90,1,0,0);

    objects_list[0]->draw(painter);

}

void worldView::initializeGL(QGLPainter *painter)
{
    Q_UNUSED(painter)
    world = QGLAbstractScene::loadScene(":/Images/Plane.3ds")->mainNode();
    camera()->setEye(camera()->eye() + QVector3D(0.0f, 5.0f, 1.0f));
    setOption(QGLView::ObjectPicking,true);

    robotModel *node = new robotModel;

    node->setPosition(QVector3D(10,10,-8));



    connect(node,SIGNAL(updated()),this,SLOT(update()));

    add_model(node);

}

void worldView::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Up)
    {

    }
    if(e->key() == Qt::Key_Down)
    {

    }
    if(e->key() == Qt::Key_Right)
    {


    }
    if(e->key() == Qt::Key_Left)
    {

    }
}
