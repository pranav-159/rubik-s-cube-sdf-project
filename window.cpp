#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include <iostream>
#include <fstream>
#include "rotator.h"
#include <bitset>
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
void processInput(GLFWwindow *window,Rotator* & rot,unsigned & viewIndex,bool& KEY,bool& CAM_KEY)
{
    //general closing
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    //rubiks stack movement
    if(glfwGetKey(window,GLFW_KEY_LEFT_SHIFT)!=GLFW_PRESS)
    {
        if(glfwGetKey(window,GLFW_KEY_X)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_Y)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_Z)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_L)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_C)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_R)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_B)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_H)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_F)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_U)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_M)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_D)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
    }
    if(glfwGetKey(window,GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS && KEY ==false)
    {
        if(glfwGetKey(window,GLFW_KEY_X)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::ANTI_CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_Y)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::ANTI_CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_Z)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::ANTI_CLOCKWISE,Stack::WHOLE);
            KEY=true;
        }
        if(glfwGetKey(window,GLFW_KEY_L)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::ANTI_CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_C)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::ANTI_CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_R)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::RIGHT,Turn::ANTI_CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_B)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::ANTI_CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_H)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::ANTI_CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_F)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::FRONT,Turn::ANTI_CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_U)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::ANTI_CLOCKWISE,Stack::FIRST);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_M)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::ANTI_CLOCKWISE,Stack::SECOND);
            KEY=true;
        }      
        if(glfwGetKey(window,GLFW_KEY_D)==GLFW_PRESS && KEY ==false)
        {
            delete rot;
            rot=new Rotator(Face::UP,Turn::ANTI_CLOCKWISE,Stack::THIRD);
            KEY=true;
        }      
    }
    //camera
        // static std::bitset<3> globe("011");
    // if(CAM_KEY==false)
    // {
    //     if(glfwGetKey(window,GLFW_KEY_UP)==GLFW_PRESS)
    //     {   
    //         if(globe[1]==false)
    //             globe.flip(1); 
    //         else
    //         {
    //             globe.flip(0);
    //             globe.flip(2);
    //         }  
    //         viewIndex=(unsigned)globe.to_ulong();   
    //         CAM_KEY=true;      
    //     }
    //     if(glfwGetKey(window,GLFW_KEY_DOWN)==GLFW_PRESS)
    //     {   
    //         if(globe[1]==true)
    //             globe.flip(1); 
    //         else
    //         {
    //             globe.flip(0);
    //             globe.flip(2);
    //         }  
    //         viewIndex=(unsigned)globe.to_ulong();     
    //         CAM_KEY=true;     
    //     }
    //     if(glfwGetKey(window,GLFW_KEY_RIGHT)==GLFW_PRESS)
    //     { 
    //         int num=globe[0]+globe[2];  
    //         if(num%2==0)
    //             globe.flip(0); 
    //         else
    //             globe.flip(2);
    //         viewIndex=(unsigned)globe.to_ulong();
    //         CAM_KEY=true;          
    //     }
    //     if(glfwGetKey(window,GLFW_KEY_LEFT)==GLFW_PRESS)
    //     { 
    //         std::ofstream myFile;
    //         int num=globe[0]+globe[2];  
    //         if(num%2==0)
    //             globe.flip(2); 
    //         else
    //             globe.flip(0);
    //         viewIndex=(unsigned)globe.to_ulong();    
    //         CAM_KEY=true;       
    //     }
    if(glfwGetKey(window,GLFW_KEY_LEFT_ALT)==GLFW_PRESS&& CAM_KEY==false)
    {
        viewIndex=(viewIndex==3)?4:3;
        CAM_KEY=true;
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}