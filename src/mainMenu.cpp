#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <misc/cpp/imgui_stdlib.h>

class MainMenu {
    public:

    static void draw(){
        if (ImGui::BeginMainMenuBar())
            {
                if (ImGui::BeginMenu("File"))
                {   
                    if (ImGui::MenuItem("Save", "CTRL+S")) {}
                    if (ImGui::MenuItem("Load", "CTRL+L", false, false)) {}  // Disabled item
                    ImGui::EndMenu();
                }
                if(ImGui::BeginMenu("Tools"))
                {
                    if (ImGui::MenuItem("Debug", "CTRL+D")){};
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Edit"))
                {
                    if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
                    if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
                    ImGui::Separator();
                    if (ImGui::MenuItem("Cut", "CTRL+X")) {}
                    if (ImGui::MenuItem("Copy", "CTRL+C")) {}
                    if (ImGui::MenuItem("Paste", "CTRL+V")) {}
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();                
                
            }
    }
};