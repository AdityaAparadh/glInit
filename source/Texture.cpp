#include "Texture.h"
#include "stb_image.h"

Texture::Texture(const std::string& path, int channels)
{
    filePath = path;
    TextureID = 0;
    textureData = nullptr;
    width = 0;
    height = 0;
    bitsPerPixel = 0;
    this->channels = channels;

    stbi_set_flip_vertically_on_load(true);

    textureData = stbi_load(filePath.c_str(),&width,&height,&bitsPerPixel, this->channels);

    GLCall( glGenTextures(1,&TextureID) );
    GLCall( glBindTexture(GL_TEXTURE_2D,TextureID));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));    


    GLCall( glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,textureData));
    GLCall( glGenerateMipmap( GL_TEXTURE_2D));
    
    GLCall( glBindTexture(GL_TEXTURE_2D, 0 ));
    GLCall( glBindTexture(GL_TEXTURE_2D, TextureID ));


    if ( textureData){
        stbi_image_free(textureData);
    }
}

Texture::~Texture(){
    GLCall( glDeleteTextures(1,&TextureID));
}

void Texture::Bind(){
    GLCall(glActiveTexture(GL_TEXTURE0 ));
    GLCall( glBindTexture(GL_TEXTURE_2D, TextureID ));
}

void Texture::Unbind(){
    GLCall( glBindTexture(GL_TEXTURE_2D, 0 ));
}