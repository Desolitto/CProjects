QT       += core gui opengl openglwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

CONFIG += c++17
DEFINES += GL_SILENCE_DEPRECATION

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Подключение доп библиотеки qgifimage
include(gifimage/qtgifimage.pri)
#include(3rdParty/giflib.pri)

SOURCES += \
    ../../back/my_affine.c \
    ../../back/my_data_functions.c \
    ../../back/my_parser.c \
    main.cpp \
    mainwindow.cpp \
    my_openglwidget.cpp

HEADERS += \
    ../../back/3D_Viewer.h \
    mainwindow.h \
    my_openglwidget.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
