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
	movement_t* movementInstance = movement_t::getInstance();
	options_t* options = options_t::getOptionsInstance();
	if(modifier_key == GLFW_MOD_SHIFT){
		//Add all the functions related to extra options like rotate right , undo etc..
		options->rotateRight();
		std::cout<<"Rotate right is called \n";
	}
	if(modifier_key == GLFW_MOD_ALT){
		//Add all the functions related to movement options 
		if(normal_key == 'l'){
			std::cout<<"leftUp function is called \n";
			movementInstance->leftUp();
		}
		else if(normal_key == 'r'){
			std::cout<<"rightUp function is called \n";
			movementInstance->rightUp();
		}
		else if(normal_key == 'u'){
			std::cout<<"topRight function is called \n";
			movementInstance->topRight();
		}
		else if(normal_key == 'b'){
			std::cout<<"bottomRight function is called \n";
			movementInstance->bottomRight();
		}
		else if(normal_key == 's'){
			std::cout<<"shuffle function is called\n";
			movementInstance->shuffle();
		}
	}
}


void options_t::rotateRight(){
	movement_t* movement = movement_t::getInstance();
	movement->angleDeg = 90.0f;
	movement->rotateAbout = glm::vec3 (0.0f,1.0f,0.0f);
	for(unsigned i=0 ; i<NOPEICES; i++) movement->peiceNumbers.push_back(i);
	movement->move();
}

