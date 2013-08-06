project(LeapMotion)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
set(LEAP_DIR $ENV{LEAP_HOME})

find_package(Boost REQUIRED COMPONENTS system thread)
find_package(Qt4 REQUIRED)
set(QT_USE_QTMAIN true)
set(QT_USE_QTGUI true)
include(${QT_USE_FILE})

include_directories(
	${QT_INCLUDE_DIR}
	${LEAP_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}
	${PROJECT_BINARY_DIR}
	${BOOST_INCLUDE_DIRS}
	${BOOST_INCLUDE_DIR}
)

link_directories(
	${QT_LIBRARY_DIR}
	${Boost_LIBRARY_DIRS}
	${Boost_LIBRARY_DIR}
)

set(LeapMotion_SRCS
	main.cpp
	DesktopMascot.cpp
	DesktopLauncher.cpp
)

set(LeapMotion_HDRS
	DesktopMascot.h
	DesktopLauncher.h
)

QT4_WRAP_CPP(LeapMotion_MOC ${LeapMotion_HDRS})

add_executable(LeapMotion
	${LeapMotion_SRCS}
	${LeapMotion_HDRS}
	${LeapMotion_MOC}
)

target_link_libraries(LeapMotion
	${Boost_LIBRARIES}
	${QT_LIBRARIES}
	${LEAP_DIR}/lib/x86/Leap.lib
	${LEAP_DIR}/lib/x86/Leapd.lib
)


