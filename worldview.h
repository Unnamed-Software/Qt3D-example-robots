#ifndef WORLDVIEW_H
#define WORLDVIEW_H

#include "qglview.h"
#include "qglpainter.h"
#include "qglabstractscene.h"
#include "modelnode.h"
#include "robotmodel.h"
#include <QKeyEvent>

class worldView : public QGLView
{
    Q_OBJECT
public:
    explicit worldView(QWidget *parent = 0);
    void add_model(modelNode *model);

private:
    QGLSceneNode *world;
    QList<modelNode*> objects_list;


protected:
    void paintGL(QGLPainter *painter);
    void initializeGL(QGLPainter *painter);
    void keyPressEvent(QKeyEvent *e);
signals:
    
public slots:
    
};

#endif // WORLDVIEW_H
