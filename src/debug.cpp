#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <misc/cpp/imgui_stdlib.h>
#include <chrono>
#include <ctime>
#include <iostream>

class Debug {
    public:
    int* windowHeight;
    int* windowWidth;
    long duration;
    int* FPS;
    
    
    void getDimensions(int* windowHeight,int* windowWidth){
        this -> windowHeight = windowHeight;
        this -> windowWidth = windowWidth;
    }

    void getFPS(){
        auto now = std::chrono::high_resolution_clock::now();
        auto ns_now = std::chrono::time_point_cast<std::chrono::nanoseconds>(now);
        this -> duration = ns_now.time_since_epoch().count();
    }
    void draw(){
        getFPS();
        int now = this-> duration;
        ImGui::Begin("Debugging Info");
            ImGui::Text("Framerate");
            ImGui::Text("Window Size:");
            ImGui::InputInt("Height ", windowHeight);
            ImGui::InputInt("Width", windowWidth);
            ImGui::InputInt("Duration", &now);
        ImGui::End();
    }
};