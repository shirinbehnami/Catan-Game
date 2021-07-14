QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cards.cpp \
    developmentcard.cpp \
    hexagonal.cpp \
    knightcard.cpp \
    main.cpp \
    ground.cpp \
    node.cpp \
    roadconstructioncard.cpp \
    sourcecard.cpp \
    specialscorecard.cpp \
    yearofpenaltycard.cpp

HEADERS += \
    cards.h \
    developmentcard.h \
    ground.h \
    hexagonal.h \
    knightcard.h \
    node.h \
    roadconstructioncard.h \
    sourcecard.h \
    specialscorecard.h \
    yearofpenaltycard.h

FORMS += \
    ground.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gr.qrc

