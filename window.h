#ifndef _WINDOW_
#define _WINDOW_
#include <GLFW/glfw3.h>
GLFWwindow* init_window();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

#endif