#ifndef _SHADERPROGRAMS_
#define _SHADERPROGRAMS_
extern float TL;

bool checkProgramLinkStatus(unsigned int handle);

unsigned int createDrawProgram();
unsigned int createDetectingProgram();
unsigned int createTransformingProgram();
unsigned int createCoverDrawProgram();
unsigned int createInstructionDrawProgram();

std::array<float,54> launchDetectingProgram(unsigned int detectingShaderProgram,unsigned int VAO,TestCondition cond);
std::array<float,54*9> launchTransformingProgram(unsigned int transformingProgram,unsigned int vao,unsigned int tbo,const glm::mat4& model,const std::array<float,54>& feedback); 
void launchDrawProgram(unsigned int drawProgram,unsigned int vao,const glm::mat4& model,const glm::mat4& view,const glm::mat4& projection,const std::array<float,54>& feedback);
void launchCoverDrawProgram(unsigned int coverDrawProgram,unsigned int vao,glm::mat4&model,const glm::mat4&view,const glm::mat4& projection);
#endif