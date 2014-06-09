#pragma once
#include <math.h>


#include "Color.h"

static const float ƒÎ = 3.1415926f;

//	’¼ü‚ðˆø‚­ƒNƒ‰ƒX
class LINE
{
private:

	float x1, y1, x2, y2;
	float width;

public:

	LINE(float _x1, float _y1, float _x2, float _y2, float size = 1.0f)
	{
	this->x1 = _x1;
	this->y1 = _y1;
	this->x2 = _x2;
	this->y2 = _y2;

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
};

//	ŽlŠpŒ`‚ð•`‰æ
class BOX
{
private:

	float x1, y1, x2, y2;

public:

	BOX(float _x1, float _y1, float _x2, float _y2)
	{
		this->x1 = _x1;
		this->y1 = _y1;
		this->x2 = _x2;
		this->y2 = _y2;
	}
	~BOX(){}

	void Draw(Color &color, bool FillFlag)
	{
		glColor4f(color.r, color.g, color.b, color.a);
		if(FillFlag)glBegin(GL_QUADS);
		if(!FillFlag)glBegin(GL_LINE_LOOP);
		glVertex2d( x1, y1);
		glVertex2d( x1, y2);
		glVertex2d( x2, y2);
		glVertex2d( x2, y1);
		glEnd();
	}
};

//	‰~‚Ì•`‰æ
class CIRCLE
{
private:

	float x, y, r;

public:
	CIRCLE(float _x,float _y,float _r)
	{
		this->x = _x;
		this->y = _y;
		this->r = _r;
	}
	~CIRCLE(){}

	void Draw(Color &color, bool FillFlag)
	{
		for (float th1 = 0.0;  th1 <= 360.0;  th1 = th1 + 1.0)
		{             
			float th2 = th1 + 10.0;
			float th1_rad = th1 / 180.0 * ƒÎ; 
			float th2_rad = th2 / 180.0 * ƒÎ;

			float x1 = r * cos(th1_rad);
			float y1 = r * sin(th1_rad);
			float x2 = r * cos(th2_rad);
			float y2 = r * sin(th2_rad);


			glColor4f(color.r, color.g, color.b, color.a);
			if(FillFlag)glBegin(GL_QUADS);
			if(!FillFlag)glBegin(GL_LINE_LOOP);
			glVertex2f( x1+x, y1+y );     
			glVertex2f( x2+x, y2+y );
			glEnd();
		}
	}

};

//	‘È‰~‚Ì•`‰æ
class OVAL
{
private:

	float x, y, r, rx, ry;

public:
	OVAL(float _x,float _y,float _r, float _rx,float _ry)
	{
		this->x		= _x;
		this->y		= _y;
		this->r		= _r;
		this->rx	= _rx;
		this->ry	= _ry;
	}
	~OVAL(){}

	void Draw(Color &color, bool FillFlag)
	{
		 for (float th1 = 0.0;  th1 <= 360.0;  th1 = th1 + 1.0)
		 {             
		  float th2 = th1 + 10.0;
		  float th1_rad = th1 / 180.0 * ƒÎ; 
		  float th2_rad = th2 / 180.0 * ƒÎ;

		  float x1 = r * cos(th1_rad)*(rx/100.0f);
		  float y1 = r * sin(th1_rad)*(ry/100.0f);
		  float x2 = r * cos(th2_rad)*(rx/100.0f);
		  float y2 = r * sin(th2_rad)*(ry/100.0f);


		  glColor4f(color.r, color.g, color.b, color.a);
		  glBegin(GL_LINES);   
		  glVertex2f( x1+x, y1+y );
		  glVertex2f( x2+x, y2+y );
		  glEnd();
		 }
	}
};