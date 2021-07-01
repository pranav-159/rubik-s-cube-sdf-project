#include"opengl.h"

//choice_t data::choice;
unsigned data::choice;
float data::filledCube[6*216];
float data::cubeSize = 300.0f; //We change this in options_t class inorder to zoom the cube

/*
 * we need a single array to render the cube so we copy all the splits into an array and send that into buffer
 * */

void data::buildCube(){
    for (unsigned j = 0; j < 54; j++) {
      for (unsigned i = 0; i < 4; i++) {
        filledCube[6* i + 24 * j] 	   = splitCube[choice-1][j][i].xCord;
        filledCube[6 * i + 24 * j + 1] = splitCube[choice-1][j][i].yCord;
        filledCube[6 * i + 24 * j + 2] = splitCube[choice-1][j][i].zCord;
        filledCube[6 * i + 24 * j + 3] = splitCube[choice-1][j][i].rCol;
        filledCube[6 * i + 24 * j + 4] = splitCube[choice-1][j][i].gCol;
        filledCube[6 * i + 24 * j + 5] = splitCube[choice-1][j][i].bCol;
      }
    }
}

void data::equateCUbes(){
	cubeSize = tempCubeSize;
}



struct vectorCord data::splitCube[static_cast<int>(choice_t::noCubes)][54][4] = {
//front face green color {{{

		  0.0f,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
	cubeSize/3,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
	cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
		  0.0f,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

	cubeSize/3,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
  2*cubeSize/3,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
  2*cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
	cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

  2*cubeSize/3,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
	  cubeSize,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
	  cubeSize,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
  2*cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

		  0.0f,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
	cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
	cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
		  0.0f,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

	cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
  2*cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
  2*cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
	cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

  2*cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
	  cubeSize,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
	  cubeSize,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
  2*cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

		  0.0f,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
	cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
	cubeSize/3,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,
		  0.0f,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,

	cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
  2*cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
  2*cubeSize/3,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,
	cubeSize/3,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,

  2*cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
	  cubeSize,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
	  cubeSize,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,
  2*cubeSize/3,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,

//right face yellow color

	  cubeSize,      cubeSize,      cubeSize,  1.0f, 1.0f, 0.0f,
	  cubeSize,      cubeSize,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,  2*cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,  2*cubeSize/3,      cubeSize,  1.0f, 1.0f, 0.0f,

	  cubeSize,      cubeSize,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,      cubeSize,    cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,  2*cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,  2*cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,

	  cubeSize,      cubeSize,    cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,      cubeSize,          0.0f,  1.0f, 1.0f, 0.0f,
	  cubeSize,  2*cubeSize/3,          0.0f,  1.0f, 1.0f, 0.0f,
	  cubeSize,  2*cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,

	  cubeSize,  2*cubeSize/3,      cubeSize,  1.0f, 1.0f, 0.0f,
	  cubeSize,  2*cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,    cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,    cubeSize/3,      cubeSize,  1.0f, 1.0f, 0.0f,

	  cubeSize,  2*cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,  2*cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,    cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,    cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,

	  cubeSize,  2*cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,  2*cubeSize/3,          0.0f,  1.0f, 1.0f, 0.0f,
	  cubeSize,    cubeSize/3,          0.0f,  1.0f, 1.0f, 0.0f,
	  cubeSize,    cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,

	  cubeSize,    cubeSize/3,      cubeSize,  1.0f, 1.0f, 0.0f,
	  cubeSize,    cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,          0.0f,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,          0.0f,      cubeSize,  1.0f, 1.0f, 0.0f,

	  cubeSize,    cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,    cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,          0.0f,    cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,          0.0f,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,

	  cubeSize,    cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
	  cubeSize,    cubeSize/3,          0.0f,  1.0f, 1.0f, 0.0f,
	  cubeSize,          0.0f,          0.0f,  1.0f, 1.0f, 0.0f,
	  cubeSize,          0.0f,    cubeSize/3,  1.0f, 1.0f, 0.0f,

//back face blue color

	  cubeSize,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
  2*cubeSize/3,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
  2*cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
	  cubeSize,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,

  2*cubeSize/3,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
	cubeSize/3,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
	cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
  2*cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,

	cubeSize/3,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
		  0.0f,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
		  0.0f,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
	cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,

	  cubeSize,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
  2*cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
  2*cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
	  cubeSize,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,

  2*cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
	cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
	cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
  2*cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,

	cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
		  0.0f,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
		  0.0f,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
	cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f, 

	  cubeSize,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
  2*cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
  2*cubeSize/3,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f,
	  cubeSize,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f,

  2*cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
	cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
	cubeSize/3,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f,
  2*cubeSize/3,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f,

	cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
		  0.0f,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
		  0.0f,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f,
	cubeSize/3,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f, 

//left face white color

		  0.0f,     cubeSize,           0.0f,   1.0f, 1.0f, 1.0f,
		  0.0f,     cubeSize,     cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f, 2*cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f, 2*cubeSize/3,           0.0f,   1.0f, 1.0f, 1.0f,

		  0.0f,     cubeSize,     cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,     cubeSize,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f, 2*cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f, 2*cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,

		  0.0f,     cubeSize,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,     cubeSize,       cubeSize,   1.0f, 1.0f, 1.0f,
		  0.0f, 2*cubeSize/3,       cubeSize,   1.0f, 1.0f, 1.0f,
		  0.0f, 2*cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,

		  0.0f, 2*cubeSize/3,           0.0f,   1.0f, 1.0f, 1.0f,
		  0.0f, 2*cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,   cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,   cubeSize/3,           0.0f,   1.0f, 1.0f, 1.0f,

		  0.0f, 2*cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f, 2*cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,   cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,   cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,

		  0.0f, 2*cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f, 2*cubeSize/3,       cubeSize,   1.0f, 1.0f, 1.0f,
		  0.0f,   cubeSize/3,       cubeSize,   1.0f, 1.0f, 1.0f,
		  0.0f,   cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
		  
		  0.0f,   cubeSize/3,           0.0f,   1.0f, 1.0f, 1.0f,
		  0.0f,   cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,         0.0f,     cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,         0.0f,           0.0f,   1.0f, 1.0f, 1.0f,

		  0.0f,   cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,   cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,         0.0f,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,         0.0f,     cubeSize/3,   1.0f, 1.0f, 1.0f,

		  0.0f,   cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
		  0.0f,   cubeSize/3,       cubeSize,   1.0f, 1.0f, 1.0f,
		  0.0f,         0.0f,       cubeSize,   1.0f, 1.0f, 1.0f,
		  0.0f,         0.0f,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,

//top face red colour

		  0.0f,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
	cubeSize/3,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
	cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
		  0.0f,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,

	cubeSize/3,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
  2*cubeSize/3,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
  2*cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
	cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,

  2*cubeSize/3,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
	  cubeSize,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
	  cubeSize,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
  2*cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,

		  0.0f,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
	cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
	cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
		  0.0f,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,

	cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
  2*cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
  2*cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
	cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,

  2*cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
	  cubeSize,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
	  cubeSize,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
  2*cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
		  
		  0.0f,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
	cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
	cubeSize/3,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,
		  0.0f,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,

	cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
  2*cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
  2*cubeSize/3,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,
	cubeSize/3,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,

  2*cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
	  cubeSize,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
	  cubeSize,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,
  2*cubeSize/3,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,

//bottom face

		  0.0f,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
	cubeSize/3,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
	cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
		  0.0f,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,

	cubeSize/3,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
  2*cubeSize/3,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
  2*cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
	cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,

  2*cubeSize/3,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
	  cubeSize,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
	  cubeSize,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
  2*cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,

		  0.0f,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
	cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
	cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
		  0.0f,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,

	cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
  2*cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
  2*cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
	cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,

  2*cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
	  cubeSize,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
	  cubeSize,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
  2*cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
		  
		  0.0f,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
	cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
	cubeSize/3,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f,
		  0.0f,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f,

	cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
  2*cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
  2*cubeSize/3,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f,
	cubeSize/3,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f,

  2*cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
	  cubeSize,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
	  cubeSize,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f,
  2*cubeSize/3,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f,/*}}}*/

  //front face green color 
/*{{{*/
              0.0f,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
        cubeSize/3,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
        cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
              0.0f,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

        cubeSize/3,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
      2*cubeSize/3,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
      2*cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
        cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

      2*cubeSize/3,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
          cubeSize,      cubeSize,      cubeSize,  0.0f, 1.0f, 0.0f,
          cubeSize,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
      2*cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

              0.0f,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
        cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
        cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
              0.0f,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

        cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
      2*cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
      2*cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
        cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

      2*cubeSize/3,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
          cubeSize,  2*cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
          cubeSize,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
      2*cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,

              0.0f,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
        cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
        cubeSize/3,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,
              0.0f,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,

        cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
      2*cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
      2*cubeSize/3,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,
        cubeSize/3,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,

      2*cubeSize/3,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
          cubeSize,    cubeSize/3,      cubeSize,  0.0f, 1.0f, 0.0f,
          cubeSize,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,
      2*cubeSize/3,          0.0f,      cubeSize,  0.0f, 1.0f, 0.0f,

    //right face yellow color

          cubeSize,      cubeSize,      cubeSize,  1.0f, 1.0f, 0.0f,
          cubeSize,      cubeSize,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,  2*cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,  2*cubeSize/3,      cubeSize,  1.0f, 1.0f, 0.0f,

          cubeSize,      cubeSize,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,      cubeSize,    cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,  2*cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,  2*cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
    
          cubeSize,      cubeSize,    cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,      cubeSize,          0.0f,  1.0f, 1.0f, 0.0f,
          cubeSize,  2*cubeSize/3,          0.0f,  1.0f, 1.0f, 0.0f,
          cubeSize,  2*cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,

          cubeSize,  2*cubeSize/3,      cubeSize,  1.0f, 1.0f, 0.0f,
          cubeSize,  2*cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,    cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,    cubeSize/3,      cubeSize,  1.0f, 1.0f, 0.0f,

          cubeSize,  2*cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,  2*cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,    cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,    cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
    
          cubeSize,  2*cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,  2*cubeSize/3,          0.0f,  1.0f, 1.0f, 0.0f,
          cubeSize,    cubeSize/3,          0.0f,  1.0f, 1.0f, 0.0f,
          cubeSize,    cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,

          cubeSize,    cubeSize/3,      cubeSize,  1.0f, 1.0f, 0.0f,
          cubeSize,    cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,          0.0f,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,          0.0f,      cubeSize,  1.0f, 1.0f, 0.0f,

          cubeSize,    cubeSize/3,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,    cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,          0.0f,    cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,          0.0f,  2*cubeSize/3,  1.0f, 1.0f, 0.0f,
    
          cubeSize,    cubeSize/3,    cubeSize/3,  1.0f, 1.0f, 0.0f,
          cubeSize,    cubeSize/3,          0.0f,  1.0f, 1.0f, 0.0f,
          cubeSize,          0.0f,          0.0f,  1.0f, 1.0f, 0.0f,
          cubeSize,          0.0f,    cubeSize/3,  1.0f, 1.0f, 0.0f,

    //back face blue color

          cubeSize,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
      2*cubeSize/3,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
      2*cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
          cubeSize,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,

      2*cubeSize/3,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
        cubeSize/3,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
        cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
      2*cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,

        cubeSize/3,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
              0.0f,      cubeSize,          0.0f,  0.0f, 0.0f, 1.0f,
              0.0f,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
        cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,

          cubeSize,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
      2*cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
      2*cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
          cubeSize,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,

      2*cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
        cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
        cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
      2*cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,

        cubeSize/3,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
              0.0f,  2*cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
              0.0f,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
        cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f, 

          cubeSize,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
      2*cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
      2*cubeSize/3,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f,
          cubeSize,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f,

      2*cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
        cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
        cubeSize/3,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f,
      2*cubeSize/3,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f,

        cubeSize/3,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
              0.0f,    cubeSize/3,          0.0f,  0.0f, 0.0f, 1.0f,
              0.0f,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f,
        cubeSize/3,          0.0f,          0.0f,  0.0f, 0.0f, 1.0f, 

    //left face white color

              0.0f,     cubeSize,           0.0f,   1.0f, 1.0f, 1.0f,
              0.0f,     cubeSize,     cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f, 2*cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f, 2*cubeSize/3,           0.0f,   1.0f, 1.0f, 1.0f,

              0.0f,     cubeSize,     cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,     cubeSize,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f, 2*cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f, 2*cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,

              0.0f,     cubeSize,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,     cubeSize,       cubeSize,   1.0f, 1.0f, 1.0f,
              0.0f, 2*cubeSize/3,       cubeSize,   1.0f, 1.0f, 1.0f,
              0.0f, 2*cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,

              0.0f, 2*cubeSize/3,           0.0f,   1.0f, 1.0f, 1.0f,
              0.0f, 2*cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,   cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,   cubeSize/3,           0.0f,   1.0f, 1.0f, 1.0f,

              0.0f, 2*cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f, 2*cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,   cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,   cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,

              0.0f, 2*cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f, 2*cubeSize/3,       cubeSize,   1.0f, 1.0f, 1.0f,
              0.0f,   cubeSize/3,       cubeSize,   1.0f, 1.0f, 1.0f,
              0.0f,   cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
              
              0.0f,   cubeSize/3,           0.0f,   1.0f, 1.0f, 1.0f,
              0.0f,   cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,         0.0f,     cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,         0.0f,           0.0f,   1.0f, 1.0f, 1.0f,

              0.0f,   cubeSize/3,     cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,   cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,         0.0f,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,         0.0f,     cubeSize/3,   1.0f, 1.0f, 1.0f,

              0.0f,   cubeSize/3,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,
              0.0f,   cubeSize/3,       cubeSize,   1.0f, 1.0f, 1.0f,
              0.0f,         0.0f,       cubeSize,   1.0f, 1.0f, 1.0f,
              0.0f,         0.0f,   2*cubeSize/3,   1.0f, 1.0f, 1.0f,

    //top face red colour

              0.0f,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
        cubeSize/3,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
        cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
              0.0f,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,

        cubeSize/3,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
      2*cubeSize/3,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
      2*cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
        cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,

      2*cubeSize/3,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
          cubeSize,     cubeSize,            0.0f,   1.0f, 0.0f, 0.0f,
          cubeSize,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
      2*cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,

              0.0f,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
        cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
        cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
              0.0f,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,

        cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
      2*cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
      2*cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
        cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,

      2*cubeSize/3,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
          cubeSize,     cubeSize,      cubeSize/3,   1.0f, 0.0f, 0.0f,
          cubeSize,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
      2*cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
              
              0.0f,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
        cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
        cubeSize/3,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,
              0.0f,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,

        cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
      2*cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
      2*cubeSize/3,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,
        cubeSize/3,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,

      2*cubeSize/3,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
          cubeSize,     cubeSize,    2*cubeSize/3,   1.0f, 0.0f, 0.0f,
          cubeSize,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,
      2*cubeSize/3,     cubeSize,        cubeSize,   1.0f, 0.0f, 0.0f,

    //bottom face

              0.0f,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
        cubeSize/3,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
        cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
              0.0f,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,

        cubeSize/3,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
      2*cubeSize/3,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
      2*cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
        cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,

      2*cubeSize/3,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
          cubeSize,         0.0f,        cubeSize,   1.0f, 0.0f, 1.0f,
          cubeSize,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
      2*cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,

              0.0f,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
        cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
        cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
              0.0f,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,

        cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
      2*cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
      2*cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
        cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,

      2*cubeSize/3,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
          cubeSize,         0.0f,    2*cubeSize/3,   1.0f, 0.0f, 1.0f,
          cubeSize,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
      2*cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
              
              0.0f,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
        cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
        cubeSize/3,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f,
              0.0f,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f,

        cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
      2*cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
      2*cubeSize/3,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f,
        cubeSize/3,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f,

      2*cubeSize/3,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
          cubeSize,         0.0f,      cubeSize/3,   1.0f, 0.0f, 1.0f,
          cubeSize,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f,
      2*cubeSize/3,         0.0f,            0.0f,   1.0f, 0.0f, 1.0f/*}}}*/
	};
