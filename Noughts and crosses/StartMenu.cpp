#include "StartMenu.h"

using namespace sf;

StartMenu::StartMenu()
{
	m_MenuTex.loadFromFile("images/Menu.png");
	m_MenuSpr.setTexture(m_MenuTex);
	m_Font.loadFromFile("AGENCYR.TTF");

	m_TextStartGame.setString("Start Game");
	m_TextStartGame.setFont(m_Font);
	m_TextStartGame.setCharacterSize(50);
	m_TextStartGame.setFillColor(Color::Black);
	m_TextStartGame.setPosition(295, 250);

	m_TextContinue.setString("Continue");
	m_TextContinue.setFont(m_Font);
	m_TextContinue.setCharacterSize(50);
	m_TextContinue.setFillColor(Color::Color(192, 192, 192));
	m_TextContinue.setPosition(315, 340);

	m_TextExit.setString("Exit");
	m_TextExit.setFont(m_Font);
	m_TextExit.setCharacterSize(50);
	m_TextExit.setFillColor(Color::Black);
	m_TextExit.setPosition(350, 440);

	m_RectPositionStart.x = 190;
	m_RectPositionStart.y = 70;
	m_RectPositionContinue.x = 150;
	m_RectPositionContinue.y = 70;
	m_RectPositionExit.x = 70;
	m_RectPositionExit.y = 70;

	m_rectStart.setSize(m_RectPositionStart);
	m_rectStart.setFillColor(Color::Black);
	m_rectStart.setPosition(290, 247);
	m_rectContinue.setSize(m_RectPositionContinue);
	m_rectContinue.setFillColor(Color::Black);
	m_rectContinue.setPosition(310, 337);
	m_rectExit.setSize(m_RectPositionExit);
	m_rectExit.setFillColor(Color::Black);
	m_rectExit.setPosition(345, 437);
}

void StartMenu::Draw(RenderWindow& window, Vector2i& MousePosition, Event& event, bool& isGame, bool& isMenu, bool& MousePressed, bool& NewGame, std::list<Figure*>& Figures)
{
	window.draw(m_MenuSpr);
	if (m_rectStart.getGlobalBounds().contains(MousePosition.x, MousePosition.y))
	{
		window.draw(m_rectStart);
		m_TextStartGame.setFillColor(Color::White);
		if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left && !MousePressed)
		{
			isGame = true;
			isMenu = false;
			MousePressed = true;
			NewGame = true;
		}
	}
	else
	{
		if (m_rectContinue.getGlobalBounds().contains(MousePosition.x, MousePosition.y) && !isMenu)
		{
			window.draw(m_rectContinue);
			m_TextContinue.setFillColor(Color::White);
			if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left)
			{
				isGame = true;
				isMenu = false;
				MousePressed = true;
			}
		}
		else if (m_rectExit.getGlobalBounds().contains(MousePosition.x, MousePosition.y))
		{
			window.draw(m_rectExit);
			m_TextExit.setFillColor(Color::White);
			if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left)
			{
				while (!Figures.empty())
				{
					delete Figures.back();
					Figures.pop_back();
				}
				window.close();
			}
		}
		else
		{
			m_TextStartGame.setFillColor(Color::Black);
			if (!isMenu) m_TextContinue.setFillColor(Color::Black);
			m_TextExit.setFillColor(Color::Black);
		}
	}
	if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left) MousePressed = false;
	window.draw(m_TextStartGame);
	window.draw(m_TextContinue);
	window.draw(m_TextExit);
}


StartMenu::~StartMenu()
{
}
