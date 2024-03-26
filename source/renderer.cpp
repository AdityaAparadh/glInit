#include "renderer.h"

void GLClearError(){
    while( glGetError() != GL_NO_ERROR);
}
bool GLLogCall(const char* function, const char* file, int line){
    while( GLenum error = glGetError() ){
        std::cout << "[GL ERROR] - " << error << " " << "\n In File" << file <<"  " << "\n LINE: " << line << std::endl;
        return false;
    }
    return true;
}

void resizeWindow(GLFWwindow* window, int height, int width){
    GLCall(glViewport(0,0,height,width));
}
void processInput(GLFWwindow* window){

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}
