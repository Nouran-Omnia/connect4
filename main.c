#include <stdio.h>
#include <stdlib.h>
# include"colors.h"
int n, m;
int modifyArray(char a[][2 * m + 1],  char col, int n, int p);
int checkFreeSpaces (char a[][2 * m + 1] , int n , int m);
void winner (char a[][2 * m + 1] , int n , int m);


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
    if(checkFreeSpaces (a , n , m) == 0)
    {
        for( i=0 ; i<n*2-1 ; i+=2)
        {
            for( j=1 ; j<m*2 ; j+=2)
            {
                //checking right diagonal elements.
                if( (a[i][j] == a[i+2][j+2]) && (a[i][j] == a[i+4][j+4]) && (a[i][j] == a[i+6][j+6]))
                {
                    if( a[i][j] == 'X'){
                        pointsP1++;
                    }else{
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
                    if( a[i][j] == 'X'){
                        pointsP1++;
                    }else{
                        pointsP2++;
                    }
                }
                //checking column elements.
                if( a[i][j] == a[i+2][j] && a[i][j] == a[i+4][j] && a[i][j] == a[i+6][j])
                {
                    if( a[i][j] == 'X'){
                        pointsP1++;
                    }else{
                        pointsP2++;
                    }
                }
            }
        }
        if( pointsP1 > pointsP2 ){
            printf("\n\nplayer 1 wins %d - %d ", pointsP1 , pointsP2);
        }else if( pointsP1 < pointsP2 ){
            printf("\n\nplayer 2 wins %d - %d ", pointsP2 , pointsP1);
        }else{
            printf("\n\nplayer 1 & player 2 got equal points %d - %d ", pointsP1 , pointsP2);
        }
    }
}

int main ()
{
    int i, j, k, p = 1;
    cyan(0);
    printf("Welcome to \033[0;32mConnect 4 Game\033[0;36m please enter the number of rows :\n");
    white(0);
    scanf("%d", &n);
    cyan(0);
    printf("please enter the number of columns :\n");
    white(0);
    scanf("%d", &m);
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
            p  = 1;
            blue(0);
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
        for(k = 0; k < m; k ++)
            printf("   %c", k + 65);
    }
    winner (mat , n ,  m);

    return 0;
}
