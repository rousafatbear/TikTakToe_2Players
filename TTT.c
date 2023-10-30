#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// This is really bad

int place[3][3];

void print_board();
bool Winner_check(int i, int j, int player);
bool checkColumn(int j, int player);
bool CheckRow(int i, int player);
bool CheckDiagnoal(int i, int j, int player);
void placing(int *i, int *j, int player);

void print_board()
{
    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int j = 0; j < 3; j++)
        {
            if (place[i][j] == 0)
                printf(" ");
            else if (place[i][j] == 1)
                printf("O");
            else 
                printf("X");
            printf("|");
        }
        printf("\n------\n");
    }    
}

bool checkColumn(int j, int player)
{
    if (place[0][j] == player && place[1][j] == player && place[2][j] == player)
        return true;
    return false;
}

bool CheckRow(int i, int player)
{
    if (place[i][0] == player && place[i][1] == player && place[i][2] == player)
        return true;
    return false;
}

bool CheckDiagnoal(int i, int j, int player)
{
    if (i - j == 0 || abs(i - j) == 2)
    {
        if (place[0][0] == player && place[1][1] == player && place[2][2] == player)
            return true;
        if (place[0][2] == player && place[1][1] == player && place[2][0] == player)
            return true;
        return false;
    }
    return false;
}

void placing(int *i, int *j, int player)
{
    int check = 0;
    while (check == 0)
    {
        printf("[player%d] Hang/Cot: ", player);
        scanf("%d/%d", &*i, &*j);
        if (place[*i][*j] == 0 && *i < 3 && *j < 3) check = 1;
    }
    place[*i][*j] = player;
    print_board();
}

bool Winner_check(int i, int j, int player)
{
    if (CheckDiagnoal(i, j, player) || CheckRow(i, player) || checkColumn(j, player))
    {
        printf("Player %d win\n", player);
        return true;
    }
    return false;
}

void main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            place[i][j] == 0;
        }
    }
    print_board();
    bool winner = false;
    int player = 1;
    int player2 = 2;
    int i, j = 0;
    while (winner != true)
    {
        placing(&i, &j, player);
        winner = Winner_check(i, j, player);
        if (winner) break;
        placing(&i, &j, player2);
        winner = Winner_check(i, j, player2);
        if (winner) break;
    }
}