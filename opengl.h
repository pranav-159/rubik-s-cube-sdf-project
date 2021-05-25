#ifndef _OPENGL_
#define _OPENGL_

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stack>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "data.h"
#define PI 3.14159265359




GLFWwindow* init_window();

//a singleton class because we should have only one shader 

class shader_t{
    private:
    static unsigned shader_program_id;
    shader_t();
    static void set_shaders();
    public:
    static unsigned get_shader_program_id();
};



class set_buffer{
    public:
    //only this changes for its derived classes
    set_buffer()=default;
	float vertices[24*6] = {} ;

unsigned indices[36]={   
     0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4,
    8, 9, 10, 10, 11, 8,
    12, 13, 14, 14, 15, 12,
    16, 17, 18, 18, 19, 16,
    20, 21, 22, 22, 23, 20};
GLsizei indices_size();
/**
 * 
 * It loads (saves) the data in to the buffer that is binded 
 *   
*/
void init_buffer();


};



//call back functions

void processInput(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// On introducing the term static , we don't need to create seprate instances for the options_t class
//we can directly use the functions and I defined a class  to organize things

class options_t{
private:
static glm::mat4 transform_matrix ; 

public:
static void pass_transform_matrix();
static void scroll_callback(GLFWwindow *window, double xoffset , double yoffset);
static void key_callback(GLFWwindow *window, unsigned normal_key, int modifier_key);

};



//we should have only one history maintainer and one set ofmovement matrix
//hence it is better to use singleton here
class movement_t{
private:
	static movement_t* Instance;
	static std::stack<unsigned>history;
	movement_t()=delete;
public:
	//need to add the actual movement matrices here 
	static movement_t* getInstance();
	static void undo_option();
	//static void move_callback(GLFWwindow *window,unsigned unicode);
};
#endif
