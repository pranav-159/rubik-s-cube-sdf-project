#include <glad/glad.h>
#include <iostream>
#include <array>
#include <GL/gl.h>
#include "shader.h"
#include "shaderPrograms.h"

/**
 * @brief Creates a Draw Program object
 * 
 * @return unsigned int handle of the program.
 */
unsigned int createDrawProgram()
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

unsigned int createCoverDrawProgram()
{
    unsigned int coverDrawProgram =glCreateProgram();
    unsigned int coververtexShader = createAndCompileShaderFromFile(GL_VERTEX_SHADER,"coverVertexShader");
    unsigned int covergeometryShader = createAndCompileShaderFromFile(GL_GEOMETRY_SHADER,"coverGeometryShader");
    unsigned int coverfragmentShader =createAndCompileShaderFromFile(GL_FRAGMENT_SHADER,"coverFragmentShader");
    glAttachShader(coverDrawProgram,coververtexShader);
    glAttachShader(coverDrawProgram,covergeometryShader);
    glAttachShader(coverDrawProgram,coverfragmentShader);
    glLinkProgram(coverDrawProgram);

    checkProgramLinkStatus(coverDrawProgram);

    glDeleteShader(coververtexShader);
    glDeleteShader(covergeometryShader);
    glDeleteShader(coverfragmentShader);

    return coverDrawProgram;
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
std::array<float, 54> launchDetectingProgram(unsigned int detectingShaderProgram, unsigned int VAO,TestCondition cond)
{

    glUseProgram(detectingShaderProgram);
    setUniform(detectingShaderProgram, "cond", cond);

    glBindVertexArray(0);

    unsigned int TBO;
    glGenBuffers(1, &TBO);
    glBindBuffer(GL_ARRAY_BUFFER, TBO);
    glBufferData(GL_ARRAY_BUFFER, 54 * sizeof(float), nullptr, GL_STATIC_READ);

    glEnable(GL_RASTERIZER_DISCARD);

    glBindVertexArray(VAO);
    glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, TBO);

    glBeginTransformFeedback(GL_POINTS);
    glDrawArrays(GL_POINTS, 0, 54);
    glEndTransformFeedback();

    glDisable(GL_RASTERIZER_DISCARD);

    std::array<float, 54> tfData;
    glGetBufferSubData(GL_TRANSFORM_FEEDBACK_BUFFER, 0, sizeof(tfData), (void *)&tfData[0]);
    glDeleteBuffers(1, &TBO);
    return tfData;
}
unsigned int launchTransformingProgram(unsigned int transformingProgram, unsigned int vao, unsigned int tbo, const glm::mat4& model,const std::array<float, 54>& feedback)
{
    glUseProgram(transformingProgram);
    setUniform(transformingProgram, "model", model);
    setUniform(transformingProgram, "feedback", feedback);
    glBindVertexArray(vao);
    glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, tbo);
    glEnable(GL_RASTERIZER_DISCARD);
    glBeginTransformFeedback(GL_POINTS);
    glDrawArrays(GL_POINTS, 0, 54);
    glEndTransformFeedback();
    glDisable(GL_RASTERIZER_DISCARD);
    return tbo;
}
void launchDrawProgram(unsigned int drawProgram,unsigned int vao,const glm::mat4& model,const glm::mat4& view,const glm::mat4& projection,const std::array<float,54>& feedback)
{
    glUseProgram(drawProgram);
    setUniform(drawProgram,"TL",TL);
    setUniform(drawProgram,"model",model);
    setUniform(drawProgram,"view",view);
    setUniform(drawProgram,"projection",projection);
    setUniform(drawProgram,"feedback",feedback);
    glBindVertexArray(vao);
    // glDrawArrays(GL_POINTS,12,2);
    // glDrawArrays(GL_POINTS,37,1);
    // glDrawArrays(GL_POINTS,40,1);
    // glDrawArrays(GL_POINTS,43,1);
    // glDrawArrays(GL_POINTS,27,9);
    glDrawArrays(GL_POINTS,0,54);
}

void launchCoverDrawProgram(unsigned int coverDrawProgram,unsigned int vao,glm::mat4&model,const glm::mat4&view,const glm::mat4& projection)
{
    glUseProgram(coverDrawProgram);
    setUniform(coverDrawProgram,"TL",TL);
    setUniform(coverDrawProgram,"model",model);
    setUniform(coverDrawProgram,"view",view);
    setUniform(coverDrawProgram,"projection",projection);
    glBindVertexArray(vao);
    glDrawArrays(GL_POINTS,0,2);
}