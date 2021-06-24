#include"opengl.h"

unsigned data::choice;
float data::cubeSize = 300.0f;

void data::buildCube(){
  if (choice == 1) {
    for (unsigned j = 0; j < 54; j++) {
      for (unsigned i = 0; i < 4; i++) {
        shuffled[6* i + 24 * j] = shuffledFaces[j][i].xCord;
        shuffled[6 * i + 24 * j + 1] = shuffledFaces[j][i].yCord;
        shuffled[6 * i + 24 * j + 2] = shuffledFaces[j][i].zCord;
        shuffled[6 * i + 24 * j + 3] = shuffledFaces[j][i].rCol;
        shuffled[6 * i + 24 * j + 4] = shuffledFaces[j][i].gCol;
        shuffled[6 * i + 24 * j + 5] = shuffledFaces[j][i].bCol;
      }
    }
  } else if (choice == 2) {
    for (unsigned j = 0; j < 54; j++) {
      for (unsigned i = 0; i < 4; i++) {
        pattern[6 * i + 24 * j] = patternFaces[j][i].xCord;
        pattern[6 * i + 24 * j + 1] = patternFaces[j][i].yCord;
        pattern[6 * i + 24 * j + 2] = patternFaces[j][i].zCord;
        pattern[6 * i + 24 * j + 3] = patternFaces[j][i].rCol;
        pattern[6 * i + 24 * j + 4] = patternFaces[j][i].gCol;
        pattern[6 * i + 24 * j + 5] = patternFaces[j][i].bCol;
      }
    }
  }
}

void data::setVertices(){
    set_buffer dataRenderd;
    if(choice == 1){
		buildCube();
        std::copy(shuffled,shuffled+(216*6),dataRenderd.vertices);
        std::cout<<"You have selected to solve the shuffledCube cube\n";
        dataRenderd.init_buffer();
        
    }
    else if(choice == 2){
		buildCube();
        std::copy(pattern,pattern+(216*6),dataRenderd.vertices);
        std::cout<<"You have selected to solve the pattern \n";
        dataRenderd.init_buffer();
    }
    else{
        std::cout<<"Please enter 1 or 2 \n";
        setVertices();
    }
}
