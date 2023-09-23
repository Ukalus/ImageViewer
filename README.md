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

#### Installing on Linux (Manjaro)

if your new compiling first read this: https://learnopengl.com/Getting-started/Creating-a-window


GLAD

As mention in the Tutorial Glad can be configured and downloaded on https://glad.dav1d.de/


GLFW 

either get the glfw libary from your favorite package manager or compile it yourself

i used the following commands inside my project folder to get GLFW included into the project

    git clone https://github.com/glfw/glfw.git
    cd glfw
    cmake ../glfw 
    cmake --build .
    make 
    sudo make install  

after that put the header and lib file into you standard search path something like **/usr/lib/** 



## Classes 

![Docs/Classes.drawio.svg](Docs/Classes.drawio.svg)




