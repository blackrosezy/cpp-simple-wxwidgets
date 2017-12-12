cmake_minimum_required(VERSION 2.6)
project(SimpleImagePanel)

set(CMAKE_CXX_FLAGS_RELEASE "-Os")

set(WXWIDGETS_ROOT C:/wxWidgets-3.0.3)
set(MINGW_ROOT C:/mingw64)

set(PROJECT_LINK_LIBS libwxmsw30u.a libcomctl32.a libwxpng.a libwxjpeg.a libwxzlib.a)
link_directories(${WXWIDGETS_ROOT}/lib ${MINGW_ROOT}/x86_64-w64-mingw32/lib)

include_directories(${WXWIDGETS_ROOT}/include)

file(GLOB SOURCES "*.cpp")

if (WIN32)
	ENABLE_LANGUAGE(RC)
	set(SOURCES ${SOURCES} resource.rc)
endif (WIN32)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${PROJECT_LINK_LIBS} -mwindows)

file(COPY images DESTINATION ${CMAKE_CURRENT_BINARY_DIR})