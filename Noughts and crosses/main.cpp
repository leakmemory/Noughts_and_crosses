#include "StartMenu.h"
#include "GameField.h"
#include "Figure.h"
#include "Player.h"
#include "Enemy.h"
#include "EndMenu.h"
#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;
using namespace sf;

const int SIZE_OF_WINDOW = 745;
const char EMPTY = ' ';
const String CROSS = "cross.png";
const String NOUGHT = "nought.png";
const int WIN_POSITION[8][3][2] = { { { 0, 0 },{ 0, 1 },{ 0, 2 } },
									{ { 1, 0 },{ 1, 1 },{ 1, 2 } },
									{ { 2, 0 },{ 2, 1 },{ 2, 2 } },
									{ { 0, 0 },{ 1, 0 },{ 2, 0 } },
									{ { 0, 1 },{ 1, 1 },{ 2, 1 } },
									{ { 0, 2 },{ 1, 2 },{ 2, 2 } },
									{ { 0, 0 },{ 1, 1 },{ 2, 2 } },
									{ { 0, 2 },{ 1, 1 },{ 2, 0 } },
								  };
const int BEST_MOVES[9][2] = { {1,1}, {0,0}, {0,2}, {2,2}, {2,0}, {0,1}, {1,2}, {2,1}, {1,0} };

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(static_cast<unsigned int>(time(0)));
	
	RenderWindow window(VideoMode(SIZE_OF_WINDOW, SIZE_OF_WINDOW), "Noughts and crosses");
	StartMenu StrMenu;
	MenuEnd EndMenu;
	GameField Field;
	Player Human;
	Enemy Computer;
	bool isMenu = true, isGameMenu = false, isGame = false, KeyPressed = false, MousePressed = false, NewGame = false, HumanMove, again = false, Result = false, sleep = false;;
	

	vector<vector<char>> FigurePosition;
	list<Figure*> Figures;
	vector<char> tmp(3, EMPTY);
	for (int i = 0; i < 3; i++ ) FigurePosition.push_back(tmp);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		Vector2i MousePosition = Mouse::getPosition(window);

		if (NewGame)
		{
			again = true;
			NewGame = false;
			Result = false;
			sleep = false;
			if (rand() % 2 == 0)
			{
				HumanMove = true;
				Human.setFile(CROSS);
				Computer.setFile(NOUGHT);
			}
			else
			{
				HumanMove = false;
				Human.setFile(NOUGHT);
				Computer.setFile(CROSS);
			}
			while (!Figures.empty())
			{
				delete Figures.back();
				Figures.pop_back();
			}
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					FigurePosition[i][j] = EMPTY;
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape) && !KeyPressed)
		{
			if (isGame) { isGameMenu = true; isGame = false; }
			else if (isGameMenu) { isGameMenu = false; isGame = true; }
			KeyPressed = true;
		}
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::Escape) KeyPressed = false;
		window.clear();

		if (Result)
		{

			Field.Draw(window);
			for (auto iter = Figures.begin(); iter != Figures.end(); iter++) (*iter)->Draw(window);
			if (!sleep )window.display();
			if (Computer.Win(FigurePosition, WIN_POSITION, 'H')) EndMenu.setResult("You Win!");
			else
			{
				if (Computer.Win(FigurePosition, WIN_POSITION, 'C')) EndMenu.setResult("You Lose!");
				else if (Figures.size() == 9) EndMenu.setResult("Draw!");

			}
			if (!sleep) { Sleep(1000); sleep = true; MousePressed = false; }
			EndMenu.Draw(window, MousePosition, event, MousePressed, NewGame, Figures);
		}

		if (!isGame) StrMenu.Draw(window, MousePosition, event, isGame, isMenu, MousePressed, NewGame, Figures);
		if (isGame && !NewGame && !Result) 
		{	Field.Draw(window); 
			for (auto iter = Figures.begin(); iter != Figures.end(); iter++) (*iter)->Draw(window);
			if (!(Computer.Win(FigurePosition, WIN_POSITION, 'H')) && !(Computer.Win(FigurePosition, WIN_POSITION, 'C')))
			{
				if (HumanMove) Human.Move(window, MousePosition, event, MousePressed, FigurePosition, HumanMove, Figures, EMPTY);
				else Computer.Move(window, FigurePosition, HumanMove, Figures, EMPTY, WIN_POSITION, BEST_MOVES, NewGame, again);
				if (Figures.size() == 9) Result = true;
			}
			else Result = true;
		}

		window.display();
	}

	return 0;
}