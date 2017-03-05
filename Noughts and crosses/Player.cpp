#include "Player.h"
#include <iostream>


Player::Player()
{
	m_RectSize.x = 153;
	m_RectSize.y = 150;
	m_Rect.setFillColor(Color::Color(143, 215, 113, 100));
	m_Rect.setSize(m_RectSize);
}

void Player::Move(RenderWindow& window, Vector2i& MousePosition, Event& event, bool& MousePressed, std::vector<std::vector<char>>& FigurePosition, bool& HumanMove, std::list<Figure*>& Figures, const char& EMPTY)
{
	if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)	MousePressed = false;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			m_Rect.setPosition(144 + j * 153 + j * 5, 134 + i * 150 + i * 5);
			if (m_Rect.getGlobalBounds().contains(MousePosition.x, MousePosition.y) && FigurePosition[i][j] == EMPTY)
			{
				window.draw(m_Rect);
				if (Mouse::isButtonPressed(Mouse::Left) && !MousePressed)
				{
					MousePressed = true;
					Figures.push_back(new Figure(m_File, 144 + j * 153 + j * 5, 134 + i * 150 + i * 5));
					FigurePosition[i][j] = 'H';
					HumanMove = false;
				}
			}
		}
}

void Player::setFile(const String& file)
{
	m_File = file;
}


Player::~Player()
{
}
