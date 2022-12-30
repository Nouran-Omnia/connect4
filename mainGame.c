#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "colors.h"
#define max 10000
int n , m;

struct player{
    char name [100];
    int points;
    int rank;
};

struct player player1 , player2 ;
//functions' prototypes.
int modifyArray (char a[][2 * m + 1],  char col, int n, int p);
int checkFreeSpaces (char a[][2 * m + 1] , int n , int m);
void winner (char a[][2 * m + 1] , int n , int m);
void showPoints (char a[][2 * m + 1] , int n , int m , int p);
void sorting (int a[] , int size);
//void file_array ();

// void file_array ()
// {
//         struct player arr_topScores[in];
//         int arrSize = 0;
//         FILE* fp;
//         fp = fopen("/Users/mac/Desktop/topScores.txt" , "r" );
//         if(fp == NULL)
//         {
//             printf("File can't be opened\n");
//         }
//         else
//         {
//             while(!feof(fp)){
//                 struct player any_player;
//                 fgets(any_player.name , 100 , fp);
//                 fscanf(fp , "%d\n" , &any_player.points);
//                 arr_topScores[arrSize] = any_player;
//                 arrSize++;
//             }
//         }
//         fclose(fp);
// }


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
    
    int i , j , k , z;
    player1.points=0;
    player2.points=0;


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
                        player1.points++;
                    }
                    else
                    {
                        player2.points++;
                    }
                }
                //checking left diagonal elements.
                if( (a[i][j] == a[i+2][j-2]) && (a[i][j] == a[i+4][j-4]) && (a[i][j] == a[i+6][j-6]))
                {
                    if( a[i][j] == 'X')
                    {
                        player1.points++;
                    }
                    else
                    {
                        player2.points++;
                    }
                }
                //checking row elements.
                if( (a[i][j] == a[i][j+2]) && (a[i][j] == a[i][j+4]) && (a[i][j] == a[i][j+6]))
                {
                    if( a[i][j] == 'X')
                    {
                        player1.points++;
                    }
                    else
                    {
                        player2.points++;
                    }
                }
                //checking column elements.
                if( a[i][j] == a[i+2][j] && a[i][j] == a[i+4][j] && a[i][j] == a[i+6][j])
                {
                    if( a[i][j] == 'X')
                    {
                        player1.points++;
                    }
                    else
                    {
                        player2.points++;
                    }
                }
            }
        }
        if( player1.points > player2.points )
        {
            printf("\n\033[1;33mplayer 1 wins %d - %d ", player1.points , player2.points);
            printf("\n\n\033[0;33m Player 1 , Please enter your name :\n ");
            fflush(stdin);
            FILE* fp ;
            fp = fopen("/Users/mac/Desktop/topScores.txt" , "a" );
            fgets(player1.name , max , stdin);
            for(int k=0 ; k<strlen(player1.name) ; k++)
            {
                player1.name[k] = tolower(player1.name[k]);
            }
            fprintf(fp , "%s\n" , player1.name);
            fprintf(fp , "%d\n" , player1.points);
            fclose (fp);
        }
        else if( player1.points < player2.points )
        {
            printf("\n\033[1;35mplayer 2 wins %d - %d ", player2.points , player1.points);
            printf("\n\n\033[0;35m Player 2 , Please enter your name :\n ");
            fflush(stdin);
            FILE* fp ;
            fp = fopen("/Users/mac/Desktop/topScores.txt" , "a" );
            fgets(player2.name , max , stdin);
            for(int k=0 ; k<strlen(player1.name) ; k++)
            {
                player1.name[k] = tolower(player1.name[k]);
            }
            fprintf(fp , "%s\n" , player2.name);
            fprintf(fp , "%d\n" , player2.points);
            fclose (fp);  
        }
        else
        {
            printf("\n\033[1;34mplayer 1 & player 2 got equal points %d - %d ", player1.points , player2.points);
        }
        // int n;
        // printf("\n\033[1;32m[1] Main Menu.\n\033[1;32m[2] Exit.\n");
        // printf("Please choose an option : \n");
        // scanf("%d",&n);
        // if( n == 1 )
        // {
        //     printf("ok");
        // }
        // else if( n == 2 )
        // {
        //     exit(0);
        // }
        // while ( n != 1 && n != 2)
        // {
        //     printf("\nPlease choose one of the options above :\n");
        //     scanf("%d",&n);
        // }
    }
}


void showPoints (char a[][2 * m + 1] , int n , int m , int p)
{
    int i, j;
    player1.points=0;
    player2.points=0;

        for( i=0 ; i<n*2-1 ; i+=2)
        {
            for( j=1 ; j<m*2 ; j+=2)
            {
                //checking right diagonal elements.
                if( (a[i][j] == a[i+2][j+2]) && (a[i][j] == a[i+4][j+4]) && (a[i][j] == a[i+6][j+6]))
                {
                    if( a[i][j] == 'X')
                    {
                        player1.points++;
                    }
                    else if (a[i][j] == 'O')
                    {
                        player2.points++;
                    }
                }
                //checking left diagonal elements.
                if( (a[i][j] == a[i+2][j-2]) && (a[i][j] == a[i+4][j-4]) && (a[i][j] == a[i+6][j-6]))
                {
                    if( a[i][j] == 'X')
                    {
                        player1.points++;
                    }
                    else if (a[i][j] == 'O')
                    {
                        player2.points++;
                    }
                }
                //checking row elements.
                if( (a[i][j] == a[i][j+2]) && (a[i][j] == a[i][j+4]) && (a[i][j] == a[i][j+6]))
                {
                    if( a[i][j] == 'X')
                    {
                        player1.points++;
                    }
                    else if (a[i][j] == 'O')
                    {
                        player2.points++;
                    }
                }
                //checking column elements.
                if( a[i][j] == a[i+2][j] && a[i][j] == a[i+4][j] && a[i][j] == a[i+6][j])
                {
                    if( a[i][j] == 'X')
                    {
                        player1.points++;
                    }
                    else if (a[i][j] == 'O')
                    {
                        player2.points++;
                    }
                }
            }
        }
    if ( p == 1 )
    {
        printf ("\n\n\033[0;35mPlayer 2 got \033[0;35m%d \033[0;35mpoints.\n" , player2.points);
    }
    else
    {
        printf ("\n\n\033[0;33mPlayer 1 got \033[0;33m%d \033[0;33mpoints.\n" , player1.points);                   
    }
}


//insertion sort.
void sorting (int a[] , int size)
{
    int x , y ;
    for( x=1 ; x<size ; x++ )
    {
        int next = a[x];
        for( y=x-1 ; y>=0 && a[y] > next ; y-- ) 
        {
            a[y+1] = a[y];
        }
        a[y+1] = next;
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