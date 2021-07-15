#ifndef _CAMERA_
#define _CAMERA_
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
extern float TL;

class Camera{

    glm::vec3 _eye[8];
    glm::vec3 _target=glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 _up=glm::vec3(0.0f,1.0f,0.0f);
    public:
    Camera(float len);
    glm::mat4 createViewMatrix(unsigned index=3);
  
}; 

#endif