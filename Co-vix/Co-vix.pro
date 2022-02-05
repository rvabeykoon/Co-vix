QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutus.cpp \
    addscreen.cpp \
    checkvaccinestatusscreen.cpp \
    checkvaccinestatusscreen2.cpp \
    homescreen.cpp \
    loginscreen.cpp \
    main.cpp \
    mainscreen.cpp \
    updatestatusscreen.cpp \
    viewscreen.cpp

HEADERS += \
    aboutus.h \
    addscreen.h \
    checkvaccinestatusscreen.h \
    checkvaccinestatusscreen2.h \
    homescreen.h \
    loginscreen.h \
    mainscreen.h \
    updatestatusscreen.h \
    viewscreen.h

FORMS += \
    aboutus.ui \
    addscreen.ui \
    checkvaccinestatusscreen.ui \
    checkvaccinestatusscreen2.ui \
    homescreen.ui \
    loginscreen.ui \
    mainscreen.ui \
    updatestatusscreen.ui \
    viewscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
