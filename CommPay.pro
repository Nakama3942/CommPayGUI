QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
RC_ICONS = icon.ico
VERSION = 1.0.0.1
QMAKE_TARGET_COMPANY = Kalynovsky Valentin
QMAKE_TARGET_PRODUCT = CommPay
QMAKE_TARGET_DESCRIPTION = Program for calculating communal payments.
QMAKE_TARGET_COPYRIGHT = Copyright (C) 2021 Kalynovsky Valentin. All rights reserved.

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutprogram.cpp \
    abouttheme.cpp \
    history.cpp \
    main.cpp \
    commpay.cpp

HEADERS += \
    aboutprogram.h \
    abouttheme.h \
    commpay.h \
    history.h

FORMS += \
    aboutprogram.ui \
    abouttheme.ui \
    commpay.ui \
    history.ui

TRANSLATIONS += \
    CommPay_ru_UA.ts \
	CommPay_uk_UA.ts \
	CommPay_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Config.ini \
	History.txt \
    LICENSE.txt \
    NOTICE.txt

RESOURCES += \
    breeze.qrc
