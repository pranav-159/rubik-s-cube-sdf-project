#include"opengl.h"

/**
 * This file  Should contain all the matrix that are used for transformation or movement of cube and we use a stack to
 * maintain the history of movments
 * **/

std::stack<std::function<void()>> movement_t::history;
movement_t* movement_t::Instance;

movement_t* movement_t::getInstance(){
	if(Instance == NULL) Instance = new movement_t;
	return Instance;
}


/*
 * This function multiplies the rotate matrix to the elements of the vector(a class memeber) which
 * contains the index number of the piece that we want to rotate 
 * */
void movement_t::move(){
	movePeices = glm::rotate(movePeices,glm::radians(angleDeg),rotateAbout);
	for(unsigned j : peiceNumbers){
		for(unsigned i=0; i<4; i++){
			glm::vec4 tempVector(data::splitCube[data::choice-1][j][i].xCord,data::splitCube[data::choice-1][j][i].yCord,
					data::splitCube[data::choice-1][j][i].zCord,1.0f);
			tempVector = tempVector * movePeices;
			data::splitCube[data::choice -1][j][i].xCord = tempVector.x;
			data::splitCube[data::choice -1][j][i].yCord = tempVector.y;
			data::splitCube[data::choice -1][j][i].zCord = tempVector.z;
	}
}
	data::buildCube();
}


/*
 * Check these functions carefully later 
 * */

/*
 * Here for leftUp function we need to rotate the left face and 12 pieces about the x axis
 * for other functions we need to just change the movepeices and peiceNumbers vector
 * */

void movement_t::leftUp(){
	angleDeg = -90.0f;
	rotateAbout = glm::vec3 (1.0f,0.0f,0.0f);
	peiceNumbers = {0,3,6,36,39,42,20,23,26,45,48,51};
	for(unsigned i=27; i<36; i++) peiceNumbers.push_back(i);
	move();
}

void movement_t::rightUp(){
	angleDeg = 90.0f;
	rotateAbout = glm::vec3(1.0f,0.0f,0.0f);
	peiceNumbers = {2,5,8,38,41,44,47,50,53,18,21,24};
	for(unsigned i=9;i<18;i++) peiceNumbers.push_back(i);
	move();
}

void movement_t::topRight(){
	angleDeg = 90.0f;
	rotateAbout = glm::vec3(0.0f,1.0f,0.0f);
	peiceNumbers = {0,1,2,9,10,11,18,19,20,27,28,29};
	for(unsigned i=36;i<45;i++) peiceNumbers.push_back(i);
	move();
}

void movement_t::bottomRight(){
	angleDeg = 90.0f;
	rotateAbout = glm::vec3(0.0f,1.0f,0.0f);
	peiceNumbers = {6,7,8,15,16,17,24,25,26,33,34,35};
	for(unsigned i=45;i<54;i++) peiceNumbers.push_back(i);
	move();
}

/*This function will call some rotate functions 20 times randomly each time , a program runs*/
void movement_t::shuffle(){
	std::srand(time(0));
	for(unsigned i=0;i<20;i++){
	switch( rand() % NOMOVEMENTS){
		case 0 : leftUp();  break;
		case 1 : rightUp(); break;
		case 3 : topRight(); break;
		case 4 : bottomRight(); break;
	}
	}
}
