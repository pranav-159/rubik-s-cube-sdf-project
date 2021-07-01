#include"opengl.h"

/**
 * Here we have a call back function which calls the suitable functions to change the view of the cube
 * **/

options_t* options_t::instance;
options_t* options_t::getOptionsInstance(){
	if(instance == NULL) instance = new options_t;
	return instance;
}

void key_callback(GLFWwindow *window, unsigned normal_key, int modifier_key){
	//options_t tempOptionsObj;
	if(modifier_key == GLFW_MOD_SHIFT){
		//Add all the functions related to extra options like rotate right , undo etc..
		//tempOptionsObj.rotateRight();
	}
	if(modifier_key == GLFW_MOD_ALT){
		//Add all the functions related to movement options 
	}
}

void scroll_callback(GLFWwindow *window, double xoffset , double yoffset){
	options_t* optionsInstance = options_t::getOptionsInstance();
	if(yoffset < 0 ){
		optionsInstance->decreaseCubesize();
		std::cout<<"Decreasing size\n";
	}
	else if(yoffset > 0){
		optionsInstance->increaseCubesize();
		std::cout<<"Increasing size\n";
	}
}

void options_t::increaseCubesize(){
	//tempDataObj.cubeSize = tempDataObj.cubeSize + 25.0f ;
	//data::cubeSize = data::cubeSize + 25.0f;
	tempDataObj.tempCubeSize = tempDataObj.tempCubeSize + 25.0f;
	tempDataObj.equateCUbes();
	//tempDataObj.buildCube();
	data::buildCube();
	std::cout<<data::splitCube[0][0][0].yCord<<std::endl;
	std::cout<<data::filledCube[2]<<std::endl;
	std::cout<<data::cubeSize<<std::endl;
}

void options_t::decreaseCubesize(){
	//tempDataObj.cubeSize = tempDataObj.cubeSize - 25.0f ;
	//data::cubeSize = data::cubeSize - 25.0f;
	tempDataObj.tempCubeSize = tempDataObj.tempCubeSize - 25.0f;
	tempDataObj.equateCUbes();
	//tempDataObj.buildCube();
	data::buildCube();
	std::cout<<data::splitCube[0][0][0].yCord<<std::endl;
	std::cout<<data::filledCube[2]<<std::endl;
}

