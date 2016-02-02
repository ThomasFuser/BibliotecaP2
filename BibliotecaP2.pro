#-------------------------------------------------
#
# Project created by QtCreator 2016-02-02T10:01:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BibliotecaP2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MODEL/container.cpp \
    MODEL/database.cpp \
    MODEL/Libro.cpp \
    MODEL/Opera.cpp \
    MODEL/Rivista.cpp \
    VIEW/listaop.cpp \
    Controller/C_listaop.cpp

HEADERS  += mainwindow.h \
    MODEL/container.h \
    MODEL/database.h \
    MODEL/Libro.h \
    MODEL/Opera.h \
    MODEL/Rivista.h \
    VIEW/listaop.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    DataBase.xml
