#include "robotmodel.h"

robotModel::robotModel()
{
    // Load 3D model parts of robot.
    head = QGLAbstractScene::loadScene(":/Images/Head.3ds")->mainNode();
    body = QGLAbstractScene::loadScene(":/Images/Body.3ds")->mainNode();
    left_arm = QGLAbstractScene::loadScene(":/Images/Arm.3ds")->mainNode();
    left_leg = QGLAbstractScene::loadScene(":/Images/Leg.3ds")->mainNode();
    right_arm = QGLAbstractScene::loadScene(":/Images/Arm.3ds")->mainNode()->clone();
    right_leg = QGLAbstractScene::loadScene(":/Images/Leg.3ds")->mainNode()->clone();

    add_parts();
}

void robotModel::add_parts()
{
    // We don't want to see robot without leg or arm. =)
    if(head != NULL && body != NULL && left_arm != NULL && left_leg != NULL && right_arm != NULL && right_leg != NULL)
    {
        // Small customization.
        addNode(head);

        body->setPosition(QVector3D(0,0,3.2f));
        addNode(body);

        left_arm->setPosition(QVector3D(-2.2f,0,2));
        addNode(left_arm);

        left_leg->setPosition(QVector3D(1,0,5));
        addNode(left_leg);

        right_arm->setPosition(QVector3D(2.2f,0,2));
        addNode(right_arm);

        right_leg->setPosition(QVector3D(-1,0,5));
        addNode(right_leg);
    }
}
