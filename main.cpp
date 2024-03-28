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

    // float vertices[] = {
    //     0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
    //     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
    //     -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    //     -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
    // };
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };



    // unsigned int indices[] = {0, 1, 2, 0, 2, 3};

    VertexBuffer vb(vertices, 180 * sizeof(float));
    // IndexBuffer ib(indices, 6);

    VertexBufferLayout layout;
    layout.PushFloat(3);
    // layout.PushFloat(3);
    layout.PushFloat(2);

    VertexArray VA1;
    VA1.AddBuffer(vb, layout);
    // ib.Bind();

    Shader s(   "../shaders/VertexShader.glsl", "../shaders/FragmentShader.glsl");
    s.useUniform4f("someColor",1.0f,0.0f,0.0f,1.0f);


    Texture t("../textures/block.png", 4);







    glm::mat4 viewMatrix = glm::mat4(1.0f);
    viewMatrix =    glm::translate(viewMatrix, glm::vec3(0.0f,0.0f,-3.0f));

    glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f),1.0f,0.1f,100.0f);

  //  glm::mat4 projectionMatrix = glm::ortho(-20.0f,20.0f,-20.0f,20.0f,-1.0f,1.0f);
    GLCall(glEnable(GL_DEPTH_TEST));
    while (!glfwWindowShouldClose(mainWindow))
    {
        processInput(mainWindow);
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
        GLCall(glClear(GL_DEPTH_BUFFER_BIT));


     glm::mat4 modelMatrix = glm::mat4(1.0f);
     modelMatrix = glm::rotate(modelMatrix, (float)glfwGetTime(),glm::vec3(1.0f, 1.0f, 0.0f));


        s.useUniformMatrix4fv("model",1, glm::value_ptr(modelMatrix));
        s.useUniformMatrix4fv("view",1, glm::value_ptr(viewMatrix));
        s.useUniformMatrix4fv("projection",1, glm::value_ptr(projectionMatrix));

        // GLCall(glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr));
        GLCall(glDrawArrays(GL_TRIANGLES,0,36));
        glfwPollEvents();
        glfwSwapBuffers(mainWindow);
    }

    glfwTerminate();
}
