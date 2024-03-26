#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, GLuint size){

    GLCall(glGenBuffers(1, &VertexBufferID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));

}

VertexBuffer::~VertexBuffer(){
    GLCall(glDeleteBuffers(1,&VertexBufferID))
}

void VertexBuffer::Bind(){
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID));
}

void VertexBuffer::Unbind(){
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}