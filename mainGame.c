#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "colors.h"
int n, m;
int modifyArray (char a[][2 * m + 1],  char col, int n, int p);
int checkFreeSpaces (char a[][2 * m + 1] , int n , int m);
void winner (char a[][2 * m + 1] , int n , int m);
void showPoints (char a[][2 * m + 1] , int n , int m , int p);


int modifyArray(char a[][2 * m + 1],  char col, int n, int p)
{
    int row = n * 2 - 2, flag = 0, realcol = 2 * (col - 64) - 1;
    while(flag == 0)
    {
        if(a[row][realcol] == ' ')
        {
            if(p == 1)
                a[row][realcol] = 'X';
            else
                a[row][realcol] = 'O';
            flag = 1;
        }
        else if(row == 0)
        {
            printf("\033[4;31mColumn is full.\033[0;37m\nPlease choose another column \033[0;3%dmplayer %d\033[0;37m :\n", p + 3, p);
            return flag;
        }
        else
        {
            row -= 2;
        }
    }
    return flag;
}

int checkFreeSpaces (char a[][2 * m + 1] , int n , int m){
    
    int i, j;
    int freeSpaces = n*m ;
    
    for(i=0 ; i<n*2 ; i+=2)
    {
        for(j=1 ; j<m*2+1 ; j+=2)
        {
            if(a[i][j] != 0)
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void winner (char a[][2 * m + 1] , int n , int m){
    
    int i, j;
    int pointsP1 = 0;
    int pointsP2 = 0;
    int max = 1000;       
    char name[max];

    if(checkFreeSpaces (a , n , m) == 0)
    {
        for( i=0 ; i<n*2-1 ; i+=2)
        {
            for( j=1 ; j<m*2 ; j+=2)
            {
                //checking right diagonal elements.
                if( (a[i][j] == a[i+2][j+2]) && (a[i][j] == a[i+4][j+4]) && (a[i][j] == a[i+6][j+6]))
                {
                    if( a[i][j] == 'X')
                    {
                        pointsP1++;
                    }
                    else
                    {
                        pointsP2++;
                    }
                }
                //checking left diagonal elements.
                if( (a[i][j] == a[i+2][j-2]) && (a[i][j] == a[i+4][j-4]) && (a[i][j] == a[i+6][j-6]))
                {
                    if( a[i][j] == 'X')
                    {
                        pointsP1++;
                    }
                    else
                    {
                        pointsP2++;
                    }
                }
                //checking row elements.
                if( (a[i][j] == a[i][j+2]) && (a[i][j] == a[i][j+4]) && (a[i][j] == a[i][j+6]))
                {
                    if( a[i][j] == 'X')
                    {
                        pointsP1++;
                    }
                    else
                    {
                        pointsP2++;
                    }
                }
                //checking column elements.
                if( a[i][j] == a[i+2][j] && a[i][j] == a[i+4][j] && a[i][j] == a[i+6][j])
                {
                    if( a[i][j] == 'X')
                    {
                        pointsP1++;
                    }
                    else
                    {
                        pointsP2++;
                    }
                }
            }
        }
        if( pointsP1 > pointsP2 )
        {
            printf("\n\033[1;33mplayer 1 wins %d - %d ", pointsP1 , pointsP2);
            printf("\n\n\033[0;33m Player 1 , Please enter your name :\n ");
            fflush(stdin);
            fgets(name , max , stdin);                                       
        }
        else if( pointsP1 < pointsP2 )
        {
            printf("\n\033[1;35mplayer 2 wins %d - %d ", pointsP2 , pointsP1);
            printf("\n\n\033[0;35m Player 2 , Please enter your name :\n ");
            fflush(stdin);
            fgets(name , max , stdin);                                       
        }
        else
        {
            printf("\n\033[1;34mplayer 1 & player 2 got equal points %d - %d ", pointsP1 , pointsP2);
        }
        int n;
        printf("\n\033[1;32m[1] Main Menu.\n\033[1;32m[2] Exit.\n");
        printf("Please choose an option : \n");
        scanf("%d",&n);
        if( n == 1 )
        {
            printf("ok");
        }
        else if( n == 2 )
        {
            exit(0);
        }
        while ( n != 1 && n != 2)
        {
            printf("\nPlease choose one of the options above :\n");
            scanf("%d",&n);
        }
    }
}

void showPoints (char a[][2 * m + 1] , int n , int m , int p)
{
    int i, j;
    int pointsP1 = 0;
    int pointsP2 = 0;

        for( i=0 ; i<n*2-1 ; i+=2)
        {
            for( j=1 ; j<m*2 ; j+=2)
            {
                //checking right diagonal elements.
                if( (a[i][j] == a[i+2][j+2]) && (a[i][j] == a[i+4][j+4]) && (a[i][j] == a[i+6][j+6]))
                {
                    if( a[i][j] == 'X')
                    {
                        pointsP1++;
                    }
                    else if (a[i][j] == 'O')
                    {
                        pointsP2++;
                    }
                }
                //checking left diagonal elements.
                if( (a[i][j] == a[i+2][j-2]) && (a[i][j] == a[i+4][j-4]) && (a[i][j] == a[i+6][j-6]))
                {
                    if( a[i][j] == 'X')
                    {
                        pointsP1++;
                    }
                    else if (a[i][j] == 'O')
                    {
                        pointsP2++;
                    }
                }
                //checking row elements.
                if( (a[i][j] == a[i][j+2]) && (a[i][j] == a[i][j+4]) && (a[i][j] == a[i][j+6]))
                {
                    if( a[i][j] == 'X')
                    {
                        pointsP1++;
                    }
                    else if (a[i][j] == 'O')
                    {
                        pointsP2++;
                    }
                }
                //checking column elements.
                if( a[i][j] == a[i+2][j] && a[i][j] == a[i+4][j] && a[i][j] == a[i+6][j])
                {
                    if( a[i][j] == 'X')
                    {
                        pointsP1++;
                    }
                    else if (a[i][j] == 'O')
                    {
                        pointsP2++;
                    }
                }
            }
        }
    if ( p == 1 )
    {
        printf ("\n\n\033[0;35mPlayer 2 got \033[0;35m%d \033[0;35mpoints.\n" , pointsP2);
    }
    else
    {
        printf ("\n\n\033[0;33mPlayer 1 got \033[0;33m%d \033[0;33mpoints.\n" , pointsP1);                   
    }
}


int main ()
{
    int i, j, k , p=1 ;
    cyan(0);
    printf("Welcome to \033[0;33mConnect 4 Game\033[0;36m \n\nplease enter the number of rows :\n");
    white(0);
    scanf("%d", &n);

    while(n<4){
        printf("\033[4;31m This is invalid , Please choose another number of rows :\n");
        scanf("%d", &n);
    }

    cyan(0);
    printf("please enter the number of columns :\n");
    white(0);
    scanf("%d", &m);

    while(m<4){
        printf("\033[4;31m This is invalid , Please choose another number of columns :\n");
        scanf("%d", &m);
    }

    char mat[n * 2][2 * m + 1], col;

    //generating the array
    for(i=0 ; i<n * 2; i++)
    {
        for( j=0 ; j<m*2 + 1 ; j++)
        {
            if(j % 2 == 0 && i % 2 == 0)
                mat[i][j] = '|' ;
            else if(j % 2 == 1 && i % 2 == 0)
                mat[i][j] = ' ';
            else
                mat[i][j] = '-' ;
            printf(" %c", mat[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < m; i ++)
        printf("   %c", i + 65);

    for(i=0 ; i<n * m; i++)
    {
        if(i % 2 == 0)
        {
            p = 1;
            yellow(0);
        }
        else
        {
            p = 2;
            purple(0);
        }
        printf("\nPlayer %d turn\n", p);
        white(0);
        printf("Choose a column : \n");
        point:
        scanf(" %c", &col);
        while(col > 64 + m)
        {
            printf("\033[4;31mColumn doesn\'t exist.\033[0;37m\nPlease choose another column \033[0;3%dmplayer %d \033[0;37m: \n", p + 3, p);
            scanf(" %c", &col);
        }
        if(modifyArray(mat, col, n, p) == 0)
            goto point;
        for(k=0 ; k < n *2 ; k++)
        {
            for( j=0 ; j<m*2 + 1 ; j++)
            {
                printf(" %c", mat[k][j]);
            }
            printf("\n");
        }
        for(k = 0; k < m; k ++){
            printf("   %c", k + 65);
        }
        showPoints (mat , n , m , p);
    }
    winner (mat , n ,  m);

    return 0;
}