#include"opengl.h"

/**
 * This file  Should contain all the matrix that are used for transformation or movement of cube and we use a stack to maintain the history of movments
 * **/

std::stack<unsigned> movement_t::history;
movement_t* movement_t::Instance;

movement_t* movement_t::getInstance(){
	if(Instance == NULL) Instance = new movement_t;
	return Instance;
}


/*
 * This function multiplies the rotate matrix to the elements of the vector(a class memeber) which contains the index number of the piece
 * that we want to rotate 
 * */
void movement_t::move(){
	movePeices = glm::rotate(movePeices,glm::radians(angleDeg),rotateAbout);
	for(unsigned j : peiceNumbers){
		for(unsigned i=0; i<4; i++){
			glm::vec4 tempVector(data::splitCube[data::choice-1][j][i].xCord,data::splitCube[data::choice-1][j][i].yCord,data::splitCube[data::choice-1][j][i].zCord,1.0f);
			tempVector = tempVector * movePeices;
			data::splitCube[data::choice -1][j][i].xCord = tempVector.x;
			data::splitCube[data::choice -1][j][i].yCord = tempVector.y;
			data::splitCube[data::choice -1][j][i].zCord = tempVector.z;
	}
}
	data::buildCube();
}

/*
 * Here we need to rotate the left face and 12 pieces about the x axis
 * for other functions we need to just change the movepeices and peiceNumbers vector
 * */
void movement_t::leftUp(){
	angleDeg = -90.0f;
	rotateAbout = glm::vec3 (1.0f,0.0f,0.0f);
	peiceNumbers = {0,3,6,36,39,42,20,23,26,45,48,51};
	for(unsigned i=27; i<36; i++) peiceNumbers.push_back(i);
	move();
}
