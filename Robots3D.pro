
TARGET = Robots3D
CONFIG += qt warn_on qt3d qthread thread
TEMPLATE = app
QT+=opengl declarative
CONFIG += qt3dquick



SOURCES += main.cpp \
    modelnode.cpp

HEADERS += \
    modelnode.h
