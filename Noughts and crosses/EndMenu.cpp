#include "EndMenu.h"



MenuEnd::MenuEnd()
{
	m_MenuTex.loadFromFile("images/torn_sheet.png");
	m_MenuSpr.setTexture(m_MenuTex);
	m_MenuSpr.setPosition(10, 110);
	m_Font.loadFromFile("AGENCYR.TTF");
							  
	m_TextStartGame.setFont(m_Font);
	m_TextStartGame.setCharacterSize(50);
	m_TextStartGame.setFillColor(Color::Red);
	m_TextStartGame.setPosition(300, 200);

	m_TextContinue.setString("Play Again");
	m_TextContinue.setFont(m_Font);
	m_TextContinue.setCharacterSize(50);
	m_TextContinue.setFillColor(Color::Black);
	m_TextContinue.setPosition(120, 420);

	m_TextExit.setString("Exit");
	m_TextExit.setFont(m_Font);
	m_TextExit.setCharacterSize(50);
	m_TextExit.setFillColor(Color::Black);
	m_TextExit.setPosition(550, 420);

	m_RectPositionContinue.x = 180;
	m_RectPositionContinue.y = 70;
	m_RectPositionExit.x = 70;
	m_RectPositionExit.y = 70;

	m_rectContinue.setSize(m_RectPositionContinue);
	m_rectContinue.setFillColor(Color::Black);
	m_rectContinue.setPosition(115, 417);
	m_rectExit.setSize(m_RectPositionExit);
	m_rectExit.setFillColor(Color::Black);
	m_rectExit.setPosition(545, 417);
}

void MenuEnd::Draw(RenderWindow& window, Vector2i& MousePosition, Event& event, bool& MousePressed, bool& NewGame, std::list<Figure*>& Figures)
{
	window.draw(m_MenuSpr);
	m_TextStartGame.setString(m_Result);
	
	if (m_rectContinue.getGlobalBounds().contains(MousePosition.x, MousePosition.y))
	{
		window.draw(m_rectContinue);
		m_TextContinue.setFillColor(Color::White);
		if (Mouse::isButtonPressed(Mouse::Left) && !MousePressed)
		{
			MousePressed = true;
			NewGame = true;
		}
	}
	else if (m_rectExit.getGlobalBounds().contains(MousePosition.x, MousePosition.y))
	{
		window.draw(m_rectExit);
		m_TextExit.setFillColor(Color::White);
		if (Mouse::isButtonPressed(Mouse::Left) && !MousePressed)
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
	
		m_TextContinue.setFillColor(Color::Black);
		m_TextExit.setFillColor(Color::Black);
	}

	if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left) MousePressed = false;
	window.draw(m_TextStartGame);
	window.draw(m_TextContinue);
	window.draw(m_TextExit);
}


void MenuEnd::setResult(String str)
{
	m_Result = str;
}

MenuEnd::~MenuEnd()
{
}
