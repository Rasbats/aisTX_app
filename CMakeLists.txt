cmake_minimum_required(VERSION 3.9.0)
SET(PROJECT_NAME "aisTX_app")
project(${PROJECT_NAME})
set(default_build_type "Release")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
endif()

if(MSVC)
    add_definitions(/MP)
endif()

if(MSVC AND NOT WXSOURCE)
    find_package(wxWidgets REQUIRED COMPONENTS net core base)
    include(${wxWidgets_USE_FILE})
endif()
message(STATUS "CMAKE_BUILD_TYPE:${CMAKE_BUILD_TYPE}")
file(GLOB aisTX_app_SRC
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"        
)
add_executable(${PROJECT_NAME} WIN32 ${aisTX_app_SRC})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

if(MSVC)
add_custom_command(
    TARGET ${PROJECT_NAME} 
    POST_BUILD
    COMMAND "mt.exe" -manifest \"${CMAKE_CURRENT_SOURCE_DIR}\\dpiawarescaleing.manifest\" -inputresource:\"$<TARGET_FILE:${PROJECT_NAME}>\"\;\#1 -outputresource:\"$<TARGET_FILE:${PROJECT_NAME}>\"\;\#1
    COMMENT "Adding display aware manifest..." 
)
endif()


