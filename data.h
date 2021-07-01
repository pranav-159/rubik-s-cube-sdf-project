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
	static struct vectorCord splitCube[static_cast<int>(choice_t::noCubes)][54][4] ;
    static unsigned choice;
//	static choice_t choice;
	static void buildCube();
	float  tempCubeSize = 300.0f;
	void equateCUbes();

};


#endif
