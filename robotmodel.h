#ifndef ROBOTMODEL_H
#define ROBOTMODEL_H

#include "modelnode.h"

class robotModel : public modelNode
{
public:
    robotModel();

private:
    // Robot parts.
    QGLSceneNode *head;
    QGLSceneNode *body;
    QGLSceneNode *left_arm;
    QGLSceneNode *right_arm;
    QGLSceneNode *left_leg;
    QGLSceneNode *right_leg;

    void add_parts();

};

#endif // ROBOTMODEL_H
