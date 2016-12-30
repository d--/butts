cmake_minimum_required(VERSION 3.3)
project(butts)

find_package(OpenGL REQUIRED)
if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
    find_package(SDL2 REQUIRED)
    find_package(GLEW REQUIRED)
endif(NOT MSVC)
if(MSVC)
    set(WINDOWS_SDL2_DIR C:/dev/sdl2)
    set(WINDOWS_SDL2_LIB_DIR ${WINDOWS_SDL2_DIR}/lib/x86)

    set(SDL2_INCLUDE_DIRS ${WINDOWS_SDL2_DIR}/include)
    find_library(SDL2_LIBRARY
            NAMES SDL2
            PATH_SUFFIXES lib
            PATHS ${WINDOWS_SDL2_LIB_DIR}
    )

    find_library(SDL2_LIBRARY_MAIN
            NAMES SDL2main
            PATH_SUFFIXES lib
            PATHS
            PATHS ${WINDOWS_SDL2_LIB_DIR}
    )

    set(SDL2_LIBRARIES ${SDL2_LIBRARY} ${SDL2_LIBRARY_MAIN})

    set(WINDOWS_GLEW_DIR C:/dev/GLEW)
    set(WINDOWS_GLEW_LIB_DIR ${WINDOWS_GLEW_DIR}/lib/Release/Win32)

    set(GLEW_INCLUDE_DIR ${WINDOWS_GLEW_DIR}/include)
    find_library(GLEW_LIBRARY
            NAMES glew32 
            PATH_SUFFIXES lib
            PATHS ${WINDOWS_GLEW_LIB_DIR}
    )

    include_directories(${GLEW_INCLUDE_DIR})
endif(MSVC)

include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# unfortunately necessary
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

if(MSVC)
    add_custom_command(TARGET butts POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${WINDOWS_SDL2_LIB_DIR}/SDL2.dll"
            $<TARGET_FILE_DIR:butts>)
endif(MSVC)

target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARY})
