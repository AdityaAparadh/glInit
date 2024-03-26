#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const void* data, unsigned int count){

    GLCall(glGenBuffers(1, &IndexBufferID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count* sizeof(unsigned int), data, GL_STATIC_DRAW))

}

IndexBuffer::~IndexBuffer(){
    GLCall(glDeleteBuffers(1,&IndexBufferID))
}

void IndexBuffer::Bind(){
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID));
}

void IndexBuffer::Unbind(){
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::getCount(){ return count;}