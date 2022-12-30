# include <stdio.h>
# include <stdlib.h>
# include "mainGame.c"


void menu(){

    
    printf("\033[1;34m[1] Start a new game.\n");
    printf("\033[1;34m[2] Load a game.\n");
    printf("\033[1;34m[3] Show top players.\n");
    printf("\033[1;34m[4] Quit.\n");

    int n1;
    scanf ("%d",&n1);

    if( n1 == 1 )
    {
        printf("\033[1;33m[1] Play VS human.\n");
        printf("\033[1;33m[2] Play VS computer.\n");

        int n2;
        scanf("%d",&n2);
        // if( n2 == 1 ){

        // }else if( n2 == 2 ){

        //}
        while(n2 != 1 && n2 != 2)
        {
            printf("\033[4;31mPlease choose one of the above options : \n");
            scanf("%d",&n2);
        }
    
    }
    // }else if( n1 == 2 ){

    //}
    else if( n1 == 3 )
    {
        int in ;
        scanf("%d",&in);
        struct player arr_topScores[in];
        int arrSize = 0;
        FILE* fp;
        fp = fopen("/Users/mac/Desktop/topScores.txt" , "r" );
        if(fp == NULL)
        {
            printf("File can't be opened\n");
        }
        else
        {
            while(!feof(fp)){
                struct player any_player;
                fgets(any_player.name , 100 , fp);
                fscanf(fp , "%d\n" , &any_player.points);
                arr_topScores[arrSize] = any_player;
                arrSize++;
            }
        }
        fclose(fp);
        sorting (arr_topScores , arrSize);
        for(int q=0 ; q<arrSize ; q++){
            printf("Player #%d Name: %sScore: %d\n", q + 1, arr_topScores[q].name, arr_topScores[q].points);
        }
    }
    else if( n1 == 4 )
    {
        exit(0);
    }

    while ( n1 != 1 && n1 != 2 && n1 != 3 && n1 != 4 )
    {
        printf("\033[4;31mPlease choose one of the above options : \n");
        scanf ("%d",&n1);
    }
    
}      