QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cnlhelper.cpp \
    main.cpp \
    mainwindow.cpp \
    settingwindow.cpp \
    taskdailog.cpp \
    util.cpp

HEADERS += \
    cnlhelper.h \
    mainwindow.h \
    model.h \
    settingwindow.h \
    taskdailog.h \
    util.h

FORMS += \
    mainwindow.ui \
    settingwindow.ui \
    taskdailog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Pinyin.qrc \
    icon.qrc


INCLUDEPATH += $$PWD/../../../vcpkg/installed/x64-windows/include
DEPENDPATH += $$PWD/../../../vcpkg/installed/x64-windows/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../vcpkg/installed/x64-windows/lib/ -lcpr
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../vcpkg/installed/x64-windows/debug/lib -lcpr


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../vcpkg/installed/x64-windows/lib/ -llibcurl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../vcpkg/installed/x64-windows/debug/lib/ -llibcurl-d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../vcpkg/installed/x64-windows/lib/ -lfmt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../vcpkg/installed/x64-windows/debug/lib/ -lfmtd
