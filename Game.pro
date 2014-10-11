TEMPLATE = app
#CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG+=c++11

LIBS += -lGLEW -lGL -lglfw

SOURCES += main.cpp \
    game.cpp \
    GraphicSystem/Shaders/shader.cpp \
    GraphicSystem/Shaders/shaderprogram.cpp \
    GraphicSystem/graphicobject.cpp \
    Common/objectraw.cpp \
    GraphicSystem/Shaders/shadermanager.cpp \
    Common/objectloader.cpp \
    Common/ObjectLoaders/loaderabs.cpp \
    Common/ObjectLoaders/loader3ds.cpp \
    Main/scenemanager.cpp \
    Main/Objects/gameobject.cpp \
    Main/object.cpp \
    Main/Objects/sceneobject.cpp \
    Main/Objects/cameraobject.cpp

HEADERS += \
    game.h \
    GraphicSystem/pregraphic.h \
    GraphicSystem/Shaders/shader.h \
    GraphicSystem/Shaders/shaderprogram.h \
    Common/precommon.h \
    GraphicSystem/graphicobject.h \
    Common/objectraw.h \
    GraphicSystem/Shaders/shadermanager.h \
    Common/objectloader.h \
    Common/ObjectLoaders/loaderabs.h \
    Common/ObjectLoaders/loader3ds.h \
    Main/scenemanager.h \
    Main/premain.h \
    Main/Objects/gameobject.h \
    Main/object.h \
    Main/Objects/sceneobject.h \
    Main/Objects/cameraobject.h

OTHER_FILES += \
    Resources/Menus/MainMenu.bmp \
    Resources/Shaders/FragmentShader.fsh \
    Resources/Shaders/VertexShader.vsh \
    Resources/Engine.3ds

