#include"opengl.h"


/**
 * Should contain all the matrix that are used for transformation or movement of cube and we use a stack to maintain the history of movments
 * **/

std::stack<unsigned> movement_t::history;

//If you press a key then the function of that key should be performed  and the complementary key of that should be 
//stored into the stack. And when the undo option is called the top element on the stacl should be poped and that 
//particular function should be performed.
