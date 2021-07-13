#ifndef _VERTEXINITIALIZER_
#define _VERTEXINITIALIZER_

#include <array>

struct Color
{
	float R;
	float G;
	float B;
};

class VertexInitializer
{
	float TL=2.0f;

	float planes[3] = {-TL, 0, TL};

	Color green{0, 1, 0};
	Color blue{0, 0, 1};
	Color red{1, 0, 0};
	Color orange{1, 0.65, 0};
	Color white{1, 1, 1};
	Color yellow{1, 1, 0};

	Color colorList[6] = {green, blue, white, yellow, red, orange};

public:
	void vertexPopulator(std::array<float, 54 * 9> &vertexData);
	float getTL();
	void setTL(float tileLength);
};
#endif