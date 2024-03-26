#include "renderer.h"

class Shader{

private:
    unsigned int shaderID;
    unsigned int CompileShader(unsigned int type, const std::string &shaderCode);
    unsigned int CreateShader(const std::string vertexShader, const std::string fragmentShader);
    std::string loadShader(std::string path);

    std::string vertexShaderCode;
    std::string fragmentShaderCode;

public:

Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
~Shader();
void useProgram();
};