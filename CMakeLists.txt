project(LeapMotion)

set(LEAP_DIR $ENV{LEAP_HOME})

find_package(Qt4 REQUIRED)
set(QT_USE_QTMAIN true)
set(QT_USE_QTGUI true)
include(${QT_USE_FILE})

include_directories(
	${QT_INCLUDE_DIR}
	${LEAP_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}
	${PROJECT_BINARY_DIR}
)

link_directories(
	${QT_LIBRARY_DIR}
)

set(LeapMotion_SRCS
	main.cpp
	DesktopMascot.cpp
)

set(LeapMotion_HDRS
	DesktopMascot.h
)

add_executable(LeapMotion
	${LeapMotion_SRCS}
	${LeapMotion_HDRS}
)

target_link_libraries(LeapMotion
	${QT_LIBRARIES}
#	${LEAP_DIR}/lib/x86/Leap.lib
#	${LEAP_DIR}/lib/x86/Leapd.lib
)


