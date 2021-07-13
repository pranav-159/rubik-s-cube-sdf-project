#ifndef _DATA_
#define _DATA_

#define NOPEICES 6*9
#define NODATAPOINTS 6*9*4*6

/*
 * Changes to be made :
 * 1. Move the whole data into an external text, yml or json file to retain the state at which the user stopped
 * 2. Need to impliment the enum class properly 
 * */

struct vectorCord{
	float xCord, yCord, zCord, rCol, gCol, bCol;
};

enum class choice_t{shuffled , noCubes};

class data{
public:
    static float cubeSize;

    static float filledCube[NODATAPOINTS];
	static struct vectorCord splitCube[static_cast<int>(choice_t::noCubes)][NOPEICES][4] ;
    static unsigned choice;
//	static choice_t choice;
	static void buildCube();
	void equateCUbes();

};


#endif
