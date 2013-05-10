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


    QPropertyAnimation* turnAnimation(int speed, int degree);
private:
    // Robot parts.
    QGLSceneNode *head;
    QGLSceneNode *body;
    QGLSceneNode *left_arm;
    QGLSceneNode *right_arm;
    QGLSceneNode *left_leg;
    QGLSceneNode *right_leg;

    // Parts rotations.
    QGraphicsRotation3D *direction;

    QGraphicsRotation3D *rotationLA;
    QGraphicsRotation3D *rotationRA;
    QGraphicsRotation3D *rotationLL;
    QGraphicsRotation3D *rotationRL;

    void add_parts();

    // Walking animation.

    QParallelAnimationGroup *walk;

    QParallelAnimationGroup *walk_down;
    QParallelAnimationGroup *walk_up;
    QParallelAnimationGroup *walk_right;
    QParallelAnimationGroup *walk_left;


    // Helper functions to initialize walk animation direction.
    QParallelAnimationGroup* walkAnimation(int speed);

    QPropertyAnimation* moveAnimation(int speed, const QByteArray &propertyname, int step);



    void initMoveWalkAnimation(int speed);





};

#endif // ROBOTMODEL_H
