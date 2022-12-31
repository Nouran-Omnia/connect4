#ifndef AI_MINIMAX_H_INCLUDED
int n, m;
int modifyArrayOfHvC(char a[][2 * m + 1], char col, int n, int TurnNum)
{
    int row = n * 2 - 2, flag = 0, realcol = 2 * col - 1;
    while(flag == 0)
    {
        if(a[row][realcol] == ' ' && TurnNum % 2 == 0)
        {
                a[row][realcol] = 'X';
            flag = 1;
        }
        else if(a[row][col] == ' ' && TurnNum % 2 == 1)
        {
                a[row][col] = 'O';
            flag = 1;
        }
        else if(row == 0 && TurnNum % 2 == 0)
        {
            printf("\033[4;31mColumn is full.\033[0;37m\nPlease choose another column \033[0;33mHuman\033[0;37m :\n");
            return flag;
        }
        else
        {
            row -= 2;
        }
    }
    return flag;
}
void gameFlowHvC(char a[][2 * m + 1], int n, int m)
{
    int i, j, k;
    char col, moves1 = 0, moves2 = 0, lastCol[n * m];
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
            moves2++;
            yellow(0);
            printf("\nHuman turn\n\033[0;37mChoose a column : \n");
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
            printingTheGame(a, n, m, 3, 1);
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
                printf("\033[4;31mColumn doesn\'t exist.\033[0;37m\nPlease choose another column \033[0;33mHuman \033[0;37m: \n");
                scanf(" %c", &col);
                fflush(stdin);
                col = col - 64;
            }
            //checking if column is full.
            if(modifyArrayOfHvC(a, col, n, i) == 0)
                goto point;
            scores rawStatistics  = scoresStructure(a, n, m);
            showPoints(rawStatistics.player2Score, rawStatistics.player1Score, 2);
            showmoves(moves1, moves2, 2);
            rawStatisticsOfTime = Timer(old, i, rawStatisticsOfTime);
            old = showTime(2, old, i, rawStatisticsOfTime);
            printingTheGame(a, n, m, 3, 1);

        }
        else
        {
            moves1++;
            red(1);
            printf("\nComputer turn\n\033[0;37m");
            modifyArrayOfHvC(a, minimax(a, n, m, 2, 2), n, i);
            scores rawStatistics  = scoresStructure(a, n, m);
            showPoints(rawStatistics.player2Score, rawStatistics.player1Score, 2);
            showmoves(moves1, moves2, 2);
            rawStatisticsOfTime = Timer(old, i, rawStatisticsOfTime);
            old = showTime(2, old, i, rawStatisticsOfTime);
            printingTheGame(a, n, m, 3, 1);

        }
    }

}
void cloneArray(char oldArray[][2 * m + 1], char newArray[][2 * m + 1], int n, int m)
{
    int i, j;
    for(i = 0; i < n * 2; i++){
        for(j = 0; j < m * 2 + 1; j++){
            newArray[i][j] = oldArray[i][j];
        }
    }
}

void winnerCvH(int pointsP1, int pointsP2)
{
    if( pointsP1 > pointsP2 )
        {
            char name[1000];
            printf("\n\n\033[0;33mHuman wins %d - %d ", pointsP1, pointsP2);
            printf("\nHuman \033[0;37m, Please enter your name :\n ");
            fflush(stdin);
            fgets(name , 1000 , stdin);
        }
        else if( pointsP1 < pointsP2 )
        {
            printf("\n\n\033[1;31mComputer\033[0;37m wins %d - %d \033[0;32mHard luck nope X3\033[0;37m\n", pointsP2, pointsP1);
        }
        else
        {
            printf("\n\n\033[0;33mHuman\033[0;37m & \033[1;31mComputer\033[0;37m got equal points %d - %d \n", pointsP1, pointsP2);
        }
}

int checkFreecolumns(char a[][2 * m + 1], int n, int m)
{
    int i, j;
    int freeCols = 0;
    for(j=1 ; j<m*2+1 ; j+=2)
    {

        for(i=0 ; i<n*2 ; i+=2)
        {
            if(a[i][j] == ' ')
            {
                freeCols++;
                break;
            }
        }
    }
    return freeCols;
}
int modifyArray2(char a[][2 * m + 1],  int col, int n, int p)
{
    int row = n * 2 - 2, flag = 0;
    while(flag == 0)
    {
        if(a[row][col] == ' ')
        {
            if(p == 1)
                a[row][col] = 'X';
            else
                a[row][col] = 'O';
            flag = 1;
        }
        else if(row == 0)
        {
            col += 2;
            row = n * 2 - 2;
        }
        else
        {
            row -= 2;
        }
    }
    return col+= 2;
}


int minimax(char a[][2 * m + 1], int n, int m, int depth, int player)
{
    if(depth == 0 || checkFreecolumns(a, n, m) == 0){
        scores score = scoresStructure(a, n, m);
        if(score.player1Score >= score.player2Score)
            return -1 * score.player1Score;
        else
            return  score.player2Score;
    }
    else if(player == 2)
    {
        int i, eval1, maxi = -1000000000, maxColIndex = 1;
        int posit = 1;
        char newArray[n * 2][2 * m + 1];
        for(i = 0; i < checkFreecolumns(a, n, m); i++)
        {
            cloneArray(a, newArray, n, m);
            posit = modifyArray2(newArray, posit, n, 2);
            eval1 = minimax(newArray, n, m, depth - 1, 1);
            if(eval1 >= maxi)
            {
                maxi = eval1;
                maxColIndex = posit - 2;
            }
        }
        return maxColIndex;
    }
    else
    {
        int i, eval2, posit = 1;
        char newArray2[2 * n][2 * m + 1];
        int mini = 1000000000;
        for(i = 0; i < checkFreecolumns(a, n, m); i++)
        {
            cloneArray(a, newArray2, n, m);
            posit = modifyArray2(newArray2, posit, n, 1);
            eval2 = minimax(newArray2, n, m, depth - 1, 2);
            if(eval2 < mini)
                mini = eval2;
        }
            return mini;
    }

}

#define AI_MINIMAX_H_INCLUDED



#endif // AI_MINIMAX_H_INCLUDED
