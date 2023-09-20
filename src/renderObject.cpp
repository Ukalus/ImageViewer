#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>



class Vector3 {
    public:
        float x;
        float y;
        float z;
};

class Texture2D {
    char* path;
    public:        
        Texture2D(char* path){
            loadTexture(path);
        };
        void loadTexture(char* path){
            std::cout << "loading texture here";
        };

};

class Shader {
    public:
    char* vertex;
    char* fragment;
};

class Mesh{
    public: 
        void *vertexArray; 
        Texture2D* texture2D;
        Shader *shader;
        Mesh(void *vertexArray = nullptr,Texture2D *texture2D = nullptr){
            this -> vertexArray = vertexArray;
            this -> texture2D = texture2D;
        };
};

class Transform{
    public:
        Vector3*  position;
        Vector3*  rotation;
        Vector3*  scale;
};

class renderObject{
    public:
        int id;
        Transform transform;
        Mesh mesh;
        void initialize(){};
        void update(){};
        void free(){};
    private:
        char* name;

};



