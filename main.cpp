#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    qDebug()<<"HELLO World"; //TESTrere

    return a.exec();
}
