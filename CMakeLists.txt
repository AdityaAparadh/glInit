cmake_minimum_required(VERSION 2.6)

project( Graphics )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw/)

add_library(GLAD STATIC
    external/glad/src/glad.c
)

find_package(OpenGL REQUIRED)

include_directories(external/glfw/include
external/glad/include
)

add_executable(
    Graphics
    main.cpp
    source/renderer.cpp
    source/VertexBuffer.cpp
    source/STBImplementation.cpp
    source/IndexBuffer.cpp
    source/Texture.cpp
    source/VertexBufferLayout.cpp
    source/VertexArray.cpp
    source/Shader.cpp
    )
    target_include_directories(Graphics PRIVATE external/glm)


target_link_libraries(  Graphics
                        glfw
                        OpenGL::GL
                        GLAD
                         )

