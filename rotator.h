#ifndef _ROTATOR_
#define _ROTATOR_
#include <glm/glm.hpp>
#include <array>
extern float TL;

struct TestCondition{
    TestCondition(int axis_i,float plane1_i,float plane2_i)
    :axis(axis_i),plane1(plane1_i),plane2(plane2_i){}
    TestCondition(){}
    int axis;
    float plane1;
    float plane2;
};
enum class Face{FRONT,BACK,UP,DOWN,RIGHT,LEFT};
enum class Turn{CLOCKWISE,ANTI_CLOCKWISE};
enum class Stack{FIRST,SECOND,THIRD};


class Rotator{

    int face,turn,stack;
    int axis;
    float plane1,plane2;
    public:
    Rotator(Face face_,Turn turn_,Stack stack_);
    TestCondition conditionTransformer();
    glm::mat4 rotateMatrixCreator(float angle);
    glm::vec3 rotatingAxis();
    std::array<float,6> coverPoints();
    
};

#endif