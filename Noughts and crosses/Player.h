#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include "Figure.h"

using namespace sf;

class Player
{
public:
	Player();
	void Move(RenderWindow&, Vector2i&, Event&, bool&, std::vector<std::vector<char>>&, bool&, std::list<Figure*>&, const char&);
	void setFile(const String&);
	~Player();
private:
	Vector2f m_RectSize;
	RectangleShape m_Rect;
	String m_File;
};

