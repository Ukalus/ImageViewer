#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <misc/cpp/imgui_stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>


#include <canvas.h>
#include <mainMenu.h>
#include <debug.h>


double mouse_x = 0;
double mouse_y = 0;




static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    mouse_x = xpos;
    mouse_y = ypos;
    
}


class UkalusEngine {
    public:
        unsigned int screenWidth = 800;
        unsigned int screenHeigth = 600;
        GLFWwindow* window;
        GLFWwindow* gui_window;
        Canvas canvas;
        MainMenu mainMenu;
        Debug debug;
         
        
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
            glfwSetCursorPosCallback(window, cursor_position_callback);
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
            io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

            // Setup Platform/Renderer backends
            ImGui_ImplGlfw_InitForOpenGL(window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
            ImGui_ImplOpenGL3_Init();

            canvas.loadShader("./shader/canvas.vert", canvas.ShaderType::vertex);
            canvas.loadShader("./shader/canvas.frag", canvas.ShaderType::fragment);
            
        }
        void update(){
            processInput(window);
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }

        void updateGUI(){
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
           
            mainMenu.draw();
            canvas.draw(window,800,800);
            debug.draw();
        }

        void render()
        {
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            glfwSwapBuffers(window);
            glfwPollEvents(); 
        }  

        void shutdown()
        {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
            glfwTerminate();
            system("clear");
        }
};


int main(){
    UkalusEngine renderer;
    renderer.init();
    while(!glfwWindowShouldClose(renderer.window)){
        renderer.update();
        renderer.updateGUI();
        renderer.render();
       
      
    }
    renderer.shutdown();

    return 0;
}
