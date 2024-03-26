#include "VertexArray.h"

VertexArray::VertexArray(){
    stride = 0;
    offset = 0;
    GLCall(glGenVertexArrays(1, &VertexArrayID));
    GLCall(glBindVertexArray(VertexArrayID));
}

void VertexArray::AddBuffer( VertexBuffer& buffer, VertexBufferLayout& layout, IndexBuffer& iBuffer  ){

    buffer.Bind();
    iBuffer.Bind();

    for ( int i = 0 ; i < layout.Elements.size() ; i++ ){
        VertexBufferElement element = layout.Elements[i];
        GLCall( glVertexAttribPointer(i,element.count,element.type,element.normalized,layout.singleSize,(void*)((offset))));
        GLCall( glEnableVertexAttribArray(i) );
        // std::cout << "Set Offset to: " << offset << std::endl;
        offset += (sizeof(element.type))*(element.count);

    // std::cout << i << " " << element.count << " " << element.type << " " << element.normalized << " " << layout.singleSize << " " << offset << std::endl; 

    }

}

VertexArray::~VertexArray(){
    GLCall( glDeleteVertexArrays(1,&VertexArrayID));
}