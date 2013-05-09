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

}

void worldView::initializeGL(QGLPainter *painter)
{
    Q_UNUSED(painter)
    world = QGLAbstractScene::loadScene(":/Images/Plane.3ds")->mainNode();
    camera()->setEye(camera()->eye() + QVector3D(0.0f, 5.0f, 1.0f));
    setOption(QGLView::ObjectPicking,true);

}
