#include <QApplication>
#include "worldview.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    worldView world;

    world.showMaximized();

    return a.exec();
}
