TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    objectdetector.cpp \
    sightanalyser.cpp \
    behaviour.cpp \
    sightcorrector.cpp

LIBS += -lpthread -lavcodec
# -lavformat -lavresample -lswscale -lavutil
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_videoio -lopencv_objdetect -lopencv_imgproc #-lopencv_highgui

HEADERS += \
    objectdetector.hpp \
    sightanalyser.hpp \
    sightcorrector.hpp

