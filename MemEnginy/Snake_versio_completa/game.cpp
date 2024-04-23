#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "snake_game.h"

using namespace std;

void readBoard(const string& fileName, char board[MAX_ROW][MAX_COL])
{
    ifstream file;
    file.open(fileName);
    if (file.is_open())
    {
        for (int i = 0; i < MAX_ROW; ++i)
        {
            string line;
            getline(file, line);
            for (int j = 0; j < MAX_COL; ++j)
            {
                board[i][j] = line[j];
            }
        }
        file.close();
    }
}

void showBoard(const string& fileName)
{
    char board[MAX_ROW][MAX_COL];

    readBoard(fileName, board);

    cout << "Comment:=>> ";
    cout << " ";
    for (int j = 0; j < MAX_COL; ++j)
        cout << "_";
    cout << endl;
    for (int i = 0; i < MAX_ROW; ++i)
    {
        cout << "Comment:=>> ";
        cout << "|";
        for (int j = 0; j < MAX_COL; ++j)
        {
            cout << board[i][j];
        }
        cout << "|" << endl;
    }
    cout << "Comment:=>> ";
    cout << " ";
    for (int j = 0; j < MAX_COL; ++j)
        cout << "_";
    cout << endl;
}

bool compareBoard(const string& fileName1, const string& fileName2)
{
    char board1[MAX_ROW][MAX_COL];
    char board2[MAX_ROW][MAX_COL];

    readBoard(fileName1, board1);
    readBoard(fileName2, board2);

    bool iguals = true;
    int i = 0;
    while (iguals && (i < MAX_ROW))
    {
        int j = 0;
        while (iguals && (j < MAX_COL))
        {
            if (board1[i][j] != board2[i][j])
                iguals = false;
            else
                j++;
        }
        i++;
    }
    return iguals;
}

void testSnake()
{

    float grade = 0.0;

    cout << endl << "Grade :=>> " << grade << endl << endl;
    cout << "Comment :=>> " << endl;
    cout << "Comment :=>> Iniciant test" << endl;
    cout << "Comment :=>> =============" << endl;

    const int N_TEST = 5;
    string initFile[N_TEST] = { "snake_init1.txt", "snake_init2.txt" , "snake_init3.txt" , "snake_init4.txt" , "snake_init5.txt" };
    string inputFile[N_TEST] = { "snake_input1.txt", "snake_input2.txt", "snake_input3.txt", "snake_input4.txt", "snake_input5.txt" };
    string outputFile[N_TEST] = { "snake_output1.txt", "snake_output2.txt", "snake_output3.txt", "snake_output4.txt", "snake_output5.txt" };
	string expectedOutputFile[N_TEST] = { "expected_snake_output1.txt", "expected_snake_output2.txt", "expected_snake_output3.txt", "expected_snake_output4.txt", "expected_snake_output5.txt" };

	for (int i = 0; i < N_TEST; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Inicialitzant partida amb fitxers: " << initFile[i] << ", " << inputFile[i] << endl;
		cout << "Comment :=>> " << endl;
		GameStatus status;
		SnakeGame game(initFile[i], inputFile[i]);
		cout << "Comment :=>> ------------" << endl;
		cout << "Comment :=>> Jugant la partida..... " << endl;
		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> ------------" << endl;
		status = game.playGame(outputFile[i]);
		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> ------------" << endl;
		cout << "Comment :=>> Estat final de la partida esperat " << endl;
		showBoard(expectedOutputFile[i]);
		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> ------------" << endl;
		if (compareBoard(expectedOutputFile[i], outputFile[i]))
		{
			cout << "Comment :=>> CORRECTE" << endl;
			grade += 2.0;
		}
		else
			cout << "Comment :=>> ERROR" << endl;
		cout << "Grade :=>> " << grade << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
}

int main()
{
    srand(time(0)); // Inicialització de la llavor per a números aleatoris
    bool testMode = true;
    if (testMode)
    {
        testSnake();
    }
    else
    {
        GameStatus status;
        SnakeGame game;
        status = game.playGame("");
    }

    return 0;
}
