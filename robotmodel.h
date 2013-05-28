#ifndef ROBOTMODEL_H
#define ROBOTMODEL_H

#include "modelnode.h"
#include <QParallelAnimationGroup>
#include "qgraphicsrotation3d.h"
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QDebug>
#include <qglpicknode.h>
#include "worldview.h"
class robotModel : public modelNode
{
public:
    robotModel();
    int getID();
    //Pick nodes
    QList<QGLPickNode*> picklist;
    //Select
    QGLSceneNode *star;

    bool isCurrent();





public slots:
    void walk(int id , int dir);

    //Set current robot.
    void setCurrent();


private:
    //ID
    void setID(int id);
    static int count;
    int id;

    //Robot parts.
    QGLSceneNode *head;
    QGLSceneNode *body;
    QGLSceneNode *left_arm;
    QGLSceneNode *right_arm;
    QGLSceneNode *left_leg;
    QGLSceneNode *right_leg;


    //Parts rotations.
    QGraphicsRotation3D *direction;
    QGraphicsRotation3D *rotationLA;
    QGraphicsRotation3D *rotationRA;
    QGraphicsRotation3D *rotationLL;
    QGraphicsRotation3D *rotationRL;

    //Move animation.
    QPropertyAnimation *move_up;
    QPropertyAnimation *move_down;
    QPropertyAnimation *move_left;
    QPropertyAnimation *move_right;

    //Turn animation.
    QPropertyAnimation *turnTo_up;
    QPropertyAnimation *turnTo_down;
    QPropertyAnimation *turnTo_left;
    QPropertyAnimation *turnTo_right;

    //Walking animation.
    QSequentialAnimationGroup *walk_down;
    QSequentialAnimationGroup *walk_up;
    QSequentialAnimationGroup *walk_right;
    QSequentialAnimationGroup *walk_left;
    QSequentialAnimationGroup *walking;

    //Helper functions to initialize walk animation direction.
    QParallelAnimationGroup* walkAnimation(int speed);
    void SetUpAnimation(int speed);

    //INIT
    void add_parts();


signals:

    void check_me( modelNode *me);






};

#endif // ROBOTMODEL_H
