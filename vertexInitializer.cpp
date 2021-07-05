#include <iostream>
#include "vertexInitializer.h"
#include <array>
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
float VertexInitializer::getTL(){
	return TL;
}
void VertexInitializer::setTL(float tileLength){
	TL=tileLength;
}
