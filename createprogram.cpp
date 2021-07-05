#include "createprogram.h"
#include <glad/glad.h>
#include "shader.h"
#include <iostream>
#include <array>

unsigned int CreateProgram::createDrawProgram()
{

    unsigned int drawShaderProgram = glCreateProgram();
    unsigned int vertexShader = createAndCompileShaderFromFile(GL_VERTEX_SHADER, "vertexShader");
    unsigned int geometryShader = createAndCompileShaderFromFile(GL_GEOMETRY_SHADER, "geometryShader");
    unsigned int fragmentShader = createAndCompileShaderFromFile(GL_FRAGMENT_SHADER, "fragmentShader");
    glAttachShader(drawShaderProgram, vertexShader);
    glAttachShader(drawShaderProgram, geometryShader);
    glAttachShader(drawShaderProgram, fragmentShader);
    glLinkProgram(drawShaderProgram);
    checkProgramLinkStatus(drawShaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(geometryShader);
    glDeleteShader(fragmentShader);

    return drawShaderProgram;
}
bool checkProgramLinkStatus(unsigned int handle)
{

    int success;
    glGetProgramiv(handle, GL_LINK_STATUS, &success);
    if (!success)
    {
        int length;
        glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &length);
        char *message = (char *)alloca(length * sizeof(char));
        glGetProgramInfoLog(handle, length, &length, message);

        std::cerr << "Failed to link program" << std::endl;
        std::cerr << message << std::endl;
    }
    return success;
}
unsigned int createDetectingProgram()
{
    unsigned program = glCreateProgram();
    unsigned vertexShader = createAndCompileShaderFromFile(GL_VERTEX_SHADER, "RotatingTileDetectingShader");
    glAttachShader(program, vertexShader);
    const char *feedBackVaryings[] = {"result"};
    glTransformFeedbackVaryings(program, 1, feedBackVaryings, GL_INTERLEAVED_ATTRIBS);
    glLinkProgram(program);
    checkProgramLinkStatus(program);
    return program;
}
unsigned int createTransformingProgram()
{
    unsigned int program = glCreateProgram();
    unsigned int vertexShader = createAndCompileShaderFromFile(GL_VERTEX_SHADER, "vertexTransformingShader");
    glAttachShader(program, vertexShader);
    const char *feedbackVaryings[] = {"pos", "norm", "col"};
    glTransformFeedbackVaryings(program, 3, feedbackVaryings, GL_INTERLEAVED_ATTRIBS);
    glLinkProgram(program);
    checkProgramLinkStatus(program);
    return program;
}
