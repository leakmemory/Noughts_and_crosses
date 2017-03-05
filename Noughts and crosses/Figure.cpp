#include "Figure.h"



Figure::Figure(String& file, int x, int y): m_File(file)
{
	m_FigTex.loadFromFile("images/" + m_File);
	m_FigSpr.setTexture(m_FigTex);
	m_FigSpr.setPosition(x, y);
}

void Figure::Draw(RenderWindow& window)
{
	window.draw(m_FigSpr);
}


Figure::~Figure()
{
}
