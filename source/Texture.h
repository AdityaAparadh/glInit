#pragma once
#include "renderer.h"

class Texture
{

private:
    GLuint TextureID;
    std::string filePath;
    GLint width, height, bitsPerPixel;
    unsigned char* textureData;
    int channels;

public:
    Texture(const std::string& path, int channels);
    ~Texture();

    void Bind();
    void Unbind();

    int getWidth();
    int getHeight();

};