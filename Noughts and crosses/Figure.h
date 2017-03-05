#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Figure
{
public:
	Figure(String&, int, int);
	void Draw(RenderWindow&);
	~Figure();
private:
	Texture m_FigTex;
	Sprite m_FigSpr;
	String m_File;
};

