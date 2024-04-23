#ifndef SNAKE_H
#define SNAKE_H

typedef struct
{
    int row;
    int column;
} Position;

const int MAX_SNAKE = 225;

class Snake
{
public:
    Snake() : m_length(0), m_startIndex(0) {}
    void init(Position initPos[MAX_SNAKE], int lengthSnake);
    void move(const Position& pos);
    void extend(const Position& pos);
    bool collision(const Position& pos);
    Position getHead() const { return m_snake[(m_startIndex + m_length - 1) % MAX_SNAKE]; }
    Position getTail() const { return m_snake[m_startIndex]; }
private:
    static const int MAX_SNAKE = 225;
    Position m_snake[MAX_SNAKE];
    int m_length;
    int m_startIndex;
};


#endif
