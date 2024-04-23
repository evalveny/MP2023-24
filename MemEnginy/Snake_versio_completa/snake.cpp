#include "snake.h"


void Snake::init(Position initPos[MAX_SNAKE], int lengthSnake)
{
	for (int i = lengthSnake - 1; i >= 0; i--)
		extend(initPos[i]);
}

void Snake::move(const Position& pos)
{
	int index = (m_startIndex + m_length) % MAX_SNAKE;
	m_snake[index] = pos;
	m_startIndex++;
}

void Snake::extend(const Position& pos)
{
	int index = (m_startIndex + m_length) % MAX_SNAKE;
	m_snake[index] = pos;
	m_length++;
}

bool Snake::collision(const Position& pos)
{
	bool collision = false;
	int index = m_startIndex;
	int i = 0;
	while (!collision && i < m_length)
	{
		if ((m_snake[index].row == pos.row) && (m_snake[index].column == pos.column))
			collision = true;
		else
		{
			i++;
			index = (index + 1) % MAX_SNAKE;
		}
	}
	return collision;
}