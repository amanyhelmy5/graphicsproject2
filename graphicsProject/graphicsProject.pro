TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS = -lGL -lGLU -lGLEW -lglfw -lassimp -lSDL2 -lSDL2_mixer

INCLUDEPATH += $$PWD/../glm
DEPENDPATH += $$PWD/../glm

HEADERS += \
    Application_Manager/ApplicationManager.h \
    EulerCamera/EulerCamera.h \
    Model/Model.h \
    Renderer/Renderer.h \
    Shaders/shader.hpp \
    Texture/Texture_Loader/stb_image.h \
    Texture/texture.h \
    InputHandler/inputhandler.h \
    actions.h \
    Model/square.h \
    game.h \
    Collision/Bounding_Box.h \
    Collision/Collidable_Model.h \
    Collision/Collision_Manager.h \
    Model/my_hero.h \
    ShaderProgram/ShaderProgram.h \
    objloader.hpp

SOURCES += \
    Application_Manager/ApplicationManager.cpp \
    EulerCamera/EulerCamera.cpp \
    Model/Model.cpp \
    Renderer/Renderer.cpp \
    Shaders/shader.cpp \
    Texture/texture.cpp \
    main.cpp \
    Texture/Texture_Loader/stb_image.c \
    InputHandler/inputhandler.cpp \
    Model/square.cpp \
    game.cpp \
    Collision/Bounding_Box.cpp \
    Collision/Collidable_Model.cpp \
    Collision/Collision_Manager.cpp \
    Model/my_hero.cpp \
    ShaderProgram/ShaderProgram.cpp \
    objloader.cpp

