#include "rotator.h"
#include <array>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "iostream"
#include <cmath>
#include <fstream>
/**
 * @brief Construct a new Rotator:: Rotator object which simplifies the input data into more mathematical interest
 * 
 * @param face_ Face with respective which we are rotating
 * @param turn_ whether it is clockwise or anticlockwise
 * @param stack_ whether it is total 3 stacks(whole) or seperate stacks with respective to us
 */
Rotator::Rotator(Face face_,Turn turn_,Stack stack_){        
    face=(int)face_;
    stack=(int)stack_;
    turn=2*(int)turn_-1;
    axis=2-face/2;
    if(stack_!=Stack::WHOLE)
    {
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
    else
    {
        plane1=-3*TL/2;
        plane2=3*TL/2;
    }
    
}
/**
 * @brief which transforms the input data into test condition.
 * 
 * @return TestCondition data redirected to shader program for detection
 */
TestCondition Rotator::conditionTransformer()
{
    

    TestCondition cond;

    cond.axis=axis;
    cond.plane1=plane1;
    cond.plane2=plane2;
   
   return cond; 
}
/**
 * @brief creates the model matrix for the rotation
 * 
 * @param angle how much angle to ratate the cube
 * @return glm::mat4 model matrix produced
 */
glm::mat4 Rotator::rotateMatrixCreator(float angle){

    glm::vec3 normal=rotatingAxis();
    glm::mat4 matrix=glm::mat4(1.0f);
    matrix=glm::rotate(matrix,angle,normal);
    // std::cout<<normal[0]<<" "<<normal[1]<<" "<<normal[2]<<" "<<plane1<< " "<<plane2<< " "<<stack<<std::endl;
    return matrix;
}
/**
 * @brief detects the rotating axis
 * 
 * @return glm::vec3 axis to be rotated around
 */
glm::vec3 Rotator::rotatingAxis(){
    glm::vec3 normal;
    normal[axis]=turn*(1-2*(face%2))*1.0f;
    normal[(axis+1)%3]=0.0f;
    normal[(axis+2)%3]=0.0f;
    return normal;
}
/**
 * @brief detects the centres of cover points
 * 
 * @return std::array<float,6> contains the two cover points if middle stack is rotating.
 * same point repeated twice if the corner stacks are rotating
 * nothing if the whole stack is rotating
 */
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
    else if(stack!=3)
    {
        float plane=fabs(plane1)>fabs(plane2)?plane2:plane1;
        arr[axis]=plane;
        arr[(axis+1)%3]=0.0f;
        arr[(axis+2)%3]=0.0f;
        arr[3+axis]=plane;
        arr[3+(axis+1)%3]=0.0f;
        arr[3+(axis+2)%3]=0.0f;
    }
    std::ofstream myFile;
    myFile.open("coverPoints.csv");
    myFile<<stack<<","<<plane1<<","<<plane2<<std::endl;
    myFile<<arr[0]<<","<<arr[1]<<","<<arr[2]<<std::endl;
    myFile<<arr[3]<<","<<arr[4]<<","<<arr[5]<<std::endl;
    return arr;
} 
/**
 * @brief returns the stack which we are rotating
 * 
 * @return Stack rotating Stack
 */
Stack Rotator::getStack(){
    return static_cast<Stack>(stack);
}