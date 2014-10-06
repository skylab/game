TEMPLATE = app
#CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG+=c++11

LIBS += -lGLEW -lglut -lGL -lglfw

SOURCES += main.cpp \
    game.cpp \
    GraphicSystem/Shaders/shader.cpp \
    GraphicSystem/Shaders/shaderprogram.cpp \
    GraphicSystem/Textures/texture.cpp \
    GraphicSystem/Textures/image.cpp \
    GraphicSystem/Textures/imageloaderabs.cpp \
    GraphicSystem/Textures/imageloaderbmp.cpp \
    GraphicSystem/Objects/graphicobject.cpp \
    Scenes/mainscene.cpp \
    Scenes/scene.cpp \
    Scenes/loadingscene.cpp \
    Common/objectraw.cpp \
    Scenes/SceneObject/object.cpp \
    Scenes/scenemanager.cpp \
    Scenes/camera.cpp \
    GraphicSystem/Shaders/shadermanager.cpp \
    Common/objectloader.cpp \
    Common/ObjectLoaders/loaderabs.cpp \
    Common/ObjectLoaders/loader3ds.cpp

HEADERS += \
    game.h \
    GraphicSystem/pregraphic.h \
    GraphicSystem/Shaders/shader.h \
    GraphicSystem/Shaders/shaderprogram.h \
    GraphicSystem/Textures/texture.h \
    GraphicSystem/Textures/image.h \
    GraphicSystem/Textures/imageloaderabs.h \
    GraphicSystem/Textures/imageloaderbmp.h \
    Common/precommon.h \
    GraphicSystem/Objects/graphicobject.h \
    Scenes/mainscene.h \
    Scenes/scene.h \
    Scenes/loadingscene.h \
    Common/objectraw.h \
    Scenes/SceneObject/object.h \
    Scenes/scenemanager.h \
    Scenes/camera.h \
    GraphicSystem/Shaders/shadermanager.h \
    Common/objectloader.h \
    Common/ObjectLoaders/loaderabs.h \
    Common/ObjectLoaders/loader3ds.h

OTHER_FILES += \
    Resources/Menus/MainMenu.bmp \
    Resources/Shaders/FragmentShader.fsh \
    Resources/Shaders/VertexShader.vsh \
    Resources/Engine.3ds

