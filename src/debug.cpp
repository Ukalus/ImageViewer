#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <misc/cpp/imgui_stdlib.h>

class Debug {
    public:

    void draw(){
        ImGui::Begin("Debugging Info");
            ImGui::Text("Framerate");
            ImGui::Text("Window Size:");
            ImGui::Text("Heigth:");
            ImGui::Text("Width:");
        ImGui::End();
    }
};