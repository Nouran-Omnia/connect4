#include <stdio.h>
#include <stdlib.h>
# include"colors.h"
# include "mainfun.h"
#include <ctype.h>
#include <string.h>
#include "AIminimax.h"
#include "HvH.h"
#include "mainmenu.h"
#include "topScores.h"

int main ()
{
    int i, j, k, p = 1, mode, flag = 1;
    scores statistics;
    mode = menu();
    while(mode == 0)
        {
        int n;
        printf("\n\033[1;32m[1] Main Menu.\n[2] Exit.\n");
        printf("Please choose an option : \033[0;37m\n");
        scanf("%d",&n);
        fflush(stdin);

            switch(n)
            {
            case 1:
            {
                main();
                break;
            }
            case 2:
                exit(0);
            default:
            {
                printf("\nPlease choose one of the options above :\n");
                scanf("%d",&n);
                fflush(stdin);
            }
        }
        }


    printf("\nWelcome to \033[0;33mConnect 4 Game");
    green(0);
    printf("\nplease enter the number of rows :\n");
    white(0);
    scanf("%d", &n);
    fflush(stdin);

    while(n<4)
    {

        printf("\033[4;31m This is invalid\033[0;37m , Please choose another number of rows :\n");
        scanf("%d", &n);
        fflush(stdin);
    }

    cyan(0);
    printf("please enter the number of columns :\n");
    white(0);
    scanf("%d", &m);
    fflush(stdin);

    while(m<4)
    {
        printf("\033[4;31m This is invalid\033[0;37m , Please choose another number of columns :\n");
        scanf("%d", &m);
        fflush(stdin);
    }

    char mat[n * 2][2 * m + 1];
    generatingTheGame(mat, n, m);
    printingTheGame(mat, n, m, 4, 5);
    fflush(stdin);
    switch(mode)
    {
    case 11:
        gameFlowHvH(mat, n, m, p);
        statistics = scoresStructure(mat, n, m);
        player1.points = statistics.player1Score;
        player2.points = statistics.player2Score;
        winnerHvH(player1, player2);
        main();
        break;
    case 12:
        gameFlowHvC(mat, n, m);
        statistics = scoresStructure(mat, n, m);
        winnerCvH(statistics.player1Score, statistics.player2Score);
        main();
  }

    return 0;
    }

