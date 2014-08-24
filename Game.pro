TEMPLATE = app
#CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG+=c++11

LIBS += -lGLEW -lglut -lGL

SOURCES += main.cpp \
    GraphicSystem/graphicsystem.cpp \
    game.cpp \
    GraphicSystem/Scenes/sceneabs.cpp \
    GraphicSystem/Objects/objectabs.cpp \
    GraphicSystem/Shaders/shader.cpp \
    GraphicSystem/Shaders/shaderprogram.cpp \
    GraphicSystem/Objects/objecttriangle.cpp \
    GraphicSystem/Objects/objectcube.cpp \
    GraphicSystem/Objects/objectquad.cpp \
    GraphicSystem/Scenes/menuscene.cpp \
    GraphicSystem/Scenes/gamescene.cpp

HEADERS += \
    GraphicSystem/graphicsystem.h \
    game.h \
    GraphicSystem/pregraphic.h \
    GraphicSystem/Scenes/sceneabs.h \
    GraphicSystem/Objects/objectabs.h \
    GraphicSystem/Shaders/shader.h \
    GraphicSystem/Shaders/shaderprogram.h \
    GraphicSystem/Objects/objecttriangle.h \
    GraphicSystem/Objects/objectcube.h \
    GraphicSystem/Objects/objectquad.h \
    GraphicSystem/Scenes/menuscene.h \
    GraphicSystem/Scenes/gamescene.h

OTHER_FILES += \
    GraphicSystem/Shaders/VertexShader.vsh \
    GraphicSystem/Shaders/FragmentShader.fsh

