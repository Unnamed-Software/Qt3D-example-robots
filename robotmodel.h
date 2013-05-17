#ifndef ROBOTMODEL_H
#define ROBOTMODEL_H

#include "modelnode.h"
#include <QParallelAnimationGroup>
#include "qgraphicsrotation3d.h"
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QDebug>
class robotModel : public modelNode
{
public:
    robotModel();


    void walk(int dir);

private:
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

    void add_parts();




};

#endif // ROBOTMODEL_H
