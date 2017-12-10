cmake_minimum_required (VERSION 2.6)
project (SampleApp)

set(CMAKE_BUILD_TYPE Release)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
	add_definitions(-O2 -Os) 
endif()

set (WXWIDGETS_ROOT C:/wxWidgets-3.0.3)
set (MINGW_ROOT C:/mingw64)

set (PROJECT_LINK_LIBS libwxmsw30u.a libcomctl32.a libwxpng.a libwxzlib.a)
link_directories(${WXWIDGETS_ROOT}/lib ${MINGW_ROOT}/x86_64-w64-mingw32/lib)

include_directories(${WXWIDGETS_ROOT}/include)
file(GLOB SOURCES "*.cpp")

add_executable(SampleApp ${SOURCES})
target_link_libraries(SampleApp ${PROJECT_LINK_LIBS} -mwindows)