
set(SRCS
	sImageAnnotator.cpp
	MainWindow.cpp
	)

add_executable(sImageAnnotator ${SRCS})

qt5_use_modules(${PROJECT_NAME} Widgets)
target_link_libraries(sImageAnnotator kImageAnnotator kColorPicker X11 Qt5::Svg)
