#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include "Figure.h"

using namespace sf;

class Enemy
{
public:
	Enemy();
	void setFile(const String&);
	void Move(RenderWindow&, std::vector<std::vector<char>>&, bool&, 
		std::list<Figure*>&, const char&, const int[8][3][2], const int[9][2], bool&, bool&);
	bool Win(std::vector<std::vector<char>>&, const int[8][3][2], char);
	~Enemy();
private:
	String m_File;
};

