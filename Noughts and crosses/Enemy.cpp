#include "Enemy.h"
#include <iostream>



Enemy::Enemy()
{

}

void Enemy::setFile(const String& file)
{
	m_File = file;
}

bool Enemy::Win(std::vector<std::vector<char>>& FigurePosition, const int WIN_POSITION[8][3][2], char val)
{
	for (int i = 0; i < 8; i++)
	{
		if ((FigurePosition[WIN_POSITION[i][0][0]][WIN_POSITION[i][0][1]] == FigurePosition[WIN_POSITION[i][1][0]][WIN_POSITION[i][1][1]]) &&
			(FigurePosition[WIN_POSITION[i][1][0]][WIN_POSITION[i][1][1]] == FigurePosition[WIN_POSITION[i][2][0]][WIN_POSITION[i][2][1]]) &&
			(FigurePosition[WIN_POSITION[i][0][0]][WIN_POSITION[i][0][1]]) == val)
		{
			return true;
		}
	}
	return false;
}

void Enemy::Move(RenderWindow& window, std::vector<std::vector<char>>& FigurePosition, bool& HumanMove, 
	std::list<Figure*>& Figures, const char& EMPTY, const int WIN_POSITION[8][3][2], const int BEST_MOVES[9][2], bool& NewGame, bool& again)
{
	bool found = false;
	static int count = 0;
	if (again)
	{
		count = 0;
		again = false;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (FigurePosition[i][j] == EMPTY && !found)
			{
				FigurePosition[i][j] = 'C';
				found = this->Win(FigurePosition, WIN_POSITION, 'C');
				if (found)
				{
					Figures.push_back(new Figure(m_File, 144 + j * 153 + j * 5, 134 + i * 150 + i * 5));
				}
				else FigurePosition[i][j] = EMPTY;
			}
		}
	}
	if (!found)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (FigurePosition[i][j] == EMPTY && !found)
				{
					FigurePosition[i][j] = 'H';
					found = this->Win(FigurePosition, WIN_POSITION, 'H');
					if (found)
					{
						Figures.push_back(new Figure(m_File, 144 + j * 153 + j * 5, 134 + i * 150 + i * 5));
						FigurePosition[i][j] = 'C';
					}
					else FigurePosition[i][j] = EMPTY;
				}
			}
		}
	}
	if (!found)
	{
		while (!found)
		{
			int i = BEST_MOVES[count][0], j = BEST_MOVES[count][1];
			if (FigurePosition[i][j] == EMPTY)
			{
				Figures.push_back(new Figure(m_File, 144 + j * 153 + j * 5, 134 + i * 150 + i * 5));
				found = true;
				FigurePosition[i][j] = 'C';
				count++;
			}
			else count++;
		}
	}
	HumanMove = true;
}

Enemy::~Enemy()
{
}
