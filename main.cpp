#include"opengl.h"




int main(int argc, char *argv[]){

	::testing::InitGoogleTest(&argc,argv);

    GLFWwindow* window = init_window();//creating a window
    if(window == NULL) std::cout<<"Error in creating the window \n";

    //callback functions
    glfwSetCharModsCallback(window,key_callback);
    glfwSetScrollCallback(window,scroll_callback);
	glfwSetMouseButtonCallback(window,mouse_callback);



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


	data::buildCube();
	options_t* optionsInstance=options_t::getOptionsInstance();



    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    	glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shader_program);
        glBindVertexArray(VAO);

        
        glm::mat4 projection    = glm::mat4(1.0f);
		glm::mat4 view			= glm::mat4(1.0f);
		glm::mat4 rotate		= glm::mat4(1.0f);
//		rotate = glm::rotate(rotate,glm::radians((float)glfwGetTime()*2), glm::vec3(1.0f,0.0f,0.0f));
        
		//Need to change this so that the user can get various kinds of views
		view = glm::lookAt(optionsInstance->cameraPos,optionsInstance->cameraTarget,optionsInstance->cameraUp);
//		projection = glm::ortho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);
		projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 1.0f, 5.0f);
		projection = projection * view * rotate;
        unsigned int projLoc  = glGetUniformLocation(shader_program,"projection");
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

    return RUN_ALL_TESTS();


    
}
