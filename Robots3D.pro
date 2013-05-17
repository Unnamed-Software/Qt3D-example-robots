

SOURCES += main.cpp \
    modelnode.cpp \
    worldview.cpp \
    robotmodel.cpp \
    primitiveai.cpp

HEADERS += \
    modelnode.h \
    worldview.h \
    robotmodel.h \
    primitiveai.h

TARGET = Robots3D
CONFIG += qt warn_on qt3d qthread thread
TEMPLATE = app
QT+=opengl declarative
CONFIG += qt3dquick

RESOURCES += \
    resources.qrc

