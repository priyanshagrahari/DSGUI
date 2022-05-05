QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutwindow.cpp \
    arraywindow.cpp \
    binarysearchtreewindow.cpp \
    binarytreewindow.cpp \
    hashtablewindow.cpp \
    heapwindow.cpp \
    linkedlistwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    node.cpp \
    queuewindow.cpp \
    stackwindow.cpp \
    binarysearchtree.cpp \
    heap.cpp

HEADERS += \
    aboutwindow.h \
    arraywindow.h \
    binarysearchtreewindow.h \
    binarytreewindow.h \
    hashtablewindow.h \
    heapwindow.h \
    linkedlistwindow.h \
    mainwindow.h \
    node.h \
    queuewindow.h \
    stackwindow.h \
    binarysearchtree.h \
    heap.h

FORMS += \
    aboutwindow.ui \
    arraywindow.ui \
    binarysearchtreewindow.ui \
    binarytreewindow.ui \
    hashtablewindow.ui \
    heapwindow.ui \
    linkedlistwindow.ui \
    mainwindow.ui \
    queuewindow.ui \
    stackwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
