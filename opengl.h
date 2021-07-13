#ifndef _OPENGL_
#define _OPENGL_

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stack>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "data.h"
#define PI 3.14159265359




GLFWwindow* init_window();

//CallBackfunctions
void key_callback(GLFWwindow *window, unsigned normal_key, int modifier_key);//Defined in options.cpp file
void processInput(GLFWwindow *window); //Defined in window.cpp file
void framebuffer_size_callback(GLFWwindow* window, int width, int height);//Defined in window.cpp file

//a singleton class because we should have only one shader
//This class creates the shaders and atlast what we want is the id of shader program created

class shader_t{
    private:
    static unsigned shader_program_id;
    shader_t();
    static void set_shaders();
    public:
    static unsigned get_shader_program_id();
};


// In this atlast we want the size of indices to render the cube
class set_buffer{
    public:
    set_buffer()=default;
    static unsigned indices[NOPEICES][6];
	static GLsizei indices_size();

/**
 * It loads (saves) the data in to the buffer that is binded to GPU
*/
	static void init_buffer();
};


//This class takes care of additional options 
class options_t{
private:
	static options_t* instance;
	options_t()=default;
	glm::mat4 scale= glm::mat4(1.0f);
public:
	static options_t* getOptionsInstance();
	void rotateRight();

};



//we should have only one history maintainer and one set ofmovement matrix
//hence it is better to use singleton here
class movement_t{
private:
	static movement_t* Instance;
	static std::stack<unsigned>history;
	movement_t()=default;
	glm::mat4 movePeices = glm::mat4(1.0f); //rotation matrix
public:
	std::vector<unsigned>peiceNumbers;
	float angleDeg;
	glm::vec3 rotateAbout;
	//need to add the actual movement matrices here
	static movement_t* getInstance();
	void move();
	void oppositeDirection();
	void leftUp();
	void undo_option();
};

#endif
