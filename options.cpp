/*TODO
 * 1. Add undo option,
 * 2. Add the opposite directoins to the rotations
 * 3. Add an option to move between 3d(perspective) and 2d(orthographic) modes.
 * */
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
		}
		if(normal_key == 'D'){
			options->rotateDown();
		}
	}
	if(modifier_key == GLFW_MOD_ALT){
		//Add all the functions related to movement options 
		if(normal_key == 'l'){
			movementInstance->leftDown();
		}
		else if(normal_key == 'r'){
			movementInstance->rightDown();
		}
		else if(normal_key == 'u'){
			movementInstance->topLeft();
		}
		else if(normal_key == 'd'){
			movementInstance->bottomLeft();
		}
		else if(normal_key == 'v'){
			movementInstance->verticalMiddleDown();
		}
		else if(normal_key == 'h'){
			movementInstance->horizontalMiddleLeft();
		}
		else if(normal_key == 's'){
			movementInstance->shuffle();
		}
		else if(normal_key == 'f'){
			movementInstance->frontClockwise();
		}
		else if(normal_key == 'b'){
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

//For zooming in and out
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
	static float scaleFactor=1;
	glm::mat4 zoom = glm::mat4(1.0f);
	if(yoffset>0) scaleFactor = scaleFactor*1.25; 
	else scaleFactor = scaleFactor*0.75;
	zoom = glm::scale(zoom,glm::vec3(scaleFactor,scaleFactor,scaleFactor));
	unsigned scaleLoc = glGetUniformLocation(shader_t::get_shader_program_id(),"scale");
    glUniformMatrix4fv(scaleLoc, 1, GL_FALSE, glm::value_ptr(zoom));
}

//For getting different views of the cube by moving the mouse
void mouse_callback(GLFWwindow* window,int button, int action, int mods){
	if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
		options_t::getOptionsInstance()->differentAngle();
	}
}

/*This function will be called when there is a mouse click on the -ve end position of the cube*/
void options_t::differentAngle(){
		if(cameraStatus == 0){
			cameraPos = glm::vec3(-2.0f,0.0f,2.0f);
			cameraStatus = 1;
		}
		else if(cameraStatus == 1){
			cameraPos = glm::vec3(-2.0f,0.0f,-2.0f);
			cameraStatus = 2;
		}
		else if(cameraStatus == 2){
			cameraPos = glm::vec3(2.0f,0.0f,-2.0f);
			cameraStatus = 3;
		}
		else if(cameraStatus == 3){
			cameraPos = glm::vec3(2.0f,0.0f,2.0f);
			cameraStatus = 4;
		}
		else if(cameraStatus == 4){
			cameraPos = glm::vec3(0.0f,0.0f,2.0f);
			cameraStatus = 0;
		}
}
