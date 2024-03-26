#pragma once
#include "renderer.h"

class IndexBuffer
{

private:
    GLuint IndexBufferID;
    unsigned int count;
public:
    IndexBuffer(const void* data, unsigned int count);
    ~IndexBuffer();

    void Bind();
    void Unbind();

    unsigned int getCount();

};