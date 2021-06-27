#include"opengl.h"



int main(){

    GLFWwindow* window = init_window();//creating a window
    if(window == NULL) std::cout<<"Error in creating the window \n";

    //callback functions
   glfwSetScrollCallback(window,scroll_callback);
   glfwSetCharModsCallback(window,key_callback);



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


    data cubeData;
    std::cout<<"Please enter 1 to get a shuffledCube cube and 2 to get patterns of the cube \n";
    std::cin>>data::choice;
	cubeData.buildCube();
    glEnable(GL_DEPTH);



    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shader_program);
        glBindVertexArray(VAO);

        
        glm::mat4 projection    = glm::mat4(1.0f);
		glm::mat4 view  		= glm::mat4(1.0f);
        
         projection = glm::ortho( -500.0f, 500.0f, -500.0f, 500.0f, -500.0f, 500.0f);
		 view  = glm::translate(view, glm::vec3(- data::cubeSize/2 ,- data::cubeSize/2 ,- data::cubeSize/2  ));
		 //projection = glm::perspective(glm::radians(30.0f), (float)800 / (float)600, -1000.0f, 1000.0f);
         //retrieve the matrix uniform locations
        unsigned int projLoc  = glGetUniformLocation(shader_program,"projection");
        
		projection = projection*view;
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
        //It takes the indices that are loaded into the buffer
		set_buffer::init_buffer();
        glDrawElements(GL_TRIANGLES,set_buffer::indices_size(),GL_UNSIGNED_INT,0);
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
