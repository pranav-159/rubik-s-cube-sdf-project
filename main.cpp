#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <array>
#include "shader.h"
#include "shaderPrograms.h"
#include "vertexInitializer.h"
#include "window.h"
#include "input.h"

extern float TL;
float TL=1.0f;

int main()
{
    GLFWwindow* window = init_window();//creating a window
    if(window == NULL) std::cout<<"Error in creating the window \n";
    // glShadeModel(GL_SMOOTH);   // Enable smooth shading
    // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

    // build and compile our shader program
    unsigned int drawshaderProgram=createDrawProgram();
    unsigned int detectingshaderProgram=createDetectingProgram();
    unsigned int transformingshaderProgram=createTransformingProgram();
    unsigned int coverDrawProgram=createCoverDrawProgram();
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    std::array<float,54*9> vertexData;
    VertexInitializer vertexInit;
    vertexInit.setTL(TL);
    
    vertexInit.vertexPopulator(vertexData);
    int no_of_buffers=2;
    unsigned int vbo[no_of_buffers];
    unsigned int vao[no_of_buffers];
    glGenVertexArrays(no_of_buffers, vao);
    glGenBuffers(no_of_buffers, vbo);
    
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    for(int i=0;i<no_of_buffers;i++)
    {
        glBindVertexArray(vao[i]);

        glBindBuffer(GL_ARRAY_BUFFER, vbo[i]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexData),&vertexData[0], GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,9*sizeof(float),(void*)(3*sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,9*sizeof(float),(void*)(6*sizeof(float)));
        glEnableVertexAttribArray(2);
    }

    
    
    glBindVertexArray(0);
    std::array<float,54> feedback;
    Rotator rot(Face::DOWN,Turn::CLOCKWISE,Stack::FIRST);
    feedback=launchDetectingProgram(detectingshaderProgram,vao[0],rot.conditionTransformer());

    std::array<float,6> coverPoints;
    coverPoints=rot.coverPoints();
    unsigned int vao1;
    unsigned int vbo1;
    glGenVertexArrays(1,&vao1);
    glGenBuffers(1,&vbo1);
    glBindVertexArray(vao1);
    glBindBuffer(GL_ARRAY_BUFFER,vbo1);
    glBufferData(GL_ARRAY_BUFFER,sizeof(coverPoints),(void*)&coverPoints[0],GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    std::cout<<sizeof(feedback)<<std::endl;
    for(int i=0;i<54;i++)
    {
        std::cout<<feedback[i]<<" ";
    }
    std::cout<<std::endl;
    
    glBindVertexArray(0); 



    glm::mat4 projection,view,model=glm::mat4(1.0f);
    
    glEnable(GL_DEPTH); 
    glEnable(GL_DEPTH_TEST);
    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    for(int i=0;i<54;i++)
    {
        std::cout<<i+" ";
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
            std::cout<<vertexData[9*i+3*j+k]<<" ";
            }
            std::cout<<"  ";
        }
        std::cout<<std::endl;
    }
    for(int i=0;i<2;i++)
    {
        std::cout<<i<<" ";
        for(int j=0;j<3;j++)
            std::cout<<coverPoints[3*i+j];
        std::cout<<std::endl;    
    }
    // projection=glm::perspective(90.0f,800.0f/800.0f,3.0f,30.0f); 
    projection=glm::ortho(-10.0f,10.0f,-10.0f,10.0f,1.0f,100.0f);
    view=glm::lookAt(glm::vec3(4.0f,4.0f,-4.0f),glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f));

    //buffer rotation
    int draw_buffer=0;
    //timer timings
    bool KEY=true;
    float time=0.0f;
    float now,delta=0.0f,previous=glfwGetTime();
    int setter=0;
    float process_time=0.5f;
    while (!glfwWindowShouldClose(window))
    {
        
        // input
        // -----
        processInput(window);

        // render
        // -----
        glClearColor(0.1f, 0.1f,0.1f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        if(KEY)
        {
            now=glfwGetTime();
            if(setter++) delta=now-previous;
            previous=now;
            time+=delta;
            if(time<=process_time)
            {
                model=glm::mat4(1.0f);
                model=rot.rotateMatrixCreator(glm::half_pi<float>()*time/process_time);
            }
            else{
                model=rot.rotateMatrixCreator(glm::half_pi<float>());
        
                launchTransformingProgram(transformingshaderProgram,vao[draw_buffer],vbo[(draw_buffer+1)%no_of_buffers],model,feedback);
                delta=0.0f;
                setter=0;
                time=0.0f;
                draw_buffer=(draw_buffer+1)%no_of_buffers;
                KEY=false;
            }
            
        }
        launchDrawProgram(drawshaderProgram,vao[draw_buffer],model,view,projection,feedback); 
        launchCoverDrawProgram(coverDrawProgram,vao1,model,view,projection);
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(no_of_buffers,vao);
    glDeleteBuffers(no_of_buffers, vbo);
    glDeleteProgram(drawshaderProgram);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

