#include <glad/glad.h>
#include <GL/gl.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "shader.h"
#include "rotator.h"
#include <string>
#include <array>
/**
 * @brief compiles glsl shader from the file specified
 * 
 * @param type type of the shader compiling.
 * @param name name of the file
 */
 int createAndCompileShaderFromFile(unsigned int type,char const* name){
  
    unsigned int handle=glCreateShader(type);
    std::ifstream shaderFile;
    std::stringstream shaderStream;
    std::string shaderCode;
    const char* shaderSource;

    shaderFile.exceptions(std::fstream::failbit|std::fstream::badbit);
    try{
        shaderFile.open(name);
        shaderStream<<shaderFile.rdbuf();   
        shaderFile.close();  
        shaderCode=shaderStream.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cout<<"ERROR::SHADER::FILE_NOT_SUCESSFULLY_READ"<<std::endl;
    }
    shaderSource=shaderCode.c_str(); 
    glShaderSource(handle,1,&shaderSource,NULL);
    glCompileShader(handle);
    
    const char* shaderType;
    if(type==GL_VERTEX_SHADER)
        shaderType="vertex";
    else if(type==GL_GEOMETRY_SHADER)
        shaderType="geometry";
    else if(type==GL_FRAGMENT_SHADER)
        shaderType="fragment";    
    
    int success;
    glGetShaderiv(handle,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        int length;
        glGetShaderiv(handle,GL_INFO_LOG_LENGTH,&length);
        char* message=(char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(handle,length,&length,message);

        std::cerr<<"Failed to compile "<<shaderType<<" shader"<<std::endl;
        std::cerr<<message<<std::endl;
        
    }

    return handle;
    
}


/**
 * @brief Sets the Uniform object(matrix 4 dimensions)
 * 
 * @param program program id/handle
 * @param name name of the uniform
 * @param matrix matrix which you want to set the object to.
 */
void setUniform(unsigned int program,const char* name,const glm::mat4& matrix)
{
    glUniformMatrix4fv( glGetUniformLocation(program, name), 1, GL_FALSE, glm::value_ptr(matrix) );
}
/**
 * @brief Sets the Uniform object(float)
 * 
 * @param program program id/handle
 * @param name name of the uniform
 * @param matrix matrix which you want to set the object to.
 */
void setUniform(unsigned int program,const char* name,float TL)
{
    glUniform1f(glGetUniformLocation(program,name),TL);
}
void setUniform(unsigned int program,const char* name,const TestCondition& cond)
{
    std::string str_name =name;
    glUniform1i(glGetUniformLocation(program,(str_name+".axis").c_str()),cond.axis);
    glUniform1f(glGetUniformLocation(program,(str_name+".plane1").c_str()),cond.plane1);
    glUniform1f(glGetUniformLocation(program,(str_name+".plane2").c_str()),cond.plane2);
}
void setUniform(unsigned int program,const char* name,TestCondition&& cond)
{
    std::string str_name =name;
    glUniform1i(glGetUniformLocation(program,(str_name+".axis").c_str()),cond.axis);
    glUniform1f(glGetUniformLocation(program,(str_name+".plane1").c_str()),cond.plane1);
    glUniform1f(glGetUniformLocation(program,(str_name+".plane2").c_str()),cond.plane2);

}
void setUniform(unsigned int program,const char* name,std::array<float,54> feedback)
{
    std::string str_name=name;
    for(int i=0;i<54;i++)
    {
        glUniform1f(glGetUniformLocation(program,(str_name+"["+std::to_string(i)+"]").c_str()),feedback[i]);
    }
}
