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
		//Add all the functions related to extra options like rotate left , undo etc..
		if(normal_key == 'L'){
			options->rotateLeft();
			std::cout<<"Rotate right is called \n";
		}
		if(normal_key == 'D'){
			options->rotateDown();
			std::cout<<"Rotate down is called \n";
		}
	}
	if(modifier_key == GLFW_MOD_ALT){
		//Add all the functions related to movement options 
		if(normal_key == 'l'){
			std::cout<<"leftDown function is called \n";
			movementInstance->leftDown();
		}
		else if(normal_key == 'r'){
			std::cout<<"rightDown function is called \n";
			movementInstance->rightDown();
		}
		else if(normal_key == 'u'){
			std::cout<<"topLeft function is called \n";
			movementInstance->topLeft();
		}
		else if(normal_key == 'd'){
			std::cout<<"bottomLeft function is called \n";
			movementInstance->bottomLeft();
		}
		else if(normal_key == 'v'){
			std::cout<<"verticalMiddleDown function is called\n";
			movementInstance->verticalMiddleDown();
		}
		else if(normal_key == 'h'){
			std::cout<<"horizontalMiddleLeft function is called\n";
			movementInstance->horizontalMiddleLeft();
		}
		else if(normal_key == 's'){
			std::cout<<"shuffle function is called\n";
			movementInstance->shuffle();
		}
		else if(normal_key == 'f'){
			std::cout<<"frontClockwise is called \n";
			movementInstance->frontClockwise();
		}
		else if(normal_key == 'b'){
			std::cout<<"backClockwise is called \n";
			movementInstance->backClockwise();
		}
	}
}

void options_t::rotateLeft(){
	moveInstance->topLeft();
	moveInstance->horizontalMiddleLeft();
	moveInstance->bottomLeft();
}

void options_t::rotateDown(){
	moveInstance->leftDown();
	moveInstance->verticalMiddleDown();
	moveInstance->rightDown();
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
	static float scaleFactor=1;
	glm::mat4 zoom = glm::mat4(1.0f);
	if(yoffset>0) scaleFactor = scaleFactor*1.25; 
	else scaleFactor = scaleFactor*0.75;
	zoom = glm::scale(zoom,glm::vec3(scaleFactor,scaleFactor,scaleFactor));
	unsigned scaleLoc = glGetUniformLocation(shader_t::get_shader_program_id(),"scale");
    glUniformMatrix4fv(scaleLoc, 1, GL_FALSE, glm::value_ptr(zoom));
}

