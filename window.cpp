#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include <iostream>
#include "rotator.h"
extern float TL;

GLFWwindow* init_window();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

GLFWwindow* init_window(){
        // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Rubik's Cube", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers--
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return NULL;
    }
    return window;
}

//call back functions

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window,Rotator* & rot,bool& KEY)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if(glfwGetKey(window,GLFW_KEY_LEFT_SHIFT)!=GLFW_PRESS)
    {
        if(glfwGetKey(window,GLFW_KEY_X)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_Y)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_Z)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_L)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_C)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_R)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_B)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_H)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_F)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_U)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_M)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_D)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
    }
    if(glfwGetKey(window,GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS)
    {
        if(glfwGetKey(window,GLFW_KEY_X)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::ANTI_CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_Y)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::ANTI_CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_Z)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::ANTI_CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_L)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::ANTI_CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_C)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::ANTI_CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_R)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::ANTI_CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_B)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::ANTI_CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_H)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::ANTI_CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_F)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::ANTI_CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_U)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::ANTI_CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_M)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::ANTI_CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_D)==GLFW_PRESS)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::ANTI_CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}