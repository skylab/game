TEMPLATE = app
#CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

#QT += opengl

CONFIG+=c++11

#Linux
#LIBS += -lGLEW -lGL -lglfw

#Windows
LIBS += -lglew32s -lopengl32 -lglfw3
HEADERS += System/glew/glew.h
SOURCES += System/glew/glew.c

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
    Utils/ObjectLoaders/3ds/lib3ds_atmosphere.c \
    Utils/ObjectLoaders/3ds/lib3ds_background.c \
    Utils/ObjectLoaders/3ds/lib3ds_camera.c \
    Utils/ObjectLoaders/3ds/lib3ds_chunk.c \
    Utils/ObjectLoaders/3ds/lib3ds_chunktable.c \
    Utils/ObjectLoaders/3ds/lib3ds_file.c \
    Utils/ObjectLoaders/3ds/lib3ds_io.c \
    Utils/ObjectLoaders/3ds/lib3ds_light.c \
    Utils/ObjectLoaders/3ds/lib3ds_material.c \
    Utils/ObjectLoaders/3ds/lib3ds_math.c \
    Utils/ObjectLoaders/3ds/lib3ds_matrix.c \
    Utils/ObjectLoaders/3ds/lib3ds_mesh.c \
    Utils/ObjectLoaders/3ds/lib3ds_node.c \
    Utils/ObjectLoaders/3ds/lib3ds_quat.c \
    Utils/ObjectLoaders/3ds/lib3ds_shadow.c \
    Utils/ObjectLoaders/3ds/lib3ds_track.c \
    Utils/ObjectLoaders/3ds/lib3ds_util.c \
    Utils/ObjectLoaders/3ds/lib3ds_vector.c \
    Utils/ObjectLoaders/3ds/lib3ds_viewport.c \
    GraphicSystem/Testure/texture.cpp \
    Utils/imageloader.cpp \
    Utils/ImageLoaders/imageloaderabs.cpp

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
    Utils/ObjectLoaders/3ds/lib3ds.h \
    Utils/ObjectLoaders/3ds/lib3ds_impl.h \
    GraphicSystem/Testure/texture.h \
    Utils/imageloader.h \
    Utils/ImageLoaders/imageloaderabs.h

OTHER_FILES += \
    Resources/Menus/MainMenu.bmp \
    Resources/Shaders/FragmentShader.fsh \
    Resources/Shaders/VertexShader.vsh \
    Resources/Engine.3ds \
    Config.txt \
    Resources/Fonts/Arial.bmp \
    MyMakefile
