#include <glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <cmath>

#include "source/renderer.h"
#include "source/IndexBuffer.h"
#include "source/VertexBuffer.h"
#include "source/Texture.h"
#include "source/VertexArray.h"
#include "source/VertexBufferLayout.h"
#include "source/Shader.h"
#include "source/Texture.h"

int main()
{

    OPENGL_INIT_BOILERPLATE

    float vertices[] = {
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
    };
    unsigned int indices[] = {0, 1, 2, 0, 2, 3};

    VertexBuffer vb(vertices, 32 * sizeof(float));
    IndexBuffer ib(indices, 6);

    VertexBufferLayout layout;
    layout.PushFloat(3);
    layout.PushFloat(3);
    layout.PushFloat(2);

    VertexArray VA1;
    VA1.AddBuffer(vb, layout, ib);

    Shader s("../shaders/VertexShader.glsl", "../shaders/FragmentShader.glsl");
    Texture t("../textures/block.png", 4);

    while (!glfwWindowShouldClose(mainWindow))
    {
        processInput(mainWindow);
        GLCall(glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr));
        glfwPollEvents();
        glfwSwapBuffers(mainWindow);
    }

    glfwTerminate();
}