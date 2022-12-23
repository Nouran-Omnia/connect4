# include <stdio.h>

int main (){

    printf("* To ");
    printf("\033[0;35m");
    printf("START A NEW GAME ");
    printf("\033[0;37m");
    printf("press 1\n");

    printf("* To ");
    printf("\033[0;35m");
    printf("LOAD A GAME ");
    printf("\033[0;37m");
    printf("press 2\n");

    printf("* To ");
    printf("\033[0;35m");
    printf("SHOW TOP PLAYERS ");
    printf("\033[0;37m");
    printf("press 3\n");

    printf("* To ");
    printf("\033[0;35m");
    printf("QUIT ");
    printf("\033[0;37m");
    printf("the game press 4\n");

    int n1;
    scanf ("%d",&n1);

    if( n1 == 1 ){
        printf("* To ");
        printf("\033[0;35m");
        printf("PLAY VS HUMAN ");
        printf("\033[0;37m");
        printf("press 1\n");

        printf("* To ");
        printf("\033[0;35m");
        printf("PLAY VS COMPUTER ");
        printf("\033[0;37m");
        printf("press 2\n");

        int n2;
        scanf("%d",&n2);
        // if( n2 == 1 ){

        // }else if( n2 == 2 ){

        // }else{
            //printf("ERROR");
        // }
    }

    // }else if( n1 == 2 ){

    // }else if( n1 == 3 ){

    // }else if( n1 == 4 ){

    //}
    else{
        printf("ERROR");
    }
    
    return 0 ;
    }      