#ifndef HVH_H_INCLUDED
int modifyArrayOfHvH(char a[][2 * m + 1],  char col, int n, int p)
{
    int row = n * 2 - 2, flag = 0, realcol = 2 * col - 1;
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

void gameFlowHvH(char a[][2 * m + 1], int n, int m, int p)
{
    int i, j, k;
    char col , moves1 = 0, moves2 = 0, lastCol[n * m];
    time_t old = time(NULL);
    scores rawStatisticsOfTime;
    rawStatisticsOfTime.totalTimeInSec1 = 0;
    rawStatisticsOfTime.totalTimeInSec2 = 0;
    for(i=0 ; i<n * m; i++)
    {
        beginning:
        //determining whose turn.
        if(i % 2 == 0)
        {
            moves1 ++;
            p  = 1;
            blue(0);
        }
        else
        {
            moves2 ++;
            p = 2;
            purple(1);
        }
        printf("\nPlayer %d turn\n", p);
        white(0);
        printf("Choose a column : \n");
point:

        scanf(" %c", &col);
        fflush(stdin);
        switch(col)
        {
        case '1':
        {
            main();
            break;
        }
        case '2':
        {
            i--;
            if(i < 0)
            {
                i++;
                printf("\033[1;33mno moves to undo :D\033[0;37m\n");
                goto point;
            }
            else
            {
                for(j = 0; j < 2 * m; j += 2)
            {
                if(a[j][lastCol[i] * 2 - 1] == ' ');
                else
                {
                    a[j][lastCol[i] * 2 - 1] = ' ';
                    break;
                }
            }
            printf("%d", lastCol[i]);
            printingTheGame(a, n, m, 4, 5);
            moves1--;
            moves2--;
            fflush(stdin);
            goto beginning;
            }
            break;
        }
        /*case '3':
        {
            i++;
            if(i == 0)
            {
                i--;
                printf("\033[1;33mno moves to redo :D\033[0;37m\n");
                goto point;
            }
            else
            {
                for(j = 0; j < 2 * m; j += 2)
            {
                if(a[j][lastCol[i + 1] * 2 - 1] == ' ');
                else
                {
                    a[j][lastCol[i + 1] * 2 - 1] = ' ';
                    break;
                }
            }
            printf("%d", lastCol[i]);
            printingTheGame(a, n, m, 4, 5);
            moves1++;
            moves2++;
            fflush(stdin);
            goto beginning;
            }
            break;
        }
        /*case '4':
        {
            FILE *fpointer1 = fopen("game1.txt", "wb"), *fpointer2 = fopen("game2.txt", "wb"), *fpointer3 = fopen("game3.txt", "wb");
            for(j = 0; j < 2 * n; j++)
            {
                for(k = 0; k < 2 * m + 1; k++)
                {
                    fwrite(a[][])
                }
            }
            else
           }*/
        case '5':
            exit(0);
        }
        col = col - 64;
        lastCol[i] = col;
        //checking the existence of the column.
        while(col > m)
        {
            printf("\033[4;31mColumn doesn\'t exist.\033[0;37m\nPlease choose another column \033[0;3%dmplayer %d \033[0;37m: \n", p + 3, p);
            scanf(" %c", &col);
            fflush(stdin);
            col = col - 64;
        }
        //checking if column is full.
        if(modifyArrayOfHvH(a, col, n, p) == 0)
            goto point;
        scores rawStatistics = scoresStructure(a, n, m);
        showPoints(rawStatistics.player1Score, rawStatistics.player2Score, 1);
        showmoves(moves1, moves2, 1);
        rawStatisticsOfTime = Timer(old, i, rawStatisticsOfTime);
        old = showTime(1, old, i, rawStatisticsOfTime);
        printingTheGame(a, n, m, 4, 5);
    }

}
#define HVH_H_INCLUDED



#endif // HVH_H_INCLUDED
