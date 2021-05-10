#include"opengl.h"

int main(){

    GLFWwindow* window = init_window();//creating a window
    if(window == NULL) std::cout<<"Error in creating the window \n";

    //callback functions


    glfwSetScrollCallback(window,options_t::scroll_callback);
    glfwSetCharModsCallback(window,options_t::rotate_callback);

    unsigned shader_program = shader_t::get_shader_program_id(); //getting shader id

    //creating all types of objects

    unsigned VAO,VBO,EBO;

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);
    

    //bind all objects to the buffer

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);



    init_buffer();



    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);
        glBindVertexArray(VAO);
        
        //It takes the indices that are loaded into the buffer
        glDrawElements(GL_TRIANGLES,indices_size(),GL_UNSIGNED_INT,0);
        /*
        *
        *
        *  write your code here  
        * 
        *
        */

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }





    
    //deleting all kind of objects

    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&EBO);
    glDeleteProgram(shader_program);

    glfwTerminate();

    return 0;

    
}