#ifndef _DATA_
#define _DATA_

/*
 * Changes to be made :
 * 1. Move the whole data into an external text, yml or json file to retain the state at which the user stopped
 * 2. Need to impliment the enum class properly 
 * */

struct vectorCord{
	float xCord, yCord, zCord, rCol, gCol, bCol;
};

enum class choice_t{shuffled, pattern, noCubes};

class data{
public:
    static float cubeSize;

    static float filledCube[216*6];

struct vectorCord splitCube[static_cast<int>(choice_t::noCubes)][54][4] = {
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

    static unsigned choice;
//	static choice_t choice;
	void buildCube();

};


#endif
