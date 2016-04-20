TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS = -lGL -lGLU -lGLEW -lglfw -lassimp -lSDL2 -lSDL2_mixer

SOURCES += \
    main.cpp \
    Application Manager/ApplicationManager.cpp \
    EulerCamera/EulerCamera.cpp \
    Model/Model.cpp \
    Renderer/Renderer.cpp \
    Shaders/shader.cpp \
    Texture/texture.cpp \
    Texture/Texture_Loader/stb_image.c \
    Application_Manager/ApplicationManager.cpp

HEADERS += \
    Application Manager/ApplicationManager.h \
    EulerCamera/EulerCamera.h \
    Model/Model.h \
    Renderer/Renderer.h \
    Shaders/shader.hpp \
    Texture/Texture_Loader/stb_image.h \
    Texture/texture.h \
    Application_Manager/ApplicationManager.h

INCLUDEPATH += ../../glm
