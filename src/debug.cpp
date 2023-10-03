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
    int FPNS;
    
    
    void getDimensions(int* windowHeight,int* windowWidth){
        this -> windowHeight = windowHeight;
        this -> windowWidth = windowWidth;
    }

    void getFPS(){
        auto now = std::chrono::system_clock::now();
        auto ms_now = std::chrono::time_point_cast<std::chrono::nanoseconds>(now);
        auto difference = ms_now.time_since_epoch().count() - this -> duration;
        this -> FPNS = difference / 1000;
        this -> duration =  ms_now.time_since_epoch().count();
    }
    void draw(){
        getFPS();
        ImGui::Begin("Debugging Info");
            ImGui::Text("Framerate");
            ImGui::Text("Window Size:");
            ImGui::InputInt("Height ", windowHeight);
            ImGui::InputInt("Width", windowWidth);
            ImGui::Text("Framerate:");
            ImGui::InputInt("##", &FPNS);
            ImGui::Text("Performance");
        ImGui::End();
    }
};