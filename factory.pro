TEMPLATE = app
TARGET = factory
HEADERS += \
    factory.hpp \
    derives.hpp \
    base.hpp \
    classfactory.hpp

SOURCES += \
    main.cpp \
    factory.cpp \
    classfactory.cpp

QMAKE_CXXFLAGS += -Wcomment
#LIBS += -lboost -lloki
