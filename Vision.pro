TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    objectdetector.cpp \
    sightanalyser.cpp \
    behaviour.cpp


LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_objdetect -lopencv_imgproc
LIBS += -lpthread
HEADERS += \
    objectdetector.hpp \
    sightanalyser.hpp

