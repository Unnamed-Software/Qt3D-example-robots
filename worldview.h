#ifndef WORLDVIEW_H
#define WORLDVIEW_H

#include "qglview.h"
#include "qglpainter.h"
#include "qglabstractscene.h"
#include "modelnode.h"
#include "robotmodel.h"
#include <QKeyEvent>
#include "primitiveai.h"

class worldView : public QGLView
{
    Q_OBJECT
public:
    explicit worldView(QWidget *parent = 0);
    void add_model(modelNode *model);
    static modelNode *current;


private:
    QGLSceneNode *world;
    QList<modelNode*> objects_list;
    void run_primitiveAI();
    void stop_primitiveAI();
    PrimitiveAI *ai;
    int pick_id;


protected:
    void paintGL(QGLPainter *painter);
    void initializeGL(QGLPainter *painter);
    void keyPressEvent(QKeyEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
signals:
    
public slots:
     bool detectCollision(modelNode *sender);

    
};

#endif // WORLDVIEW_H
