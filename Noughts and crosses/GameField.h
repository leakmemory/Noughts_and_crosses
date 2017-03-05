#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class GameField
{
public:
	GameField();
	void Draw(RenderWindow&);
	~GameField();
private:
	Texture m_GameTex;
	Sprite m_GameSpr;
	Vector2f m_RectSize;
	RectangleShape m_Rect;
};

