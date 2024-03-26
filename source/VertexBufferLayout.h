#pragma once
#include <unordered_map>
#include <vector>

#include "renderer.h"

struct VertexBufferElement
{
    unsigned int type;
    int count;
    bool normalized;
};

class VertexBufferLayout{

public:
    int singleSize;
    std::vector<VertexBufferElement> Elements;
    VertexBufferLayout();

    void PushFloat( int Count );
    void PushInt( int Count );
    void PushUInt( int Count );
    void PushUByte( int Count );



};