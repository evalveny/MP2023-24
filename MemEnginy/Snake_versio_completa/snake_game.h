#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include "snake.h"
#include <string>
using namespace std;

typedef enum
{
    GAME_CORRECT = 0,
    GAME_END_WALL,
    GAME_END_SNAKE,
    GAME_END_TEST
} GameStatus;

const int MAX_APPLE_POSITION = 10;
const int MAX_INPUT_SEQUENCE = 50;

static const int MAX_ROW = 15;
static const int MAX_COL = 15;

class SnakeGame
{
public:
    SnakeGame();
    SnakeGame(const string& initFile, const string& inputFile);
    void printBoard();
    Position getNextPosApple();
    GameStatus moveSnake();
    void updateDirection(char input);
    GameStatus playGame(const string& outputFile);
    void initGameFromFile(const string& initFile, const string& inputFile);
    void saveGameToFile(const string& outputFile);
private:
    Snake m_snake;
    char m_board[MAX_ROW][MAX_COL];
    int m_dx;
    int m_dy;

    // ONLY FOR TEST
    char m_inputSequence[MAX_INPUT_SEQUENCE];
    int m_nInputSequence;
    int m_nCurrentInput;
    Position m_applePositions[MAX_APPLE_POSITION];
    int m_nApples;
    int m_nCurrentApple;
    bool m_modeTest;
};



#endif
