#ifndef MODELNODE_H
#define MODELNODE_H

#include "qglabstractscene.h"


class modelNode : public QGLSceneNode
{
    Q_OBJECT
public:
    explicit modelNode(QWidget *parent = 0);
    //Getters & Setters methods.
//    virtual void setWidth(float *width)=0;
//    virtual void setHeight(float *height)=0;
//    virtual void setHigh(float *heigh)=0;
//    virtual float getWidth()=0;
//    virtual float getHeight()=0;
//    virtual float getHigh()=0;
private:
    float width;
    float height;
    float high;

signals:
    
public slots:
    virtual void walk(int,int) = 0;
};

#endif // MODELNODE_H
