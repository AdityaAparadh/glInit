#pragma once
#include "renderer.h"

class VertexBuffer
{

private:
    GLuint VertexBufferID;

public:
    VertexBuffer(const void* data, GLuint size);
    ~VertexBuffer();

    void Bind();
    void Unbind();

};