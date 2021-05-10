#include"opengl.h"


 float vertices[] = {

     -0.75f, -0.75f, 0.0f,  1.0f,0.0f,0.0f,
     -0.25f, -0.75f, 0.0f, 1.0f,0.0f,0.0f,
     -0.25f, -0.25f, 0.0f,    1.0f,0.0f,0.0f,
     -0.75f, -0.25f, 0.0f, 1.0f,0.0f,0.0f,

     -0.25f, -0.75f, 0.0f, 1.0f,1.0f,0.0f,
     0.25f, -0.75f, 0.0f,  1.0f,1.0f,0.0f,
     0.25f, -0.25f, 0.0f,    1.0f,1.0f,0.0f,
     -0.25f, -0.25f, 0.0f,    1.0f,1.0f,0.0f,

     0.25f, -0.75f, 0.0f,  0.0f,1.0f,0.0f,   
     0.75f, -0.75f, 0.0f,   0.0f,1.0f,0.0f,
     0.75f, -0.25f, 0.0f,   0.0f,1.0f,0.0f,
     0.25f, -0.25f, 0.0f,   0.0f,1.0f,0.0f,

     -0.75f, -0.25f, 0.0f, 0.0f,0.0f,1.0f,
     -0.25f, -0.25f, 0.0f,    0.0f,0.0f,1.0f,
     -0.25f, 0.25f, 0.0f,   0.0f,0.0f,1.0f,
     -0.75f, 0.25f, 0.0f,   0.0f,0.0f,1.0f




};

unsigned indices[]{
    0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4,
    8, 9, 10, 10, 11, 8,
    12, 13, 14, 14, 15, 12
};


GLsizei indices_size(){return sizeof(indices);}




/**
 * 
 * It loads (saves) the data in to the buffer that is binded 
 *   
*/
void init_buffer()
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

}