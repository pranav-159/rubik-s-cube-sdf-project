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
    // glShadeModel(GL_SMOOTH);   // Enable smooth shading
    // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

    // build and compile our shader program

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------

    std::array<float, 54> feedback;
    std::array<float, 6> coverPoints;
    std::array<float, 54 * 9> vertexData;
    glm::mat4 projection, view, model = glm::mat4(1.0f);
    Rotator *rot;
    VertexInitializer vertexInit;

    vertexInit.setTL(TL);

    vertexInit.vertexPopulator(vertexData);
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

    rot = new Rotator(Face::DOWN, Turn::CLOCKWISE, Stack::FIRST);
    rot = new Rotator(Face::FRONT, Turn::ANTI_CLOCKWISE, Stack::FIRST);
    // feedback=launchDetectingProgram(detectingshaderProgram,vao[0],rot->conditionTransformer());

    // coverPoints=rot->coverPoints();
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

    // std::cout<<sizeof(feedback)<<std::endl;
    // for(int i=0;i<54;i++)
    // {
    //     std::cout<<feedback[i]<<" ";
    // }
    // std::cout<<std::endl;

    glBindVertexArray(0);

    glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_TEST);
    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // for(int i=0;i<54;i++)
    // {
    //     std::cout<<i<<" ";
    //     for(int j=0;j<3;j++)
    //     {
    //         for(int k=0;k<3;k++)
    //         {
    //         std::cout<<(float)vertexData.at(9*i+3*j+k)<<" ";
    //         }
    //         std::cout<<"  ";
    //     }
    //     std::cout<<std::endl;
    // }
    // for(int i=0;i<2;i++)
    // {
    //     std::cout<<i<<" ";
    //     for(int j=0;j<3;j++)
    //         std::cout<<coverPoints[3*i+j];
    //     std::cout<<std::endl;
    // }
    // projection=glm::perspective(90.0f,800.0f/800.0f,3.0f,30.0f);
    projection = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 1.0f, 100.0f);
    Camera cam(2.5 * TL);
    view = cam.createViewMatrix();
    unsigned viewIndex = 3;
    //buffer rotation
    int draw_buffer = 0;
    //timer timings
    bool CAM_KEY = false;
    bool KEY = false;
    float time = 0.0f;
    float now, delta = 0.0f, previous = glfwGetTime();
    int setter = 1;
    float process_time = 0.5f;
    while (!glfwWindowShouldClose(window))
    {

        // input
        // -----
        processInput(window, rot, viewIndex, KEY,CAM_KEY);
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
