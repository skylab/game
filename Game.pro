TEMPLATE = app
#CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QT += opengl

CONFIG+=c++11

#Linux
#LIBS += -lGLEW -lGL -lglfw

# Windows
LIBS += -lglew32s
LIBS += -lopengl32
LIBS += -lglfw3

SOURCES += main.cpp \
    game.cpp \
    GraphicSystem/Shaders/shader.cpp \
    GraphicSystem/Shaders/shaderprogram.cpp \
    GraphicSystem/graphicobject.cpp \
    GraphicSystem/Shaders/shadermanager.cpp \
    Main/scenemanager.cpp \
    Main/object.cpp \
    Common/objectraw.cpp \
    Utils/objectloader.cpp \
    Utils/ObjectLoaders/loader3ds.cpp \
    Utils/ObjectLoaders/loaderabs.cpp \
    System/windowmanager.cpp \
    Main/scene.cpp \
    Main/camera.cpp \
    Main/Commands/command.cpp \
    System/glew/glew.c

HEADERS += \
    game.h \
    Common/precommon.h \
    GraphicSystem/pregraphic.h \
    GraphicSystem/Shaders/shader.h \
    GraphicSystem/Shaders/shaderprogram.h \
    GraphicSystem/graphicobject.h \
    GraphicSystem/Shaders/shadermanager.h \
    Main/scenemanager.h \
    Main/premain.h \
    Main/object.h \
    Common/objectraw.h \
    Utils/objectloader.h \
    Utils/ObjectLoaders/loader3ds.h \
    Utils/ObjectLoaders/loaderabs.h \
    System/windowmanager.h \
    Main/scene.h \
    Main/camera.h \
    Main/Commands/command.h \
    System/glew/glew.h

OTHER_FILES += \
    Resources/Menus/MainMenu.bmp \
    Resources/Shaders/FragmentShader.fsh \
    Resources/Shaders/VertexShader.vsh \
    Resources/Engine.3ds \
    Config.txt \
    Resources/Fonts/Arial.bmp

