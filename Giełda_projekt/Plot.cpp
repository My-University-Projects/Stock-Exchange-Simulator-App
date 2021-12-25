#include"Plot.h"


void Plot::configxy(float values[100])
{	
	int sum = (values[0] + values[10] + values[20] + values[30] + values[40] + values[50] + values[60] + values[70] + values[80] + values[90]) / 10;

	OX.setFillColor(Color::Yellow);
	OY.setFillColor(Color::Yellow);
	OX.setSize(Vector2f(1400, 1));
	OX.setOrigin(Vector2f(10, -880));
	OY.setSize(Vector2f(1, 950));
	OY.setOrigin(Vector2f(-10, 880));
	OY.setRotation(180);
	OX.setPosition(zero);
	OY.setPosition(zero);

	xd.setFillColor(Color::Yellow);
	xu.setFillColor(Color::Yellow);
	yl.setFillColor(Color::Yellow);
	yr.setFillColor(Color::Yellow);
	xd.setSize(Vector2f(15, 1));
	xu.setSize(Vector2f(15, 1));
	yl.setSize(Vector2f(1, 15));
	yr.setSize(Vector2f(1, 15));
	xd.setOrigin(-10, -894);
	xu.setOrigin(-10, -894);
	yl.setOrigin(0, 0);
	yr.setOrigin(0, 0);
	xd.setRotation(-45);
	xu.setRotation(45);
	yl.setRotation(45);
	yr.setRotation(-45);
	xd.setPosition(840, 366);
	xu.setPosition(2105, 329);
	yl.setPosition(88.5, 30);
	yr.setPosition(90.5, 30);

	/*scale_x[0].setFillColor(Color::Yellow);
	scale_y[0].setFillColor(Color::Yellow);
	scale_x[0].setSize(Vector2f(1, 6));
	scale_y[0].setSize(Vector2f(6, 1));
	scale_x[0].setOrigin(Vector2f(-10, -874));
	scale_y[0].setOrigin(Vector2f(10, -870));
	scale_x[0].setPosition(zero);
	scale_y[0].setPosition(zero);*/
	
	int scale;

	if (sum < 10) { scale = 100; }
	else if (sum >= 10 && sum < 100) { scale = 10; sum /= 10; }
	else if (sum >= 100) { scale = 1;  sum /= 100; }

	
	for (int i = 0; i < 99; i++)
	{
		if (i % 10 == 0)
		{
			scale_x[i + 1].setFillColor(Color::Yellow);
			scale_x[i + 1].setSize(Vector2f(1, 6));
			scale_x[i + 1].setOrigin(Vector2f(-10, -874));
			scale_x[i + 1].setPosition(100 + 15 * i, 100);
			scale_y[i + 1].setFillColor(Color::Yellow);
			scale_y[i + 1].setSize(Vector2f(6, 1));
			scale_y[i + 1].setOrigin(Vector2f(10, -870));
			scale_y[i + 1].setPosition(100, 100 - 9 * i);
		}
		
		if (values[i] > 0) { points.append(Vertex(Vector2f(90 + 14 * i, 1000 - ((scale * values[i]))), Color::Cyan)); }
	}
}

void draw(RenderWindow& w, Plot p, const Font& font, float values[100])
{
	int sum = (values[0] + values[10] + values[20] + values[30] + values[40] + values[50] + values[60] + values[70] + values[80] + values[90]) / 10;
	int scale;
	int OYtext_1 = 1;
	int OYtext_2 = 10;
	int OYtext_3 = 100;
	String tmp;
	Text text;
	p.points.setPrimitiveType(LineStrip);
	w.draw(p.OX);
	w.draw(p.OY);
	w.draw(p.scale_x[0]);
	w.draw(p.scale_y[0]);

	if (sum < 10) { scale = 100; }
	else if (sum >= 10 && sum < 100) { scale = 10;}
	else if (sum >= 100) { scale = 1; }

	for (int x = 0; x < 10; x++)
	{
		if (scale == 100)
		{
			tmp = to_string(OYtext_1);
			text.setString(tmp + "zl");
			text.setFillColor(Color::Cyan);
			text.setOrigin(Vector2f(30, -875));
			text.setPosition(80, 88 - 90* OYtext_1);
			text.setFont(font);
			text.setCharacterSize(12);
			p.text_.push_front(text);
			OYtext_1++;
		}
		else if (scale == 10)
		{
			tmp = to_string(OYtext_2);
			text.setString(tmp + "zl");
			text.setFillColor(Color::White);
			text.setOrigin(Vector2f(40, -875));
			text.setPosition(80, 88 - 9 * OYtext_2);
			text.setFont(font);
			text.setCharacterSize(12);
			p.text_.push_front(text);
			OYtext_2 += 10;;
		}
		else if (scale == 1)
		{
			tmp = to_string(OYtext_3);
			text.setString(tmp + "zl");
			text.setFont(font);
			text.setFillColor(Color::White);
			text.setOrigin(Vector2f(45, -875));
			text.setPosition(80, 88 - 0.9 * OYtext_3);
			text.setCharacterSize(12);
			p.text_.push_front(text);
			OYtext_3 += 100;
		}
	}
	for (int i = 2; i < 100; i++)
	{
		w.draw(p.scale_x[i]);
		w.draw(p.scale_y[i]);
		w.draw(p.points);
	}
	for (auto q = p.text_.begin(); q != p.text_.end(); q++) { w.draw(*q); }
	Text text_, text_1;
	text_.setString("Ostatnie 100 notowan");
	text_.setCharacterSize(14);
	text_.setFont(font);
	text_.setFillColor(Color::Yellow);
	text_.setOrigin(Vector2f(-600, -600));
	text_.setPosition(100, 385);
	text_1.setString("Cena akcji");
	text_1.setCharacterSize(14);
	text_1.setFont(font);
	text_1.setFillColor(Color::Yellow);
	text_1.setOrigin(Vector2f(100, 0));
	text_1.setPosition(0, 400);
	text_1.setRotation(-90);
	w.draw(text_1);
	w.draw(text_);
	w.draw(p.xd);
	w.draw(p.xu);
	w.draw(p.yl);
	w.draw(p.yr);
}