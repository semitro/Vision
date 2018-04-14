TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/objectdetector.cpp \
    src/behaviour.cpp \
    src/sightcorrector.cpp \
    src/vision.cpp \
    src/robot.cpp \
    src/main.cpp

CCFLAG +=

LIBS += -lpthread -lavcodec
# -lavformat -lavresample -lswscale -lavutil
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_videoio -lopencv_objdetect -lopencv_imgproc -lopencv_highgui

INCLUDEPATH += headers

HEADERS += \
    headers/objectdetector.hpp \
    headers/sightcorrector.hpp \
    headers/robot.hpp \
    headers/vision.hpp

STATECHARTS +=

DISTFILES +=

