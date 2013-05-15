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
        // Small customizations.
        addNode(head);


        body->setPosition(QVector3D(0,0,3.2f));
        addNode(body);

        rotationLA = new QGraphicsRotation3D();
        rotationLA->setAxis(QVector3D(1,0,0));
        left_arm->addTransform(rotationLA);
        left_arm->setPosition(QVector3D(-2.2f,0,2));
        addNode(left_arm);

        rotationLL = new QGraphicsRotation3D();
        rotationLL->setAxis(QVector3D(1,0,0));
        left_leg->addTransform(rotationLL);
        left_leg->setPosition(QVector3D(1,0,5));
        addNode(left_leg);


        rotationRA = new QGraphicsRotation3D();
        rotationRA->setAxis(QVector3D(1,0,0));
        right_arm->addTransform(rotationRA);
        right_arm->setPosition(QVector3D(2.2f,0,2));
        addNode(right_arm);

        rotationRL = new QGraphicsRotation3D();
        rotationRL->setAxis(QVector3D(1,0,0));
        right_leg->addTransform(rotationRL);
        right_leg->setPosition(QVector3D(-1,0,5));
        addNode(right_leg);

        direction = new QGraphicsRotation3D();
        direction->setAxis(QVector3D(0,0,1));
        addTransform(direction);

        SetUpAnimation(200);

    }
}


// We need to manualy set degrees of deviation leg and arm.
QParallelAnimationGroup *robotModel::walkAnimation(int speed)
{
    QParallelAnimationGroup *syncWalk = new QParallelAnimationGroup(); // syncWalk variable is created, to synchronize legs and arms animations.

    ///RIGHT LEG

     rotationRL->setAngle(0.0f);
    QSequentialAnimationGroup *seq2 = new QSequentialAnimationGroup();  // Right leg deviation changes from 0->-30->30->0 degree.

    QPropertyAnimation *anim1 = new QPropertyAnimation(rotationRL,"angle");
    anim1->setStartValue(0.0f);
    anim1->setEndValue(-30.0f);

    anim1->setDuration(speed/4);
    seq2->addAnimation(anim1);


    anim1 = new QPropertyAnimation(rotationRL,"angle");
    anim1->setStartValue(-30.0f);
    anim1->setEndValue(30.0f);
    anim1->setDuration(2*(speed/4));

    seq2->addAnimation(anim1);

    anim1 = new QPropertyAnimation(rotationRL,"angle");
    anim1->setStartValue(30.0f);
    anim1->setEndValue(0.0f);
    anim1->setDuration(speed/4);
    seq2->addAnimation(anim1);

    syncWalk->addAnimation(seq2);

    ///LEFT LEG

    rotationLL->setAngle(0.0f);
    QSequentialAnimationGroup *seq = new QSequentialAnimationGroup(); // Left leg deviation changes from 0->30->-30->0 degree.

    QPropertyAnimation *anim2 = new QPropertyAnimation(rotationLL,"angle");
    anim2->setStartValue(0.0f);
    anim2->setEndValue(30.0f);

    anim2->setDuration(speed/4);
    seq->addAnimation(anim2);


    anim2 = new QPropertyAnimation(rotationLL,"angle");
    anim2->setStartValue(30.0f);
    anim2->setEndValue(-30.0f);
    anim2->setDuration(2*(speed/4));

    seq->addAnimation(anim2);

    anim2 = new QPropertyAnimation(rotationLL,"angle");
    anim2->setStartValue(-30.0f);
    anim2->setEndValue(0.0f);
    anim2->setDuration(speed/4);
    seq->addAnimation(anim2);

    syncWalk->addAnimation(seq);
    ///RIGHT ARM
    QSequentialAnimationGroup *seq_arm = new QSequentialAnimationGroup(); // Right arm deviation changes from 0->15->-15->0 degree.

    QPropertyAnimation *aniarm = new QPropertyAnimation(rotationLA,"angle");
    aniarm->setStartValue(0.0f);
    aniarm->setEndValue(15.0f);
    aniarm->setDuration(speed/4);

    seq_arm->addAnimation(aniarm);

    aniarm = new QPropertyAnimation(rotationLA,"angle");
    aniarm->setStartValue(15.0f);
    aniarm->setEndValue(-15.0f);
    aniarm->setDuration(2*(speed/4));

    seq_arm->addAnimation(aniarm);

    aniarm = new QPropertyAnimation(rotationLA,"angle");
    aniarm->setStartValue(-15.0f);
    aniarm->setEndValue(0.0f);
    aniarm->setDuration(speed/4);

    seq_arm->addAnimation(aniarm);

    syncWalk->addAnimation(seq_arm);

    ///LEFT ARM

    QSequentialAnimationGroup *seq_arm1 = new QSequentialAnimationGroup(); // Left arm deviation changes from 0->-15->15->0 degree.

    QPropertyAnimation *aniarm1 = new QPropertyAnimation(rotationRA,"angle");
    aniarm1->setStartValue(0.0f);
    aniarm1->setEndValue(-15.0f);
    aniarm1->setDuration(speed/4);

    seq_arm1->addAnimation(aniarm1);

    aniarm1 = new QPropertyAnimation(rotationRA,"angle");
    aniarm1->setStartValue(-15.0f);
    aniarm1->setEndValue(15.0f);
    aniarm1->setDuration(2*(speed/4));

    seq_arm1->addAnimation(aniarm1);

    aniarm1 = new QPropertyAnimation(rotationRA,"angle");
    aniarm1->setStartValue(15.0f);
    aniarm1->setEndValue(0.0f);
    aniarm1->setDuration(speed/4);

    seq_arm1->addAnimation(aniarm1);

    syncWalk->addAnimation(seq_arm1);



    return syncWalk; // Completed 4 synchronized animations of right arm, left arm, left leg , right arm.
}



void robotModel::walk(int dir)
{
    if(walking->state() == QAbstractAnimation::Stopped)
    switch(dir)
    {
        case 1:{
                turnTo_up->setStartValue(direction->angle()); //
                turnTo_up->setEndValue(180);                  //
                move_up->setStartValue(this->y());            // updating values
                move_up->setEndValue(this->y()-1);            //
                walking = walk_up;                            //
                walking->start();

            break;
        }
        case 2:{
                turnTo_down->setStartValue(direction->angle());
                turnTo_down->setEndValue(0);
                move_down->setStartValue(this->y());
                move_down->setEndValue(this->y()+1);
                walking = walk_down;
                walking->start();
            break;
        }
        case 3:{
                turnTo_left->setStartValue(direction->angle());
                turnTo_left->setEndValue(270);
                move_left->setStartValue(this->x());
                move_left->setEndValue(this->x()+1);
                walking = walk_left;
                walking->start();
            break;
        }
    case 4:{
                turnTo_right->setStartValue(direction->angle());
                turnTo_right->setEndValue(90);
                move_right->setStartValue(this->x());
                move_right->setEndValue(this->x()-1);
                walking = walk_right;
                walking->start();
            break;
        }
    }
}



void robotModel::SetUpAnimation(int speed)
{
    QParallelAnimationGroup *sync = new QParallelAnimationGroup();

    //up
    walk_up = new QSequentialAnimationGroup;
    turnTo_up = new QPropertyAnimation(direction,"angle");
    turnTo_up->setDuration(speed/2);
    walk_up->addAnimation(turnTo_up);
    sync->addAnimation(walkAnimation(speed));
    move_up = new QPropertyAnimation(this,"y");
    move_up->setDuration(speed);
    sync->addAnimation(move_up);
    walk_up->addAnimation(sync);

    //down
    sync = new QParallelAnimationGroup();

    walk_down = new QSequentialAnimationGroup;
    turnTo_down = new QPropertyAnimation(direction,"angle");
    turnTo_down->setDuration(speed/2);
    walk_down->addAnimation(turnTo_down);
    sync->addAnimation(walkAnimation(speed));
    move_down = new QPropertyAnimation(this,"y");
    move_down->setDuration(speed);
    sync->addAnimation(move_down);
    walk_down->addAnimation(sync);

    //left
    sync = new QParallelAnimationGroup();

    walk_left = new QSequentialAnimationGroup;
    turnTo_left = new QPropertyAnimation(direction,"angle");
    turnTo_left->setDuration(speed/2);
    walk_left->addAnimation(turnTo_left);
    sync->addAnimation(walkAnimation(speed));
    move_left = new QPropertyAnimation(this,"x");
    move_left->setDuration(speed);
    sync->addAnimation(move_left);
    walk_left->addAnimation(sync);

    //right
    sync = new QParallelAnimationGroup();

    walk_right = new QSequentialAnimationGroup;
    turnTo_right = new QPropertyAnimation(direction,"angle");
    turnTo_right->setDuration(speed/2);
    walk_right->addAnimation(turnTo_right);
    sync->addAnimation(walkAnimation(speed));
    move_right = new QPropertyAnimation(this,"x");
    move_right->setDuration(speed);
    sync->addAnimation(move_right);
    walk_right->addAnimation(sync);

    walking = walk_down;
}
