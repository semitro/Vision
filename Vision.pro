TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/robot.cpp \
    src/behaviour.cpp \
    src/vision/objectdetector.cpp \
    src/vision/sightcorrector.cpp \
    src/vision/vision.cpp \
    src/semantic/node.cpp \
    src/semantic/testing.cpp \
    src/semantic/semanticweb.cpp \
    src/mind.cpp \
    src/decision_performer.cpp \
    src/attention_controller.cpp \
    src/decision.cpp \
    src/sensor/distance.cpp \
    src/settings.cpp

CCFLAG +=

LIBS += -lpthread -lavcodec
# -lavformat -lavresample -lswscale -lavutil
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_videoio -lopencv_objdetect -lopencv_imgproc -lopencv_highgui

INCLUDEPATH += headers

HEADERS += \
    headers/robot.hpp \
    headers/vision/objectdetector.hpp \
    headers/vision/sightcorrector.hpp \
    headers/vision/vision.hpp \
    headers/semantic/node.hpp \
    headers/semantic/testing.h \
    headers/semantic/semanticweb.hpp \
    headers/mind.hpp \
    headers/decision.hpp \
    headers/decision_performer.hpp \
    headers/attention_controller.hpp \
    headers/behaviour.hpp \
    headers/sensor/distance.hpp \
    headers/settings.hpp

STATECHARTS +=

DISTFILES += \
    headers/semantic/semantic.qmodel

