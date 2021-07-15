#include "camera.h"

glm::mat4 Camera::createViewMatrix(unsigned index){
        return glm::lookAt(_eye[index],_target,_up);
}

Camera::Camera(float len){
        _eye[0]=glm::vec3(-len,-len,+len);
        _eye[1]=glm::vec3(+len,-len,+len);
        _eye[5]=glm::vec3(+len,-len,-len);
        _eye[4]=glm::vec3(-len,-len,-len);
        _eye[2]=glm::vec3(-len,+len,+len);
        _eye[3]=glm::vec3(+len,+len,+len);
        _eye[7]=glm::vec3(+len,+len,-len);
        _eye[6]=glm::vec3(-len,+len,-len);
        
}