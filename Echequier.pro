TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    echec.cpp \
    joueur.cpp \
    piece.cpp \
    ../prog_cpp/Exercices/Echecs/Cavalier.cxx \
    ../prog_cpp/Exercices/Echecs/Coordonnee.cxx \
    ../prog_cpp/Exercices/Echecs/Fou.cxx \
    ../prog_cpp/Exercices/Echecs/Pion.cxx \
    ../prog_cpp/Exercices/Echecs/Reine.cxx \
    ../prog_cpp/Exercices/Echecs/Roi.cxx \
    ../prog_cpp/Exercices/Echecs/Tour.cxx

HEADERS += \
    echec.h \
    joueur.h \
    piece.h \
    ../prog_cpp/Exercices/Echecs/Cavalier.h \
    ../prog_cpp/Exercices/Echecs/Coordonnee.h \
    ../prog_cpp/Exercices/Echecs/Fou.h \
    ../prog_cpp/Exercices/Echecs/Pion.h \
    ../prog_cpp/Exercices/Echecs/Reine.h \
    ../prog_cpp/Exercices/Echecs/Roi.h \
    ../prog_cpp/Exercices/Echecs/Tour.h
