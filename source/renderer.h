#pragma once
#include <glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <csignal>

#define OPENGL_INIT_BOILERPLATE \
    glfwInit(); \
    GLFWwindow* mainWindow = glfwCreateWindow(800, 800, "PROGRAM", NULL, NULL); \
    if (mainWindow == NULL) { \
        std::cout << "Failed to create a Window" << std::endl; \
    } \
    glfwMakeContextCurrent(mainWindow); \
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { \
        std::cout << "Failed to initialize GLAD" << std::endl; \
        return -1; \
    } \
    glfwSetFramebufferSizeCallback(mainWindow, resizeWindow); \
    glViewport(0, 0, 800, 800); \
    glfwSwapInterval(1);


#define ASSERT(x) if(!(x)) std::raise(SIGTRAP);
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__,__LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
void resizeWindow(GLFWwindow* window, int height, int width);
void processInput(GLFWwindow* window);
