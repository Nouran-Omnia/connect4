#include <stdio.h>
#include <stdlib.h>

void modifyArray(char a[][15],  char col, int n, int p)
{
    int row = n * 2 - 2, flag = 0, realcol = 2 * col - 129;
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
        else
        {
            row -= 2;
        }
    }

}
int main ()
{
    system("color 2");
    int n = 6, m = 7, i, j, k, p = 1;
    char mat[n * 2][m * 2 + 1], col;
    //scanf("%d", &col);
    for(i=0 ; i<n * 2; i+=2)
    {
        for( j=0 ; j<m*2 + 1 ; j++)
        {
            if(j % 2 == 0)
                mat[i][j] = '|' ;
            else
                mat[i][j] = ' ';
            mat[i + 1][j] = '-' ;
        }
    }

    for(i=0 ; i<n *2 ; i++)
    {
        for( j=0 ; j<m*2 + 1 ; j++)
        {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < m; i ++)
        printf(" %c", i + 65);

    for(i=0 ; i<n * m; i++)
    {
        if(i % 2 == 0)
            p  = 1;
        else
            p = 2;
        printf("\nPlayer %d turn\n", p);
        printf("Choose a column : \n");
        scanf(" %c", &col);
        modifyArray(mat, col, n, p);
        for(k=0 ; k < n *2 ; k++)
        {
            for( j=0 ; j<m*2 + 1 ; j++)
            {
                printf("%c", mat[k][j]);
            }
            printf("\n");
        }
        for(k = 0; k < m; k ++)
            printf(" %c", k + 65);
    }

    return 0;
}
