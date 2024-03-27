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
void useUniform4f(std::string uniform, float f1, float f2, float f3, float f4);
    void useUniform4fv(std::string uniform,GLsizei size,const GLfloat* value);
};