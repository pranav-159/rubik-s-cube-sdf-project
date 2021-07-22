#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <array>
#include <GL/gl.h>
#include "shader.h"
#include "shaderPrograms.h"
#include <algorithm>

/**
 * @brief Creates a Draw Program object
 * 
 * @return unsigned int handle of the program.
 */
unsigned int createDrawProgram()
{
    unsigned int drawShaderProgram = glCreateProgram();
    unsigned int vertexShader = createAndCompileShaderFromFile(GL_VERTEX_SHADER, "drawShaders/vertexShader");
    unsigned int geometryShader = createAndCompileShaderFromFile(GL_GEOMETRY_SHADER, "drawShaders/geometryShader");
    unsigned int fragmentShader = createAndCompileShaderFromFile(GL_FRAGMENT_SHADER, "drawShaders/fragmentShader");
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
unsigned createInstructionDrawProgram(){
    unsigned InstructionProgram = glCreateProgram();
    unsigned int vertexShader = createAndCompileShaderFromFile(GL_VERTEX_SHADER, "textureShaders/textureVertexShader");
    unsigned int fragmentShader = createAndCompileShaderFromFile(GL_FRAGMENT_SHADER, "textureShaders/textureFragmentShader");
    glAttachShader(InstructionProgram, vertexShader);
    glAttachShader(InstructionProgram, fragmentShader);
    glLinkProgram(InstructionProgram);
    checkProgramLinkStatus(InstructionProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return InstructionProgram;

}
/**
 * @brief Create a Cover Draw Program object
 * 
 * @return unsigned int handle to the program
 */
unsigned int createCoverDrawProgram()
{
    unsigned int coverDrawProgram =glCreateProgram();
    unsigned int coververtexShader = createAndCompileShaderFromFile(GL_VERTEX_SHADER,"coverShaders/coverVertexShader");
    unsigned int covergeometryShader = createAndCompileShaderFromFile(GL_GEOMETRY_SHADER,"coverShaders/coverGeometryShader");
    unsigned int coverfragmentShader =createAndCompileShaderFromFile(GL_FRAGMENT_SHADER,"coverShaders/coverFragmentShader");
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

/**
 * @brief checks the link status of a program and handles error messages
 * 
 * @param handle program handle
 * @return true if link is successful
 * @return false if link is not successful
 */
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
/**
 * @brief Create a Detecting Program object
 * 
 * @return unsigned int program handle
 */
unsigned int createDetectingProgram()
{
    unsigned program = glCreateProgram();
    unsigned vertexShader = createAndCompileShaderFromFile(GL_VERTEX_SHADER, "detectingShaders/RotatingTileDetectingShader");
    glAttachShader(program, vertexShader);
    const char *feedBackVaryings[] = {"result"};
    glTransformFeedbackVaryings(program, 1, feedBackVaryings, GL_INTERLEAVED_ATTRIBS);
    glLinkProgram(program);
    checkProgramLinkStatus(program);
    return program;
}
/**
 * @brief Create a Transforming Program object
 * 
 * @return unsigned int program handle
 */
unsigned int createTransformingProgram()
{
    unsigned int program = glCreateProgram();
    unsigned int vertexShader = createAndCompileShaderFromFile(GL_VERTEX_SHADER, "transformShaders/vertexTransformingShader");
    glAttachShader(program, vertexShader);
    const char *feedbackVaryings[] = {"pos", "norm", "col"};
    glTransformFeedbackVaryings(program, 3, feedbackVaryings, GL_INTERLEAVED_ATTRIBS);
    glLinkProgram(program);
    checkProgramLinkStatus(program);
    return program;
}
/**
 * @brief launches and detects the particular tile coordinates which need to be rotated
 * 
 * @param detectingShaderProgram program used to detect rotating tiles
 * @param VAO vertex array buffer of the tile coordinates
 * @param cond input condition specific for rotating tiles
 * @return std::array<float, 54> an array of 0's and 1's saying whether the tile satisfy the cond
 */
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
/**
 * @brief transforms the vertex co-ordinates and normals which are rotated
 * 
 * @param transformingProgram shader program which is used for transforming vertex coordinates and normals 
 * @param vao vertex array object containing the required vertices
 * @param tbo transform buffer which takes the new vertex coords after transformation
 * @param model model matrix which is used to transform vertex coordinates and normals
 * @param feedback array containing 0's and 1's representing which tiles should be rotated
 * @return unsigned int handle of vertex buffer containing the transformed coordinates
 */
std::array<float,54*9> launchTransformingProgram(unsigned int transformingProgram, unsigned int vao, unsigned int tbo, const glm::mat4& model,const std::array<float, 54>& feedback)
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
    std::array<float,54*9> feed;
    glGetBufferSubData(GL_TRANSFORM_FEEDBACK_BUFFER,0,54*9*sizeof(float),(void*)&(feed[0]));
    
    return feed;
}
/**
 * @brief launches and draws the tiles of the cube
 * 
 * @param drawProgram shader program which is used to draw the tile
 * @param vao vertex array buffer containing the data of the vertices
 * @param model model matrix for the program
 * @param view view matrix for the program
 * @param projection projection matrix
 * @param feedback contains data whether tile to be rotated or not
 */
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
/**
 * @brief launches and draws the black covers while rotating which blocks the internal of cube to be seen
 * 
 * @param coverDrawProgram shader program which is used to draw cover
 * @param vao containing data of centre points of covers
 * @param model model matrix 
 * @param view view matrix
 * @param projection projection matrix;
 */
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