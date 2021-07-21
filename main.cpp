#include "opengl.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include "menu.h"

int main(){

  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!");
    
  Menu menu(window.getSize().x ,window.getSize().y);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      window.close();

      if(menu.getrect1().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
      {
        
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            GLFWwindow* window1 = init_window();//creating a window
            if(window1 == NULL) std::cout<<"Error in creating the window \n";

            //callback functions
            glfwSetCharModsCallback(window1,key_callback);
            glfwSetScrollCallback(window1,scroll_callback);



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

            while (!glfwWindowShouldClose(window1))
            {
              processInput(window1);

              glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    	      glEnable(GL_DEPTH);
		      glDepthFunc(GL_LESS);
              glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

              glUseProgram(shader_program);
              glBindVertexArray(VAO);

        
              glm::mat4 projection    = glm::mat4(1.0f);
		      glm::mat4 view			= glm::mat4(1.0f);
        
		      view = glm::lookAt(glm::vec3(0.0f,0.0f,2.0f),glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f));
		      projection = glm::ortho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);
              //projection = glm::perspective(60.0f, (float)800 / (float)600, 0.01f, 100.0f);
		      projection = projection * view;
              unsigned int projLoc  = glGetUniformLocation(shader_program,"projection");
              glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
              //It takes the indices that are loaded into the buffer
		      set_buffer::init_buffer();
              glDrawElements(GL_TRIANGLES,set_buffer::indices_size(),GL_UNSIGNED_INT,0);
              glfwSwapBuffers(window1);
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
      }
      if(menu.getrect2().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
      {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
          window.close();
        }
      }
    }
         
        window.clear();

        menu.draw(window);

        window.display();
  }

}
