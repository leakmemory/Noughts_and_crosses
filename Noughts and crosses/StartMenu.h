#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Figure.h"

using namespace sf;

class StartMenu
{
public:
	StartMenu();
	virtual void Draw(RenderWindow&, Vector2i&, Event&, bool&, bool&, bool&, bool&, std::list<Figure*>& );
	~StartMenu();
protected:
	Texture m_MenuTex;
	Sprite m_MenuSpr;
	Font m_Font;
	Text m_TextStartGame, m_TextContinue, m_TextExit;
	Vector2f m_RectPositionStart, m_RectPositionContinue, m_RectPositionExit;
	RectangleShape m_rectStart, m_rectContinue, m_rectExit;

};

