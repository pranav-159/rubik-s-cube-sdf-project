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
	//Reason for bug:
	//Here we need to just swap the colours of the pieces rather than the position coordinates of peices
#if 0
	for(unsigned j : peiceNumbers){
		for(unsigned i=0; i<4; i++){
			glm::vec4 tempVector(data::splitCube[data::choice-1][j][i].xCord,data::splitCube[data::choice-1][j][i].yCord,
					data::splitCube[data::choice-1][j][i].zCord,1.0f);
			tempVector = movePeices* tempVector ;
			data::splitCube[data::choice -1][j][i].xCord = tempVector.x;
			data::splitCube[data::choice -1][j][i].yCord = tempVector.y;
			data::splitCube[data::choice -1][j][i].zCord = tempVector.z;
	}
}
#endif
	for(unsigned i=0;i<9;i++){
		swapColors(peiceNumbers.at(i),peiceNumbers.at(i+3));
		printf("\n");
	}
	data::buildCube();
}

/*
 * Here for leftDown function we need to rotate the left face and 12 pieces about the x axis
 * for other functions we need to just change the movepeices and peiceNumbers vector
 * */
void movement_t::swapColors(const unsigned x, const unsigned y){
	for(unsigned j=0;j<4;j++){
		std::swap(tempMoveObj.splitCube[data::choice-1][x][j].rCol,tempMoveObj.splitCube[data::choice-1][y][j].rCol);
		std::swap(tempMoveObj.splitCube[data::choice-1][x][j].gCol,tempMoveObj.splitCube[data::choice-1][y][j].gCol);
		std::swap(tempMoveObj.splitCube[data::choice-1][x][j].bCol,tempMoveObj.splitCube[data::choice-1][y][j].bCol);
	}
	std::cout<<"Swapped "<<x<<" and "<<y<<" ; ";
	std::cout<<"Now color of " << x <<"th peice is " <<tempMoveObj.splitCube[data::choice-1][x][0].rCol<<" : "<<tempMoveObj.splitCube[data::choice-1][x][0].gCol<<" : "<<tempMoveObj.splitCube[data::choice-1][x][0].bCol<<std::endl;
}

void movement_t::leftDown(){
	angleDeg = -90.0f;
	rotateAbout = glm::vec3 (1.0f,0.0f,0.0f);
	peiceNumbers = {0,3,6,36,39,42,26,23,20,45,48,51};
	for(unsigned i=27; i<36; i++) peiceNumbers.push_back(i);
	move();
}

void movement_t::rightDown(){
	angleDeg = 90.0f;
	rotateAbout = glm::vec3(1.0f,0.0f,0.0f);
	peiceNumbers = {2,5,8,38,41,44,24,21,18,47,50,53};
	for(unsigned i=9;i<18;i++) peiceNumbers.push_back(i);
	move();
}

void movement_t::topLeft(){
	angleDeg = 90.0f;
	rotateAbout = glm::vec3(0.0f,1.0f,0.0f);
	peiceNumbers = {0,1,2,27,28,29,18,19,20,9,10,11};
	for(unsigned i=36;i<45;i++) peiceNumbers.push_back(i);
	move();
}

void movement_t::bottomLeft(){
	angleDeg = 90.0f;
	rotateAbout = glm::vec3(0.0f,1.0f,0.0f);
	peiceNumbers = {6,7,8,15,16,17,24,25,26,33,34,35};
	for(unsigned i=45;i<54;i++) peiceNumbers.push_back(i);
	move();
}


void movement_t::verticalMiddleDown(){
	peiceNumbers = {1,4,7,37,40,43,25,22,19,46,49,52};
	move();
}

void movement_t::horizontalMiddleLeft(){
	peiceNumbers = {3,4,5,30,31,32,21,22,23,12,13,14};
	move();
}

/*This function will call some rotate functions 20 times randomly each time , a program runs*/
void movement_t::shuffle(){
	std::srand(time(0));
	for(unsigned i=0;i<20;i++){
	switch( rand() % NOMOVEMENTS){
		case 0 : leftDown();  break;
		case 1 : rightDown(); break;
		case 3 : topLeft(); break;
		case 4 : bottomLeft(); break;
		case 5 : verticalMiddleDown(); break;
		case 6 : horizontalMiddleLeft();
	}
	}
}
