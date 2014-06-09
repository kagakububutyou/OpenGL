#pragma once


//	F‚ÌƒNƒ‰ƒX
class Color
{
public:
	Color(float r,float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
	~Color(){}

	float r, g, b, a;
private:

};
