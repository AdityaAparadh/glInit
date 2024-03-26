#include "VertexBufferLayout.h"

VertexBufferLayout::VertexBufferLayout()
{
    singleSize=  0;
}

void VertexBufferLayout::PushFloat(int Count)
{
    struct VertexBufferElement floats = {GL_FLOAT, Count, false};
    Elements.push_back(floats);
    singleSize += sizeof(GL_FLOAT)*Count;
}
void VertexBufferLayout::PushInt(int Count)
{
    struct VertexBufferElement ints = {GL_INT, Count, false};
    Elements.push_back(ints);
    singleSize += sizeof(GL_INT)*Count;
}
void VertexBufferLayout::PushUInt(int Count)
{
    struct VertexBufferElement uints = {GL_UNSIGNED_INT, Count, false};
    Elements.push_back(uints);
    singleSize += sizeof(GL_UNSIGNED_INT)*Count;
}
void VertexBufferLayout::PushUByte(int Count)
{
    struct VertexBufferElement ubytes = {GL_UNSIGNED_BYTE, Count, false};
    Elements.push_back(ubytes);
    singleSize += sizeof(GL_UNSIGNED_BYTE)*Count;
}


