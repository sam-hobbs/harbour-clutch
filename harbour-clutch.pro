# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = harbour-clutch

CONFIG += sailfishapp c++11

SOURCES += src/harbour-clutch.cpp \
    src/transmissioncontrol.cpp \
    src/filesmodel.cpp \
    src/filesmodelworker.cpp \
    src/settings.cpp

HEADERS += src/transmissioncontrol.h \
    src/filesmodel.h \
    src/filesmodelworker.h \
    src/settings.h

OTHER_FILES += qml/harbour-clutch.qml \
    qml/pages/MainPage.qml \
    qml/cover/CoverPage.qml \
    qml/pages/AboutPage.qml \
    qml/pages/SettingsPage.qml \
    qml/pages/WebRemote.qml \
    qml/pages/FilePicker.qml \
    rpm/harbour-clutch.spec \
    rpm/harbour-clutch.yaml \
    rpm/harbour-clutch.changes \
    translations/*.ts \
    harbour-clutch.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
#TRANSLATIONS += translations/harbour-clutch-de.ts

DISTFILES += qml/js/PixelRatioHandler.js


RESOURCES += harbour-clutch.qrc

DISTFILES +=
