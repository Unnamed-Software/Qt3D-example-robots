#ifndef MODELNODE_H
#define MODELNODE_H

#include "qglabstractscene.h"


class modelNode : public QGLSceneNode
{
    Q_OBJECT
public:
    explicit modelNode(QObject *parent = 0);
private:
    float width;
    float height;

signals:
    
public slots:
    
};

#endif // MODELNODE_H
