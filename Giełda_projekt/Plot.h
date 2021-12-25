#pragma once
#include"Person.h"

/*
* Class representanting a chart plot in program
*/
class Plot
{
	
public:

	RectangleShape scale_x[100];
	RectangleShape scale_y[100];
	RectangleShape OX;
	RectangleShape OY;
	RectangleShape xu, xd, yl, yr;
	Vector2f zero;
	VertexArray points;
	list<Text> text_;
	
	/*
	* Method configures the appearance of the stock chart of a given stock
	* @param array of stock values
	*/
	void configxy(float values[100]);

	/*
	* Method that draws a chart
	*/
	friend void draw(RenderWindow& w, Plot p, const Font& font, float values[100]);


};
