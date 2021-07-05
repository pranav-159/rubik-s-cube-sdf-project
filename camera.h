#ifndef _CAMERA_
#define _CAMERA_
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
extern float TL;

class Camera{
    glm::vec3 eye=glm::vec3(4.0f,4.0f,4.0f);
    glm::vec3 target=glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 up=glm::vec3(0.0f,1.0f,0.0f);
    public:
    glm::mat4 viewMatrixCreator(int TL){
        return glm::lookAt(eye,target,up);
    }
}; 

#endif