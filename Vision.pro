TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    objectdetector.cpp \
    sightanalyser.cpp

LIBS += -lpthread -lavcodec
# -lavformat -lavresample -lswscale -lavutil
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_videoio -lopencv_objdetect -lopencv_imgproc

HEADERS += \
    objectdetector.hpp \
    sightanalyser.hpp

