#include"opengl.h"

//choice_t data::choice;
unsigned data::choice;
float data::filledCube[6*216];
float data::cubeSize = 300.0f; //We change this in options_t class inorder to zoom the cube

/*
 * we need a single array to render the cube so we copy all the splits into an array and send that into buffer
 * */

void data::buildCube(){
    for (unsigned j = 0; j < 54; j++) {
      for (unsigned i = 0; i < 4; i++) {
        filledCube[6* i + 24 * j] 	   = splitCube[choice-1][j][i].xCord;
        filledCube[6 * i + 24 * j + 1] = splitCube[choice-1][j][i].yCord;
        filledCube[6 * i + 24 * j + 2] = splitCube[choice-1][j][i].zCord;
        filledCube[6 * i + 24 * j + 3] = splitCube[choice-1][j][i].rCol;
        filledCube[6 * i + 24 * j + 4] = splitCube[choice-1][j][i].gCol;
        filledCube[6 * i + 24 * j + 5] = splitCube[choice-1][j][i].bCol;
      }
    }
}

