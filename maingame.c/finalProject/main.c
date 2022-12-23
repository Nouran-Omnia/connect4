# include <stdio.h>


void modifyArray(char a[][15], int row, int col, int n, int m, int p)
{
    int i, j;
    for(i=0 ; i<n * 2; i+=2)
    {
        for( j=0 ; j<m*2 + 1 ; j++)
        {
            if(row == i && col == j)
            {
                if(p == 1)
                    a[i][j] = 'X';
                else
                    a[i][j] = 'O';
                a[i + 1][j] = '-' ;
            }
        }
    }
}
typedef struct
{
    int colnum;
    int availableRow;
} colHistory;
int main ()
{
    system("color 30");
    int n=6, i, j, k, col, p = 1;
    int m=7, row1 = n*2 - 2, row2 = n*2 - 2, row3 = n*2 - 2, row4 = n*2 - 2, row5 = n*2 - 2, row6 = n*2 - 2, row7 = n*2 - 2;
    char mat[n * 2][m * 2 + 1];
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
            printf(" %c", mat[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < m; i ++)
        printf("   %d", i + 1);

    for(i=0 ; i<n * m; i++)
    {
        if(i % 2 == 0)
            p  = 1;
        else
            p = 2;
        printf("\nPlayer %d turn\n", p);
        printf("Choose a column : \n");
        scanf("%d", &col);
        switch(2 * col - 1)
        {
        case 1:
            modifyArray(mat, row1, 2 * col - 1, n, m, p);
            row1 -= 2;
            break;
        case 3:
            modifyArray(mat, row2, 2 * col - 1, n, m, p);
            row2 -= 2;
            break;
        case 5:
            modifyArray(mat, row3, 2 * col - 1, n, m, p);
            row3 -= 2;
            break;
        case 7:
            modifyArray(mat, row4, 2 * col - 1, n, m, p);
            row4 -= 2;
            break;
        case 9:
            modifyArray(mat, row5, 2 * col - 1, n, m, p);
            row5 -= 2;
            break;
        case 11:
            modifyArray(mat, row6, 2 * col - 1, n, m, p);
            row6 -= 2;
            break;
        case 13:
            modifyArray(mat, row7, 2 * col - 1, n, m, p);
            row7 -= 2;
            break;
        }
        for(k=0 ; k<n *2 ; k++)
        {
            for( j=0 ; j<m*2 + 1 ; j++)
            {
                printf(" %c", mat[k][j]);
            }
            printf("\n");
        }
        for(k = 0; k < m; k ++)
            printf("   %d", k + 1);


    }

    return 0;
}
