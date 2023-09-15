Goal of this project:

Use ImGui and OpenGl to view an image (maybe even edit it)

definition of done:

- [ ] ImGui window with open and safe functionality 
- [ ] OpenGl context inside of application 


Building the Project:

Is done by using CMake as a build-system.

To build this project you need the following libraries:

- GLAD
- GLFW
- ImGui

if your new compiling first read this: https://learnopengl.com/Getting-started/Creating-a-window


GLAD

As mention in the Tutorial Glad can be configured and downloaded on https://glad.dav1d.de/


GLFW 

I decided to use GLFW as a Dynamic Library so i dont have to deal with linking system specific files to the linker
EDIT: in the future i may also use GLFW as a static libary if im developing, to decrease compile time 

i used the following commands inside my project folder to get GLFW included into the project

git clone https://github.com/glfw/glfw.git
cd glfw
cmake -D BUILD_SHARED_LIBS=ON ../glfw 
cmake --build .
make 
make DESTDIR=.. install ../   