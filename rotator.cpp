#include "rotator.h"
#include <array>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "iostream"
#include <cmath>


Rotator::Rotator(Face face_,Turn turn_,Stack stack_){        
    face=(int)face_;
    stack=(int)stack_;
    turn=2*(int)turn_-1;
    axis=2-face/2;
    if(face%2)
    {
        plane1=-3*TL/2+stack*TL;
        plane2=-TL/2+stack*TL;
    }
    else
    {
        plane1=TL/2-stack*TL;
        plane2=3*TL/2-stack*TL;
    }
}

TestCondition Rotator::conditionTransformer()
{
    

    TestCondition cond;

    cond.axis=axis;
    cond.plane1=plane1;
    cond.plane2=plane2;
   
   return cond; 
}
glm::mat4 Rotator::rotateMatrixCreator(float angle){

    glm::vec3 normal=rotatingAxis();
    glm::mat4 matrix=glm::mat4(1.0f);
    matrix=glm::rotate(matrix,angle,normal);
    std::cout<<normal[0]<<" "<<normal[1]<<" "<<normal[2]<<" "<<plane1<< " "<<plane2<< " "<<stack<<std::endl;
    return matrix;
}
glm::vec3 Rotator::rotatingAxis(){
    glm::vec3 normal;
    normal[axis]=turn*(1-2*(face%2))*1.0f;
    normal[(axis+1)%3]=0.0f;
    normal[(axis+2)%3]=0.0f;
    return normal;
}
std::array<float,6> Rotator::coverPoints(){
    std::array<float,6> arr;
    if(stack==1)
    {
        arr[axis]=plane1;
        arr[(axis+1)%3]=0.0f;
        arr[(axis+2)%3]=0.0f;
        arr[3+axis]=plane2;
        arr[3+(axis+1)%3]=0.0f;
        arr[3+(axis+2)%3]=0.0f;
    }
    else
    {
        float plane=fabs(plane1)>fabs(plane2)?plane2:plane1;
        arr[axis]=plane;
        arr[(axis+1)%3]=0.0f;
        arr[(axis+2)%3]=0.0f;
        arr[3+axis]=plane;
        arr[3+(axis+1)%3]=0.0f;
        arr[3+(axis+2)%3]=0.0f;
    }
    return arr;
} 