cmake_minimum_required (VERSION 3.5)

project(sImageAnnotator LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)

set(QT_COMPONENTS Core Widgets Network Xml PrintSupport DBus Svg)
set(QT_MIN_VERSION 5.9.4)

if (UNIX AND NOT APPLE)
	list(APPEND QT_COMPONENTS Concurrent)
endif()

find_package(Qt5 ${QT_MIN_VERSION} REQUIRED ${QT_COMPONENTS})

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(KIMAGEANNOTATOR_MIN_VERSION "0.5.0")
find_package(kImageAnnotator ${KIMAGEANNOTATOR_MIN_VERSION} REQUIRED)

set(KCOLORPICKER_MIN_VERSION "0.1.5")
find_package(kColorPicker ${KCOLORPICKER_MIN_VERSION} REQUIRED)


add_subdirectory(src)
