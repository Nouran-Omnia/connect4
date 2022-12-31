#ifndef MAINMENU_H_INCLUDED
typedef struct{
    char name [100];
    int points;
    int rank1;
}player;
int menu()
{
    system("");
    printf("\033[1;34m[1] Start a new game.\n");
    printf("\033[1;34m[2] Load a game.\n");
    printf("\033[1;34m[3] Show top players.\n");
    printf("\033[1;34m[4] Quit.\033[0;37m\n");

    int n1;
    scanf ("%d",&n1);
    fflush(stdin);
    while ( n1 != 1 && n1 != 2 && n1 != 3 && n1 != 4 )
        {
            printf("\033[4;31mPlease choose one of the above options :\033[0;37m\n");
            fflush(stdin);
            scanf ("%d",&n1);
        }

    switch( n1 )
    {
    case 1:
    {
        printf("\033[1;33m[1] Play VS human.\n");
        printf("\033[1;33m[2] Play VS computer.\033[0;37m\n");
        int n2;
        scanf("%d",&n2);
        while(1)
        {
            switch(n2)
            {
            case 1:
                return 11;
            case 2:
                return 12;
            default:
            {
                printf("\033[4;31mPlease choose one of the above options :\033[0;37m \n");
                scanf("%d",&n2);
            }

            }
        }
    }

case 2:{
    printf("hi");
    break;
}
case 3:
        {
            int in ;
            printf("show top : ");
            scanf("%d",&in);
            player arr_topScores[in];
            int arrSize = 0;
            FILE* fp;
            fp = fopen("topScores.txt", "r" );
            if(fp == NULL)
            {
                printf("File can't be opened\n");
            }
            else
            {
                while(!feof(fp))
                {
                    player any_player;
                    fgets(any_player.name, 100, fp);
                    fscanf(fp, "%d\n", &any_player.points);
                    arr_topScores[arrSize] = any_player;
                    arrSize++;
                }
            }
            fclose(fp);
            sorting (arr_topScores, arrSize);
            int q;
            for(q=0 ; q<arrSize ; q++)
            {
                printf("Player #%d Name: %sScore: %d\n", q + 1, arr_topScores[q].name, arr_topScores[q].points);
            }
            break;
        }
        case 4 :
        {
            exit(0);
        }
 }
 return 0;
    }



#define MAINMENU_H_INCLUDED



#endif // MAINMENU_H_INCLUDED
