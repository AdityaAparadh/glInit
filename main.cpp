#include <glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "source/renderer.h"
#include "source/IndexBuffer.h"
#include "source/VertexBuffer.h"
#include "source/Texture.h"
#include "source/VertexArray.h"
#include "source/VertexBufferLayout.h"
#include "source/Shader.h"
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
    s.useUniform4f("someColor",1.0f,0.0f,0.0f,1.0f);


    Texture t("../textures/block.png", 4);


    // glm::vec4 vec(1.0f,0.0f,0.0f,1.0f);
    // glm::mat4 matrix(1.0f);
    // matrix = glm::translate(matrix, glm::vec3(1.0,1.0,0.0f)); // This creates a transformation Matrix, basically using the translation vector
    // vec = matrix * vec;
    // std::cout << vec.x << " " << vec.y << " " << vec.z ;

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::scale(trans, glm::vec3(0.5 ,0.5,0.5));
    // trans = glm::scale(trans, glm::vec3(1.5 ,1.5,1.5));




   while (!glfwWindowShouldClose(mainWindow))
    {
        processInput(mainWindow);
        glClear(GL_COLOR_BUFFER_BIT);

       trans = glm::rotate(trans, 0.005f, glm::vec3(0.0,0.0,1.0) );
       s.useUniform4fv("transform",1,glm::value_ptr(trans));



       GLCall(glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr));
        glfwPollEvents();
        glfwSwapBuffers(mainWindow);
    }

    glfwTerminate();
}