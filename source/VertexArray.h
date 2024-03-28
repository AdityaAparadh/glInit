#pragma once
#include "renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray{

private:
    unsigned int VertexArrayID;
    int stride;
    int offset;

public:

    VertexArray();
    ~VertexArray();

    void AddBuffer( VertexBuffer& buffer, VertexBufferLayout& layout  );

};