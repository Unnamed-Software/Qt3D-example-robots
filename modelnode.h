#ifndef MODELNODE_H
#define MODELNODE_H

#include "qglabstractscene.h"


class modelNode : public QGLSceneNode
{
    Q_OBJECT
public:
    explicit modelNode(QWidget *parent = 0);
    //Getters & Setters methods.
    void setWidth(float *width)=0;
    void setHeight(float *height)=0;
    void setHigh(float *heigh)=0;
    float getWidth()=0;
    float getHeight()=0;
    float getHigh()=0;
private:
    float width;
    float height;
    float high;

signals:
    
public slots:
    
};

#endif // MODELNODE_H
