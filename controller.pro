#-------------------------------------------------
#
# Project created by QtCreator 2016-02-27T20:10:40
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Controller
TEMPLATE = app

SOURCES += main.cpp\
    control.cpp \

HEADERS  += \
    control.h \
    header.h \

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    resource.qrc

DISTFILES += \
    ReadMe \
    AndroidMinifest.xml \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat
RC_FILE = app.rc

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
