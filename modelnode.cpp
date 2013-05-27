#include "modelnode.h"

modelNode::modelNode(QWidget *parent) :
    QGLSceneNode(parent)
{
}

void modelNode::setWidth(float width)
{
    this->width = width;
}

void modelNode::setHeight(float height)
{
    this->height = height;
}

void modelNode::setHigh(float high)
{
    this->high = high;
}

float modelNode::getWidth()
{
    return width;
}

float modelNode::getHeight()
{
    return height;
}

float modelNode::getHigh()
{
    return high;
}
