#ifndef _DATA_
#define _DATA_

/**
 * 
 * This file contains only the data used in making cubes
 * The data used here is just an example, we need to carefully calculate the points and modify the arrays below accordingly
 * Whatever changes we make via function calls, the changes are applied on the shuffledFaces array and then it is copied
 * to shuffled array and then to vertices array which is used to render cube
 * 
 * changes to be done :
 * 	1. It would be better to make shuffledFaces and shuffled static
 * 	2. It would be better to make a 3d matrix shuffledFaces instead of two seperate arrays : shuffledFaces and patternFaces
 * 
 * **/
struct vectorCord{
	float xCord, yCord, zCord, rCol, gCol, bCol;
};//Need to use this struct effectively inorder to make less changes while building movements

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
    void setVertices();

};


#endif
