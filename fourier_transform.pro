TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fourier_transform.cpp \
        main.cpp \
        tests.cpp \
        utility_functions.cpp

HEADERS += \
    fourier_transform.h \
    log_duration.h \
    test_framework.h \
    tests.h \
    utility_functions.h
