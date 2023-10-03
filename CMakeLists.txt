cmake_minimum_required(VERSION 3.10)
project(ImageViewer)


# This adds the paths inside the program
set(SRC_DIR ./src)
set(INCLUDE_DIR ./include)
set(THIRD_PARTY ./third_party)


# All source code files i have written
set(SOURCES
    ${SRC_DIR}/main.cpp 
    ${SRC_DIR}/canvas.cpp
    ${SRC_DIR}/mainMenu.cpp
    ${SRC_DIR}/debug.cpp
    ${THIRD_PARTY}/imgui/imgui.cpp
    ${THIRD_PARTY}/imgui/imgui_demo.cpp 
    ${THIRD_PARTY}/imgui/imgui_draw.cpp 
    ${THIRD_PARTY}/imgui/imgui_tables.cpp 
    ${THIRD_PARTY}/imgui/imgui_widgets.cpp   
    ${THIRD_PARTY}/imgui/backends/imgui_impl_glfw.cpp
    ${THIRD_PARTY}/imgui/backends/imgui_impl_opengl3.cpp
    ${THIRD_PARTY}/imgui/misc/cpp/imgui_stdlib.cpp
)






add_executable(ImageViewer
    ${SOURCES}
)

# All include directories in which the header files are for the project
target_include_directories(ImageViewer PUBLIC
    ${INCLUDE_DIR}
    ${THIRD_PARTY}
    ${THIRD_PARTY}/imgui
    ${THIRD_PARTY}/imgui/backends
    ${THIRD_PATTY}/stb
    
) 

add_subdirectory(${THIRD_PARTY}/glad)

# All library file include paths  
target_link_directories(ImageViewer PUBLIC 
    ${THIRD_PARTY}/lib/
    
)

# Linking the librarys to target
target_link_libraries(ImageViewer glfw3 glad)
