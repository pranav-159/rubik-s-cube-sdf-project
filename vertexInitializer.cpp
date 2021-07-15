#include <iostream>
#include "vertexInitializer.h"
#include <array>
#include "shaderPrograms.h"
#include <glad/glad.h>
#include "rotator.h"
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <fstream>
#include <ctime>
#include <cstdlib>
/**
 * @brief populates the initial vertices into vertexData
 * 
* @param vertexData which is used to store the initial vertices
 */
void VertexInitializer::vertexPopulator(std::array<float,54*9>& vertexData)
{
	int i=0;
	for(int a=0;a<6;a++)
	{       
		int a1=(2-a/2)%3;
		int a2=(3-a/2)%3;
		int a3=(4-a/2)%3;
		int a4=1-2*(a%2);
		Color color=colorList[a];
		for(int b=0;b<3;b++)
		{
			for(int c=0;c<3;c++)
			{
				//initial vertex positions
				vertexData[i+a1]=3*a4*(TL/2); 
				vertexData[i+a2]=planes[c];
				vertexData[i+a3]=planes[b];
				//initial vertex normals
				i+=3;
				vertexData[i+a1]=a4;
				vertexData[i+a2]=0;
				vertexData[i+a3]=0;
				i+=3;
				//initial colors
				vertexData[i]=color.R;
				vertexData[i+1]=color.G;
				vertexData[i+2]=color.B;
				i+=3;
			}
		}
	}

}
/**
 * @brief gets the tile length used for vertex initialization
 * 
 * @return float tile length.
 */
float VertexInitializer::getTL(){
	return TL;
}
/**
 * @brief sets the tile length used for vertex initialization
 * 
 * @param tileLength length of the tile.
 */
void VertexInitializer::setTL(float tileLength){
	TL=tileLength;
}
/**
 * @brief populates the rubiks cube with random tiles.
 * 
 * @param vertexData the array which contains the tile data.
 */
void VertexInitializer::randomPopulator(std::array<float, 54 * 9> &vertexData)
{
	vertexPopulator(vertexData);
	unsigned int transformProgram=createTransformingProgram();  
	unsigned int detectingProgram=createDetectingProgram();

	std::srand((unsigned)std::time(NULL));
	int no_of_buffers=2;
    unsigned int vbo2[no_of_buffers];
    unsigned int vao2[no_of_buffers];
    glGenVertexArrays(no_of_buffers, vao2);
    glGenBuffers(no_of_buffers, vbo2);

	int draw_buffer=0;
    for(int i=0;i<no_of_buffers;i++)
    {
        glBindVertexArray(vao2[i]);

        glBindBuffer(GL_ARRAY_BUFFER, vbo2[i]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexData),&vertexData[0], GL_STREAM_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,9*sizeof(float),(void*)(3*sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,9*sizeof(float),(void*)(6*sizeof(float)));
        glEnableVertexAttribArray(2);
    }
	// std::array<float,54*9> tfData;
	// glGetBufferSubData(GL_ARRAY_BUFFER,0,54*9*sizeof(float),(void*)&tfData[0]);
	// std::ofstream myFile;
	// myFile.open("initTransform.csv");
	// for(int i=0;i<54;i++)
	// 	{	
	// 		myFile<<i<<",";
	// 		for(int j=0;j<3;j++)
	// 		{
	// 			for(int k=0;k<3;k++)
	// 			{
	// 				myFile<<vertexData[9*i+3*j+k]<<",";
	// 			}
	// 			myFile<<",";
	// 		}
	// 		myFile<<std::endl;
	// 	}
	// 	myFile<<std::endl;


	int n=15+std::rand()%20;
	while(n--)
	{
		// myFile<<n<<std::endl;
		int f=std::rand(),t=std::rand(),s=std::rand();
		Rotator* rot =new Rotator((Face)(f%6),(Turn)(t%2),(Stack)(s%4));
		// TestCondition test=rot->conditionTransformer();
		// myFile<<test.axis<<std::endl;
		// myFile<<test.plane1<<std::endl;
		// myFile<<test.plane2<<std::endl;
		std::array<float,54> feedback=launchDetectingProgram(detectingProgram,vao2[draw_buffer],rot->conditionTransformer());
		// for(int i=0;i<54;i++)
		// {
		// 	myFile<<i<<" "<<feedback[i]<<std::endl;
		// }
		// myFile<<std::endl;
		glm::mat4 model=rot->rotateMatrixCreator(glm::half_pi<float>());
		launchTransformingProgram(transformProgram,vao2[draw_buffer],vbo2[(draw_buffer+1)%no_of_buffers],model,feedback);
		
		// for(int i=0;i<4;i++){
		// 	for(int j=0;j<4;j++)
		// 		myFile<<model[i][j]<<" ";
		// 	myFile<<std::endl;
		// }	
		// myFile<<std::endl;
		// glBindVertexArray(vao2[(draw_buffer+1)%no_of_buffers]);
		// glGetBufferSubData(GL_ARRAY_BUFFER,0,54*9*sizeof(float),(void*)&tfData[0]);
		// for(int i=0;i<54;i++)
		// {
		// 	myFile<<i<<",";
		// 	for(int j=0;j<3;j++)
		// 	{
		// 		for(int k=0;k<3;k++)
		// 		{
		// 			myFile<<tfData[9*i+3*j+k]<<",";
		// 		}
		// 		myFile<<",";
		// 	}
		// 	myFile<<std::endl;
		// }
		// myFile<<std::endl;
		draw_buffer=(draw_buffer+1)%no_of_buffers;
		delete rot;
	}
	// myFile.close();
	glBindVertexArray(vao2[draw_buffer]);
	glBindBuffer(GL_ARRAY_BUFFER,vao2[draw_buffer]);
	glGetBufferSubData(GL_ARRAY_BUFFER,0,54*9*sizeof(float),(void*)&vertexData[0]);
	// for(int i=0;i<54;i++)
	// 	{
	// 		myFile<<i<<",";
	// 		for(int j=0;j<3;j++)
	// 		{
	// 			for(int k=0;k<3;k++)
	// 			{
	// 				myFile<<vertexData[9*i+3*j+k]<<",";
	// 			}
	// 			myFile<<",";
	// 		}
	// 		myFile<<std::endl;
	// 	}
	// 	myFile<<std::endl;
	// 	myFile.close();
	glDeleteBuffers(2,vbo2);
	glDeleteVertexArrays(2,vao2);
	glDeleteProgram(transformProgram);
	glDeleteProgram(detectingProgram);

}