#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>


class Canvas{
    public:

    int width = 800;
    int heigth = 800;

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    unsigned int FBO;
    unsigned int RBO;

    unsigned int textureId;
    unsigned int shaderId; 

    std::string vertexShaderSourcePath;
    std::string fragmentShaderSourcePath;
    enum ShaderType {
        vertex,
        fragment
    };

    unsigned int loadShader(std::string filePath, ShaderType type){
        std::ifstream shaderFile;
        shaderFile.open(filePath);
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        if(type == ShaderType::vertex){
            std::string vertexShaderString = shaderStream.str();
            const char* vertexShaderSource = vertexShaderString.c_str();
            unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
            glCompileShader(vertexShader);
            return vertexShader;

        }
        else if(type == ShaderType::fragment){
            std::string fragmentShaderString = shaderStream.str();
            const char* fragmentShaderSource = fragmentShaderString.c_str();
            unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
            glCompileShader(fragmentShader);
            return fragmentShader;
            
        }

        
        
        
        
    }
    void drawImage(GLFWwindow* window,float width,float height){
        float vertices[] = {
            0.0f,  -1.0f, 0.0f,
            0.0f,   1.0f, 0.0f,
            1.0f,   1.0f, 0.0f,
            1.0f,  -1.0f, 0.0f,
        };
        unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
        };
        


        unsigned int VBO;
        unsigned int VAO;
        unsigned int EBO;


        unsigned int vertexShader;
        unsigned int fragmentShader;


        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);


        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);


        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);


        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        
        vertexShader = loadShader("./shader/canvas.vert", ShaderType::vertex);
        fragmentShader = loadShader("./shader/canvas.frag", ShaderType::fragment); 
        

        unsigned int shaderProgram;
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);


        glUseProgram(shaderProgram);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);
        

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }
};
