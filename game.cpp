#include <iostream>
#include <windows.h>
using namespace std;

const int gridSizeX = 80;  // Width of the grid
const int gridSizeY = 24;  // Height of the grid

void printEnemy();
void gotoxy(int x, int y);
void printMaze();
void MoveEnemy();
void MoveEnemyDown();
void MoveEnemyDiagonal();
void EraseEnemy();
void printPlayer();
void ErasePlayer();
void MovePlayerRight();
void MovePlayerLeft();
void MovePlayerUp();
void MovePlayerDown();

int ex1 = 2, ey1 = 2;
int ex2 = 20, ey2 = 2;
int ex3 = 40, ey3 = 2;
int px = 35, py = 12;

int main()
{
    system("cls");
    printMaze();
    printEnemy();
    printPlayer();
    while (true)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            MovePlayerLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            MovePlayerRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            MovePlayerUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            MovePlayerDown();
        }

        MoveEnemy();
        MoveEnemyDown();
        MoveEnemyDiagonal();
        Sleep(100);
    }
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void printEnemy()
{
    // Enemy 1 (Moving Right)
    gotoxy(ex1, ey1);
    cout << "   ____   ";
    gotoxy(ex1, ey1 + 1);
    cout << "  /  ..\\  ";
    gotoxy(ex1, ey1 + 2);
    cout << " |  (__) |";
    gotoxy(ex1, ey1 + 3);
    cout << "  \\____/ ";

    // Enemy 2 (Moving Down)
    gotoxy(ex2, ey2);
    cout << "   /\\    ";
    gotoxy(ex2, ey2 + 1);
    cout << "  /  \\   ";
    gotoxy(ex2, ey2 + 2);
    cout << " |    |  ";
    gotoxy(ex2, ey2 + 3);
    cout << " |____|  ";

    // Enemy 3 (Moving Diagonal)
    gotoxy(ex3, ey3);
    cout << "   /\\    ";
    gotoxy(ex3, ey3 + 1);
    cout << "  /  \\   ";
    gotoxy(ex3, ey3 + 2);
    cout << " |    |  ";
    gotoxy(ex3, ey3 + 3);
    cout << " |____|  ";
}

void EraseEnemy()
{
    // Erase Enemy 1
    gotoxy(ex1, ey1);
    cout << "         ";
    gotoxy(ex1, ey1 + 1);
    cout << "         ";
    gotoxy(ex1, ey1 + 2);
    cout << "         ";
    gotoxy(ex1, ey1 + 3);
    cout << "         ";

    // Erase Enemy 2
    gotoxy(ex2, ey2);
    cout << "         ";
    gotoxy(ex2, ey2 + 1);
    cout << "         ";
    gotoxy(ex2, ey2 + 2);
    cout << "         ";
    gotoxy(ex2, ey2 + 3);
    cout << "         ";

    // Erase Enemy 3
    gotoxy(ex3, ey3);
    cout << "         ";
    gotoxy(ex3, ey3 + 1);
    cout << "         ";
    gotoxy(ex3, ey3 + 2);
    cout << "         ";
    gotoxy(ex3, ey3 + 3);
    cout << "         ";
}


  void printMaze()
{
    cout<<"#################################################################################################"<<endl;//##########################################################";
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#                                                                                               #"<<endl;
    cout<<"#################################################################################################"<<endl;
}


void MoveEnemy()
{
    EraseEnemy();
    ex1 = ex1 + 1;
    if (ex1 == gridSizeX - 10)
    {
        ex1 = 2;
    }
    printEnemy();
}

void MoveEnemyDown()
{
    EraseEnemy();
    ey2 = ey2 + 1;
    if (ey2 == gridSizeY - 5)
    {
        ey2 = 2;
    }
    printEnemy();
}

void MoveEnemyDiagonal()
{
    EraseEnemy();
    ex3 = ex3 + 1;
    ey3 = ey3 + 1;
    if (ex3 == gridSizeX - 10 || ey3 == gridSizeY - 5)
    {
        ex3 = 2;
        ey3 = 2;
    }
    printEnemy();
}

void printPlayer()
{
    gotoxy(px, py);
    cout << "      /\\     ";
    gotoxy(px, py + 1);
    cout << "   __/~~\\__  ";
    gotoxy(px, py + 2);
    cout << "    / | | \\   ";
    gotoxy(px, py + 3);
    cout << "=====. .=====";
    gotoxy(px, py + 4);
    cout << "     ||||     ";
}

void ErasePlayer()
{
    gotoxy(px, py);
    cout << "            ";
    gotoxy(px, py + 1);
    cout << "            ";
    gotoxy(px, py + 2);
    cout << "            ";
    gotoxy(px, py + 3);
    cout << "             ";
    gotoxy(px, py + 4);
    cout << "             ";
}

void MovePlayerRight()
{
    ErasePlayer();
    if (px + 10 < gridSizeX)
    {
        px = px + 1;
    }
    printPlayer();
}

void MovePlayerLeft()
{
    ErasePlayer();
    if (px > 2)
    {
        px = px - 1;
    }
    printPlayer();
}

void MovePlayerUp()
{
    ErasePlayer();
    if (py > 2)
    {
        py = py - 1;
    }
    printPlayer();
}

void MovePlayerDown()
{
    ErasePlayer();
    if (py + 5 < gridSizeY)
    {
        py = py + 1;
    }
    printPlayer();
}