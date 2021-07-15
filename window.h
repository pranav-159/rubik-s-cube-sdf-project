#ifndef _WINDOW_
#define _WINDOW_
#include <GLFW/glfw3.h>
#include "rotator.h"
GLFWwindow* init_window();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window,Rotator*& rot,unsigned& viewIndex,bool& KEY,bool& CAM_KEY);

#endif