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
    MODEL/container.cpp \
    MODEL/database.cpp \
    MODEL/Libro.cpp \
    MODEL/Opera.cpp \
    MODEL/Rivista.cpp \
    VIEW/listaop.cpp \
    Controller/C_listaop.cpp \
    CONTROLLER/c_listaop.cpp \
    VIEW/dettagli_rivista.cpp \
    MODEL/info.cpp \
    VIEW/dettagli_libro.cpp \
    VIEW/mainwindow.cpp \
    CONTROLLER/c_mainwindow.cpp \
    VIEW/inserisci_rivista.cpp \
    CONTROLLER/c_add_rivista.cpp \
    VIEW/inserisci_libro.cpp \
    CONTROLLER/c_add_libro.cpp \
    VIEW/widget_padre.cpp \
    VIEW/dettagli_opera.cpp

HEADERS  += \
    MODEL/container.h \
    MODEL/database.h \
    MODEL/Libro.h \
    MODEL/Opera.h \
    MODEL/Rivista.h \
    VIEW/listaop.h \
    CONTROLLER/c_listaop.h \
    VIEW/dettagli_rivista.h \
    MODEL/info.h \
    VIEW/dettagli_libro.h \
    VIEW/mainwindow.h \
    CONTROLLER/c_mainwindow.h \
    VIEW/inserisci_rivista.h \
    CONTROLLER/c_add_rivista.h \
    VIEW/inserisci_libro.h \
    CONTROLLER/c_add_libro.h \
    VIEW/widget_padre.h \
    VIEW/dettagli_opera.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    DataBase.xml
