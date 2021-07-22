#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <array>
#include "shader.h"
#include "shaderPrograms.h"
#include "vertexInitializer.h"
#include "window.h"
#include "camera.h"
#include <thread>
#include <chrono>
#include <stb_image.h>

extern float TL;
float TL = 2.0f;

int main()
{
    GLFWwindow *window = init_window(); //creating a window
    if (window == NULL)
        std::cout << "Error in creating the window \n";

    unsigned int drawshaderProgram = createDrawProgram();
    unsigned int detectingshaderProgram = createDetectingProgram();
    unsigned int transformingshaderProgram = createTransformingProgram();
    unsigned int coverDrawProgram = createCoverDrawProgram();
    unsigned int instructionProgram =createInstructionDrawProgram();


    std::array<float, 54> feedback;
    std::array<float, 6> coverPoints;
    std::array<float, 54 * 9> vertexData;
    glm::mat4 projection, view, model = glm::mat4(1.0f);
    Rotator *rot;
    VertexInitializer vertexInit;

    vertexInit.setTL(TL);

    vertexInit.randomPopulator(vertexData);
    int no_of_buffers = 2;
    unsigned int vbo[no_of_buffers];
    unsigned int vao[no_of_buffers];
    glGenVertexArrays(no_of_buffers, vao);
    glGenBuffers(no_of_buffers, vbo);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    for (int i = 0; i < no_of_buffers; i++)
    {
        glBindVertexArray(vao[i]);

        glBindBuffer(GL_ARRAY_BUFFER, vbo[i]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), &vertexData[0], GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }

    glBindVertexArray(0);

   
    float vertices[] = {
        // positions          // colors           // texture coords
         1.0f,1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f, // top right
         1.0f,-1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f, // bottom right
        -1.0f,-1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f, // bottom left
        -1.0f,1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   1.0f, 0.0f  // top left 
    };
    unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    unsigned int vbo2, vao2, ebo2;
    glGenVertexArrays(1, &vao2);
    glGenBuffers(1, &vbo2);
    glGenBuffers(1, &ebo2);

    glBindVertexArray(vao2);

    glBindBuffer(GL_ARRAY_BUFFER, vbo2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

        // load and create a texture 
    // -------------------------
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *data = stbi_load("textures/projectInstructions.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    std::cout<<width<<" "<<height<<" "<<nrChannels<<std::endl;

    rot = new Rotator(Face::DOWN, Turn::CLOCKWISE, Stack::FIRST);
    
    unsigned int vao1;
    unsigned int vbo1;
    glGenVertexArrays(1, &vao1);
    glGenBuffers(1, &vbo1);
    glBindVertexArray(vao1);
    glBindBuffer(GL_ARRAY_BUFFER, vbo1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(coverPoints), NULL, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    
    glBindVertexArray(0);

    
    
    projection=glm::perspective(120.0f,800.0f/800.0f,0.1f,30.0f);
    // projection = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 1.0f, 100.0f);
    Camera cam(5 * TL);
    view = cam.createViewMatrix();
    unsigned viewIndex = 3;
    //buffer rotation
    int draw_buffer = 0;
    //timer timings
    bool GAME_KEY = false;
    bool CAM_KEY = false;
    bool KEY = false;
    float time = 0.0f;
    float now, delta = 0.0f, previous = glfwGetTime();
    int setter = 1;
    int setter1=1;
    float process_time = 0.4f;
    while (!glfwWindowShouldClose(window))
    {

        // input
        // -----
        processInput(window, rot, viewIndex, KEY,CAM_KEY,GAME_KEY);

        if(GAME_KEY){   
            if(setter1--)
            {
                glEnable(GL_DEPTH);
                glEnable(GL_DEPTH_TEST);
                glfwSetWindowSize(window,600, 600);
            }    
            view = cam.createViewMatrix(viewIndex);

            //render
            //------
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            if (KEY)
            {
                now = glfwGetTime();
                delta = now - previous;

                if (setter)
                {
                    delta = 0.0f;
                    if (rot->getStack() != Stack::WHOLE)
                    {
                        feedback = launchDetectingProgram(detectingshaderProgram, vao[draw_buffer], rot->conditionTransformer());
                        coverPoints = rot->coverPoints();
                        glBindVertexArray(0);
                        glBindBuffer(GL_ARRAY_BUFFER, vbo1);
                        glBufferData(GL_ARRAY_BUFFER, sizeof(coverPoints), (void *)&coverPoints[0], GL_DYNAMIC_DRAW);
                    }
                    else
                    {
                        feedback.fill(1);
                    }

                    setter--;
                }

                previous = now;
                time += delta;
                if (time <= process_time)
                {
                    model = glm::mat4(1.0f);
                    model = rot->rotateMatrixCreator(glm::half_pi<float>() * time / process_time);
                    if (rot->getStack() != Stack::WHOLE)
                        launchCoverDrawProgram(coverDrawProgram, vao1, model, view, projection);
                }
                else
                {

                    model = rot->rotateMatrixCreator(glm::half_pi<float>());

                    launchTransformingProgram(transformingshaderProgram, vao[draw_buffer], vbo[(draw_buffer + 1) % no_of_buffers], model, feedback);
                    delta = 0.0f;
                    setter = 1;
                    time = 0.0f;
                    draw_buffer = (draw_buffer + 1) % no_of_buffers;
                    model = glm::mat4(1.0f);
                    KEY = false;
                }
            }
            
            launchDrawProgram(drawshaderProgram, vao[draw_buffer], model, view, projection, feedback);

            // glfw: swap buffers and poll IO events (KEYs pressed/released, mouse moved etc.)
            // -------------------------------------------------------------------------------
            glfwSwapBuffers(window);
            if(CAM_KEY)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                CAM_KEY=false;
            }   
        }
        else
        {
           // ------
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // draw our first triangle
            glBindTexture(GL_TEXTURE_2D,texture);
            glUseProgram(instructionProgram);
            glm::mat4 view2d=glm::lookAt(glm::vec3(0.0f,0.0f,-1.0f),glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f));
            setUniform(instructionProgram,"view",view2d);
            glBindVertexArray(vao2); // seeing as we only have a single vao2 there's no need to bind it every time, but we'll do so to keep things a bit more organized
            // glDrawArrays(GL_TRIANGLES, 0, 3);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            // glBindVertexArray(0); // no need to unbind it every time 
    
            // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
            // -------------------------------------------------------------------------------
            glfwSwapBuffers(window); 
        }
        
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(no_of_buffers, vao);
    glDeleteVertexArrays(no_of_buffers, &vao1);
    glDeleteBuffers(no_of_buffers, &vbo1);
    glDeleteBuffers(1, &vbo1);
    glDeleteProgram(drawshaderProgram);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}
