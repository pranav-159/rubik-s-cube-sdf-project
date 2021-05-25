#ifndef _DATA_
#define _DATA_

/**
 * 
 * This file contains only the data used in making cubes
 * The data used here is just an example, we need to carefully calculate the points and modify the arrays below accordingly
 * 
 * **/
class data{
private:
    float shuffled[24*6]= {

        //back face red color

        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 0.0f,0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 0.0f,0.0f,
        
        //front face green color 

        -0.5f, -0.5f,  0.5f,   0.0f, 1.0f,0.0f,
         0.5f, -0.5f,  0.5f,   0.0f, 1.0f,0.0f,
         0.5f,  0.5f,  0.5f,   0.0f, 1.0f,0.0f,
        -0.5f,  0.5f,  0.5f,   0.0f, 1.0f,0.0f,
        
        
        //left face blue color

        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,1.0f,
        
        
        //right face yellow color

        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 1.0f,0.0f,
       
        
        //down face

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,1.0f,
        0.5f, -0.5f, -0.5f,   0.0f, 1.0f,1.0f,
        0.5f, -0.5f,  0.5f,   0.0f, 1.0f,1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,1.0f,
        
        
        //top face

        -0.5f,  0.5f, -0.5f,  1.0f, 0.0f,1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 0.0f,1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,1.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,1.0f};


    float pattern[24*6]={

        //back face red color

        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 0.0f,0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 0.0f,0.0f,
        
        //front face green color 

        -0.5f, -0.5f,  0.5f,   0.0f, 1.0f,0.0f,
         0.5f, -0.5f,  0.5f,   0.0f, 1.0f,0.0f,
         0.5f,  0.5f,  0.5f,   0.0f, 1.0f,0.0f,
        -0.5f,  0.5f,  0.5f,   0.0f, 1.0f,0.0f,
        
        
        //left face blue color

        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,1.0f,
        
        
        //right face yellow color

        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 1.0f,0.0f,
       
        
        //down face

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,1.0f,
        0.5f, -0.5f, -0.5f,   0.0f, 1.0f,1.0f,
        0.5f, -0.5f,  0.5f,   0.0f, 1.0f,1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,1.0f,
        
        
        //top face

        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 0.0f,1.0f,
        0.5f,  0.5f,  0.5f,  0.0f, 0.0f,1.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,1.0f};
public:
    float* getShuffle(){return shuffled;}
    float*  getPattern(){return pattern;}
    GLsizei setVertices();

};


#endif