#include "Shader.h"
#include <fstream>
#include <iostream>

unsigned int Shader::CompileShader(unsigned int type, const std::string &shaderCode){
    
    // std::cout << "CompileShader(" << type << ", " <<shaderCode << ");" << std::endl;
    
    unsigned int id = glCreateShader(type);
    const char *src = shaderCode.c_str();

    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));

    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

    if (!result)
    {
        int length;
        GLCall( glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
        char *message = (char *)alloca(length * sizeof(char));
        GLCall( glGetShaderInfoLog(id, length, &length, message));
        std::cout << "FAILED TO COMPILE : " << ((type == GL_VERTEX_SHADER) ? "Vertex" : "Fragment") << std::endl;
        std::cout << message << std::endl;

       GLCall(glDeleteShader(id));
        return 0;
    }

    return id;
}

unsigned int Shader::CreateShader(const std::string vertexShader, const std::string fragmentShader){

    // std::cout << "CreateShader(" << vertexShader <<", " <<fragmentShader << ");" << std::endl;


    unsigned int program = glCreateProgram();

    unsigned int vshader = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fshader = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GLCall(glAttachShader(program, vshader));
    GLCall(glAttachShader(program, fshader));

    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    return program;
}

std::string Shader::loadShader(std::string path){
    // std::cout << "loadShader(" << path  << ");" << std::endl;

    std::ifstream file;
    file.open(path);
    std::string shader = "";
    std::string line;
    while(getline(file,line)){
        shader+= line + '\n';
    }
    file.close();
    return shader;
}

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath){

    vertexShaderCode = loadShader(vertexShaderPath);
    fragmentShaderCode = loadShader(fragmentShaderPath);
    shaderID = CreateShader(vertexShaderCode,fragmentShaderCode);
    GLCall( glUseProgram(shaderID));
}

void Shader::useProgram(){
    GLCall( glUseProgram(shaderID));
}

Shader::~Shader(){
    glDeleteShader(shaderID);
}

void Shader::useUniform4f(std::string uniform, float f1 = 0, float f2 = 0, float f3 = 0, float f4 = 0) {

    GLuint uniformlocation = glGetUniformLocation(shaderID,uniform.c_str());
    GLCall( glUniform4f(uniformlocation,f1,f2,f3,f4) );

}

