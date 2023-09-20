#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "src/renderObject.h"
#include "imgui/imgui.h"



class UkalusEngine {
    public:
        const unsigned int screenWidth = 800;
        const unsigned int screenHeigth = 600;
        GLFWwindow* window;
        
        bool shouldClose = false;
        

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }

        static void processInput(GLFWwindow *window)
        {
            if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);
        }

       
        // 
        void init(){
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

            window = glfwCreateWindow(screenWidth, screenHeigth, "Ukalus engine", NULL, NULL);
            if (window == NULL)
                {
                    std::cout << "Failed to create GLFW window" << std::endl;
                    glfwTerminate();
                    shouldClose = true;
                }
            glfwMakeContextCurrent(window);
            glfwSetFramebufferSizeCallback(window, UkalusEngine::framebuffer_size_callback);
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
                {
                    std::cout << "Failed to initialize GLAD" << std::endl;
                    shouldClose = true;
                }
           
            
        };
        void update(){
            processInput(window);
        };
        void render(){

            glfwSwapBuffers(window);
            glfwPollEvents();  
            
        };    
        void shutdown(){
            glfwTerminate();
            system("clear");
        };

       
};



int main(){
    UkalusEngine renderer;
    renderObject object = renderObject();
    renderer.init();
    while(!glfwWindowShouldClose(renderer.window)){
        renderer.update();
        renderer.render();
    }
    renderer.shutdown();

    return 0;
}

