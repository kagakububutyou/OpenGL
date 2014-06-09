#pragma once

#include "Color.h"

//	直線を引くクラス
class LINE
{
public:

	LINE(float x1, float y1, float x2, float y2, float size = 1.0f)
	{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;

	this->width = size;

	}
	~LINE(){}

	void Draw(Color &color)
	{
		glColor4f(color.r, color.g, color.b, color.a);
		glBegin(GL_LINE_LOOP);
		glVertex2d( x1, y1);
		glVertex2d( x2, y2);
		glEnd();
	}


private:

	float x1, y1, x2, y2;
	float width;

};

//	四角形を描画
class BOX
{
public:
	BOX();
	~BOX();

private:

};