#include"opengl.h"

/**
 * Here we have a call back function which calls the suitable functions to change the view of the cube
 * **/

void key_callback(GLFWwindow *window, unsigned normal_key, int modifier_key){
	options_t tempOptionsObj;
	if(modifier_key == GLFW_MOD_SHIFT){
		//Add all the functions related to extra options like rotate right , undo etc..
		std::cout<<"Shift key is pressed \n";
		//tempOptionsObj.rotateRight();
	}
	if(modifier_key == GLFW_MOD_ALT){
		//Add all the functions related to movement options 
		std::cout<<"Alt key is pressed \n";
	}
}

void scroll_callback(GLFWwindow *window, double xoffset , double yoffset){
	options_t tempOptionsObj;
	if(yoffset < 0 ){
	std::cout<<"Size is increased \n";
	tempOptionsObj.increaseCubesize();
	}
	else if(yoffset > 0){
	std::cout<<"Size is decreased \n";
	tempOptionsObj.decreaseCubesize();
	}
}

void options_t::increaseCubesize(){
	tempDataObj.cubeSize = tempDataObj.cubeSize + 25.0f ;
	tempDataObj.setVertices();
}

void options_t::decreaseCubesize(){
	tempDataObj.cubeSize = tempDataObj.cubeSize - 25.0f ;
	tempDataObj.setVertices();
}

