QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../modules/my_calc.c \
    ../modules/my_finance.c \
    ../modules/my_polish.c \
    ../modules/my_stack.c \
    ../modules/my_valid.c \
    credit.cpp \
    deposit.cpp \
    graphwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../modules/my_calc.h \
    ../modules/my_finance.h \
    ../modules/my_polish.h \
    ../modules/my_stack.h \
    ../modules/my_valid.h \
    ../my_smart_calc.h \
    credit.h \
    deposit.h \
    graphwindow.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    credit.ui \
    deposit.ui \
    graphwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
