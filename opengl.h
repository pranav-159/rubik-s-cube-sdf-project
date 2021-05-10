#ifndef _OPENGL_
#define _OPENGL_

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
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

void init_buffer();

GLsizei indices_size ();

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
static void rotate_callback(GLFWwindow *window, unsigned normal_key, int modifier_key);
};



#endif