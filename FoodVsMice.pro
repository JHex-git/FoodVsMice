QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common/random.cpp \
    main.cpp \
    mainwindow.cpp \
    model/file.cpp \
    model/level/level_manager.cpp \
    view/GUI_manager.cpp \
    view/game_manager.cpp \
    view/music_manager.cpp \
    view/time_manager.cpp \
    viewmodel/card/card.cpp \
    viewmodel/sprite/flame/flame.cpp \
    viewmodel/sprite/flame/flame_manager.cpp \
    viewmodel/sprite/food/food.cpp \
    viewmodel/sprite/food/food_manager.cpp \
    viewmodel/sprite/food/stove.cpp \
    viewmodel/sprite/mouse/bucket_mouse.cpp \
    viewmodel/sprite/mouse/mouse.cpp \
    viewmodel/sprite/mouse/mouse_manager.cpp \
    viewmodel/sprite/projectile/horizontal_projectile.cpp \
    viewmodel/sprite/projectile/projectile.cpp \
    viewmodel/sprite/sprite.cpp

HEADERS += \
    common/common.h \
    common/enums.h \
    common/random.h \
    mainwindow.h \
    model/file.h \
    model/level/level_manager.h \
    view/GUI_manager.h \
    view/game_manager.h \
    view/music_manager.h \
    view/time_manager.h \
    viewmodel/card/card.h \
    viewmodel/sprite/flame/flame.h \
    viewmodel/sprite/flame/flame_manager.h \
    viewmodel/sprite/food/food.h \
    viewmodel/sprite/food/food_manager.h \
    viewmodel/sprite/food/stove.h \
    viewmodel/sprite/mouse/bucket_mouse.h \
    viewmodel/sprite/mouse/mouse.h \
    viewmodel/sprite/mouse/mouse_manager.h \
    viewmodel/sprite/projectile/horizontal_projectile.h \
    viewmodel/sprite/projectile/projectile.h \
    viewmodel/sprite/sprite.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
