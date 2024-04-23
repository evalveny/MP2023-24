#include "snake_game.h"
#include <stdio.h>
#ifdef _WINDOWS
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <fstream>
using namespace std;



SnakeGame::SnakeGame()
{
    m_dx = 0;
    m_dy = 0;

    for (int i = 0; i < MAX_ROW; ++i)
    {
        for (int j = 0; j < MAX_COL; ++j)
        {
            m_board[i][j] = ' ';
        }
    }

    // Col·loca la serp inicial en el tauler
    Position startPos = { MAX_ROW / 2, MAX_COL / 2 };
    m_snake.extend(startPos);
    m_board[MAX_ROW / 2][MAX_COL / 2] = 'S';

    // Col·loca la primera poma en el tauler
    int row, column;
    do 
    { //comprovem que no sigui la matexia posició que 
        row = rand() % MAX_ROW;
        column = rand() % MAX_COL;
    } while (m_board[row][column] != ' ');
    m_board[row][column] = 'O';

    m_nInputSequence = 0;
    m_nCurrentInput = 0;
    m_nApples = 0;
    m_nCurrentApple = 0;

    m_modeTest = false;
}

SnakeGame::SnakeGame(const string& initFile, const string& inputFile)
{
    m_dx = 0;
    m_dy = 0;

    for (int i = 0; i < MAX_ROW; ++i)
    {
        for (int j = 0; j < MAX_COL; ++j)
        {
            m_board[i][j] = ' ';
        }
    }

    initGameFromFile(initFile, inputFile);


    // Col·loca la primera poma en el tauler
    m_board[m_applePositions[m_nCurrentApple].row][m_applePositions[m_nCurrentApple].column] = 'O';
    m_nCurrentApple++;

    m_modeTest = true;
}

void SnakeGame::printBoard()
{
    if (!m_modeTest)
    {
#ifdef _WINDOWS
        system("cls"); // Neteja la consola (utilitza "cls" en Windows)
#endif
    }

    if (m_modeTest)
        cout << "Comment:=>> ";
    cout << " ";
    for (int j = 0; j < MAX_COL; ++j)
        cout << "_";
    cout << endl;
    for (int i = 0; i < MAX_ROW; ++i) 
    {
        if (m_modeTest)
            cout << "Comment:=>> ";
        cout << "|";
        for (int j = 0; j < MAX_COL; ++j) 
        {
            cout << m_board[i][j];
        }
        cout << "|" << endl;
    }
    if (m_modeTest)
        cout << "Comment:=>> ";
    cout << " ";
    for (int j = 0; j < MAX_COL; ++j)
        cout << "_";
    cout << endl;
}

GameStatus SnakeGame::moveSnake()
{
    GameStatus status = GAME_CORRECT;
    Position headSnake = m_snake.getHead();
    Position newPos;
    newPos.row = headSnake.row + m_dy;
    newPos.column = headSnake.column + m_dx;

    // Comprova si la serp intenta moure's fora dels límits
    if (newPos.column < 0 || newPos.row < 0 || newPos.column >= MAX_COL || newPos.row >= MAX_ROW)
        status = GAME_END_WALL;
    else
    {
        if (m_snake.collision(newPos))
            status = GAME_END_SNAKE;
        else
        {
            // Comprova si hi ha una poma en la nova posició
            if (m_board[newPos.row][newPos.column] == 'O')
            {
                m_snake.extend(newPos);

                Position applePos = getNextPosApple();
                m_board[applePos.row][applePos.column] = 'O';
            }
            else
            {
                Position tailSnake = m_snake.getTail();
                m_snake.move(newPos);
                m_board[tailSnake.row][tailSnake.column] = ' ';
            }
            m_board[newPos.row][newPos.column] = 'S';
        }
    }
    return status;
}

Position SnakeGame::getNextPosApple()
{
    Position posApple;
    if (!m_modeTest)
    {
        do
        {
            posApple.row = rand() % MAX_COL;
            posApple.column = rand() % MAX_ROW;
        } while (m_board[posApple.row][posApple.column] != ' ');
    }
    else
    {
        posApple = m_applePositions[m_nCurrentApple++];
    }
    return posApple;
}

void SnakeGame::updateDirection(char input)
{
    switch (input) 
    {
    case 'a': 
        m_dx = -1; 
        m_dy = 0; 
        break;
    case 'd': 
        m_dx = 1; 
        m_dy = 0; 
        break;
    case 'w': 
        m_dx = 0; 
        m_dy = -1; 
        break;
    case 's': 
        m_dx = 0; 
        m_dy = 1; 
        break;
    default:  
        m_dx = 0; 
        m_dy = 0; 
        break;
    }

}

GameStatus SnakeGame::playGame(const string& outputFile)
{
    char input;
    printBoard();
    GameStatus status = GAME_CORRECT;
    while (status == GAME_CORRECT) 
    {
        if (!m_modeTest)
        {
#ifdef _WINDOWS
            if (_kbhit())
            {

                input = _getch(); // Captura la direcció des del teclat
                updateDirection(input);
                if (m_dx != 0 || m_dy != 0)
                { // Si hi ha moviment correcte
                    status = moveSnake();
                    printBoard();
                    Sleep(20); // Espera una mica abans del següent moviment
                }
            }
#endif
        }
        else
        {
            if (m_nCurrentInput < m_nInputSequence)
            {
                input = m_inputSequence[m_nCurrentInput++];
                updateDirection(input);
                cout << "Comment :=>> Tecla entrada: " << input << endl;
#ifdef _WINDOWS
                Sleep(1000);
#else
                sleep(1);
#endif
                if (m_dx != 0 || m_dy != 0)
                { // Si hi ha moviment correcte
                    status = moveSnake();
                    printBoard();
                }
            }
            else
                status = GAME_END_TEST;
        }
    }
    if (status == GAME_END_WALL)
        cout << "Fi del joc! La serp ha xocat amb la paret." << endl;
    else
        if (status == GAME_END_SNAKE)
            cout << "Fi del joc! La serp s'ha xocat amb ella mateixa." << endl;
        else
            if (status == GAME_END_TEST)
                cout << "Final del test! " << endl;
    if (outputFile != "")
        saveGameToFile(outputFile);
    return status;
}

void SnakeGame::initGameFromFile(const string& initFile, const string& inputFile)
{
    ifstream fileInit;
    fileInit.open(initFile);
    if (fileInit.is_open())
    {
        int lengthSnake;
        Position posSnake[MAX_SNAKE];

        fileInit >> lengthSnake;
        for (int i = 0; i < lengthSnake; i++)
        {
            fileInit >> posSnake[i].row >> posSnake[i].column;
            m_board[posSnake[i].row][posSnake[i].column] = 'S';
        }
        m_snake.init(posSnake, lengthSnake);

        fileInit >> m_nApples;
        for (int i = 0; i < m_nApples; i++)
            fileInit >> m_applePositions[i].row >> m_applePositions[i].column;
        m_nCurrentApple = 0;

        fileInit.close();
    }

    ifstream fileInput;
    fileInput.open(inputFile);
    if (fileInput.is_open())
    {
        fileInput >> m_nInputSequence;
        for (int i = 0; i < m_nInputSequence; i++)
            fileInput >> m_inputSequence[i];
        m_nCurrentInput = 0;

        fileInput.close();
    }

}


void SnakeGame::saveGameToFile(const string& outputFile)
{
    ofstream fileOutput;

    fileOutput.open(outputFile);

    for (int i = 0; i < MAX_ROW; ++i)
    {
        for (int j = 0; j < MAX_COL; ++j)
        {
            fileOutput << m_board[i][j];
        }
        fileOutput << endl;
    }
    fileOutput.close();
}