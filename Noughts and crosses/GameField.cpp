#include "GameField.h"



GameField::GameField()
{
	m_GameTex.loadFromFile("images/sheet.jpg");
	m_GameSpr.setTexture(m_GameTex);
}

void GameField::Draw(RenderWindow& window)
{
	window.draw(m_GameSpr);
}

GameField::~GameField()
{
}
