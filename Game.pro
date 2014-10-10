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
    GraphicSystem/Objects/graphicobject.cpp \
    Common/objectraw.cpp \
    GraphicSystem/Shaders/shadermanager.cpp \
    Common/objectloader.cpp \
    Common/ObjectLoaders/loaderabs.cpp \
    Common/ObjectLoaders/loader3ds.cpp \
    Main/gameobject.cpp \
    Main/scenemanager.cpp \
    Main/Objects/scenebase.cpp \
    Main/Objects/camerabase.cpp \
    Main/Objects/objectbase.cpp

HEADERS += \
    game.h \
    GraphicSystem/pregraphic.h \
    GraphicSystem/Shaders/shader.h \
    GraphicSystem/Shaders/shaderprogram.h \
    Common/precommon.h \
    GraphicSystem/Objects/graphicobject.h \
    Common/objectraw.h \
    GraphicSystem/Shaders/shadermanager.h \
    Common/objectloader.h \
    Common/ObjectLoaders/loaderabs.h \
    Common/ObjectLoaders/loader3ds.h \
    Main/gameobject.h \
    Main/scenemanager.h \
    Main/premain.h \
    Main/Objects/scenebase.h \
    Main/Objects/camerabase.h \
    Main/Objects/objectbase.h

OTHER_FILES += \
    Resources/Menus/MainMenu.bmp \
    Resources/Shaders/FragmentShader.fsh \
    Resources/Shaders/VertexShader.vsh \
    Resources/Engine.3ds

