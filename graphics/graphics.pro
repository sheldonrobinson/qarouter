# -------------------------------------------------
# Project created by QtCreator 2011-06-16T09:55:28
# -------------------------------------------------
QT += gui
win32: CONFIG += qt dll debug
unix: CONFIG += dll debug
INCLUDEPATH += include ../include ../specctra/include
TARGET = graphics
TEMPLATE = lib
unix {
	target.path = /usr/local/lib
	INSTALLS += target
}
SOURCES += cgpad.cpp \
		cgpadstack.cpp \
		cgsegment.cpp \
		cgvia.cpp \
		cgwire.cpp \
		cutil.cpp

HEADERS += include/cgpad.h \
		include/cgpadstack.h \
		include/cgraphics.h \
		include/cgsegment.h \
		include/cgvia.h \
		include/cgwire.h \
		include/cutil.h

OTHER_FILES += README.txt
