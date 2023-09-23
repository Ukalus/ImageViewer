#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <renderObject.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>



class UkalusEngine {
    public:
        const unsigned int screenWidth = 800;
        const unsigned int screenHeigth = 600;
        GLFWwindow* window;
        GLFWwindow* gui_window;
        
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
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
            io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

            gui_window = glfwCreateWindow(screenWidth, screenHeigth, "ImGui Example", NULL, NULL);
            glfwMakeContextCurrent(gui_window);
            // Setup Platform/Renderer backends
            ImGui_ImplGlfw_InitForOpenGL(gui_window, false);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
            ImGui_ImplOpenGL3_Init();
            
        };
        void update(){
            processInput(window);
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
            ImGui::ShowDemoWindow(); // Show demo window! :)
        };
        void render(){
            
            glfwSwapBuffers(window);
            glfwPollEvents(); 
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            
        };    
        void shutdown(){
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
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

