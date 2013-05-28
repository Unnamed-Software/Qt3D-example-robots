#ifndef MODELNODE_H
#define MODELNODE_H

#include "qglabstractscene.h"


class modelNode : public QGLSceneNode
{
    Q_OBJECT
public:
    explicit modelNode(QWidget *parent = 0);
    //Getters & Setters methods.
    virtual void setWidth(float width);
    virtual void setHeight(float height);
    virtual void setHigh(float high);
    virtual float getWidth();
    virtual float getHeight();
    virtual float getHigh();
    virtual void setID(int id);
    virtual int getID();
private:
    float width;
    float height;
    float high;
    int id;

signals:
    
public slots:
    virtual void walk(int,int) = 0;
    virtual void setCurrent() = 0;
};

#endif // MODELNODE_H
