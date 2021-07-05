#ifndef SHADER_H
#define SHADER_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/gl.h>
#include <array>
#include "rotator.h"


int createAndCompileShaderFromFile(unsigned int type,char const* name);
void setUniform(unsigned int program,const char* name,const glm::mat4& matrix);
void setUniform(unsigned int program,const char* name,float TL);
void setUniform(unsigned int program,const char* name,const TestCondition& cond);
void setUniform(unsigned int program,const char* name,TestCondition&& cond);
void setUniform(unsigned int program,const char* name,std::array<float,54> feedback);

#endif