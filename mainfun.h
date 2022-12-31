#ifndef MAINFUN_H_INCLUDED
int n, m;
typedef struct
{
    int mins1 ;
    int mins2 ;
    int secs1 ;
    int secs2 ;
    int hours1 ;
    int hours2 ;
    int player1Score;
    int player2Score;
    int totalTimeInSec1;
    int totalTimeInSec2;

} scores;
scores Timer(time_t old, int i, scores timeData)
{
    time_t current = time(NULL);
    time_t timeElapsed = current - old;
    if(i % 2 == 0 && i == 0)
    {
        timeData.totalTimeInSec1 += timeElapsed;
        timeData.hours1 = timeData.totalTimeInSec1 / 3600;
        timeData.mins1 = (timeData.totalTimeInSec1 % 3600) / 60;
        timeData.secs1 = (timeData.totalTimeInSec1 %3600) % 60;
        timeData.hours2 = 0;
        timeData.mins2 = 0;
        timeData.secs2 = 0;
    }
    else if(i % 2 == 0)
    {
        timeData.totalTimeInSec1 += timeElapsed;
        timeData.hours1  = timeData.totalTimeInSec1 / 3600;
        timeData.mins1 = (timeData.totalTimeInSec1 % 3600) / 60;
        timeData.secs1 = (timeData.totalTimeInSec1 %3600) % 60;
    }
    else
    {
        timeData.totalTimeInSec2 += timeElapsed;
        timeData.hours2 = timeData.totalTimeInSec2 / 3600;
        timeData.mins2 = (timeData.totalTimeInSec2 % 3600) / 60;
        timeData.secs2 = (timeData.totalTimeInSec2 %3600) % 60;
    }
    return timeData;
}
scores scoresStructure(char a[][2 * m + 1], int n, int m)
{
    int i, j;
    scores gameScore;
    gameScore.player1Score = 0;
    gameScore.player2Score = 0;
    for( i=0 ; i<n*2-1 ; i+=2)
    {
        for( j=1 ; j<m*2 ; j+=2)
        {
            //checking right diagonal elements.
            if( (a[i][j] == a[i+2][j+2]) && (a[i][j] == a[i+4][j+4]) && (a[i][j] == a[i+6][j+6]))
            {
                if( a[i][j] == 'X')
                {
                    gameScore.player1Score++;
                }
                else if(( a[i][j] == 'O'))
                {
                    gameScore.player2Score++;
                }
            }
            //checking left diagonal elements.
            if( (a[i][j] == a[i+2][j-2]) && (a[i][j] == a[i+4][j-4]) && (a[i][j] == a[i+6][j-6]))
            {
                if( a[i][j] == 'X')
                {
                    gameScore.player1Score++;
                }
                else if( a[i][j] == 'O')
                {
                    gameScore.player2Score++;
                }
            }
            //checking row elements.
            if( (a[i][j] == a[i][j+2]) && (a[i][j] == a[i][j+4]) && (a[i][j] == a[i][j+6]))
            {
                if( a[i][j] == 'X')
                {
                    gameScore.player1Score++;
                }
                else if(( a[i][j] == 'O'))
                {
                    gameScore.player2Score++;
                }
            }
            //checking column elements.
            if( a[i][j] == a[i+2][j] && a[i][j] == a[i+4][j] && a[i][j] == a[i+6][j])
            {
                if( a[i][j] == 'X')
                {
                    gameScore.player1Score++;
                }
                else if(( a[i][j] == 'O'))
                {
                    gameScore.player2Score++;
                }
            }
        }
    }
    return gameScore;
}

void generatingTheGame(char a[][2 * m + 1], int n, int m)
{
    int i, j;
    for(i=0 ; i<n * 2; i++)
    {
        for( j=0 ; j<m*2 + 1 ; j++)
        {
            if(j % 2 == 0 && i % 2 == 0)
                a[i][j] = '|' ;
            else if(j % 2 == 1 && i % 2 == 0)
                a[i][j] = ' ';
            else
                a[i][j] = '-' ;
        }
    }
}

void printingTheGame(char a[][2 * m + 1], int n, int m, int player1Color, int player2Color)
{
    int i, j, k;
    printf("\033[1;33m[1] Main Menu. [2]Undo. [3]Redo. [4] Save. [5] Exit.\033[0;37m\n");
    for(k=0 ; k < n *2 ; k++)
    {
        for( j=0 ; j<m*2 + 1 ; j++)
        {
            if(a[k][j] == 'X')
            {
                printf(" \033[0;3%dm%c\033[0;37m", player1Color, a[k][j]);
            }
            else if(a[k][j] == 'O')
            {
                printf(" \033[1;3%dm%c\033[0;37m", player2Color, a[k][j]);
            }
            else
                printf(" %c", a[k][j]);
        }
        printf("\n");
    }
    for(k = 0; k < m; k ++)
        printf("   %c", k + 65);
}
time_t showTime(int mode, time_t old, int i, scores timeModification)
{
    switch(mode)
    {
    case 1:
        printf ("\n\033[0;34mElapsed time by Player 1  %d : %d : %d", timeModification.hours1, timeModification.mins1, timeModification.secs1);
        printf ("\n\033[1;35mElapsed time by Player 2  %d : %d : %d\033[0;37m\n", timeModification.hours2, timeModification.mins2, timeModification.secs2);
        break;
    case 2:
        //printf ("\n\033[1;31mComputer time %d : %d : %d", timeModification.hours2, timeModification.mins2, timeModification.secs2);
        printf ("\n\033[0;33mElapsed time by Human %d : %d : %d\033[0;37m\n", timeModification.hours1, timeModification.mins1, timeModification.secs1);
        break;
    }
    return time(NULL);
}

void showPoints(int pointsP1, int pointsP2, int mode)
{
    switch(mode)
    {
    case 1:
        printf ("\n\033[0;34mPlayer 1 got %d points.\n", pointsP1);
        printf ("\033[1;35mPlayer 2 got %d points.\033[0;37m\n", pointsP2);
        break;
    case 2:
        printf ("\n\033[1;31mComputer got %d points.\n", pointsP1);
        printf ("\033[0;33mHuman got %d points.\033[0;37m\n", pointsP2);
        break;

    }
}
void showmoves(int movesP1, int movesP2, int mode)
{
    switch(mode)
    {
    case 1:
        printf ("\n\033[0;34mPlayer 1 made %d moves.\n", movesP1);
        printf ("\033[1;35mPlayer 2 made %d moves.\033[0;37m\n", movesP2);
        break;
    case 2:
        printf ("\n\033[1;31mComputer made %d moves.\n", movesP1);
        printf ("\033[0;33mHuman made %d moves.\033[0;37m\n", movesP2);
        break;

    }
}


#define MAINFUN_H_INCLUDED



#endif // MAINFUN_H_INCLUDED
